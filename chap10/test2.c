#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define RIO_BUFSIZE 8192
typedef struct {
    int rio_fd;                 /* Description for this internal buf */
    int rio_cnt;                /* Unread bytes in internal buf */
    char *rio_bufptr;           /* Next unread byte in internal buf */    
    char rio_buf[RIO_BUFSIZE];  /* Internal buffer */
} rio_t;

void rio_readinitb(rio_t *rp, int fd) {
    rp->rio_fd = fd;
    rp->rio_cnt = 0;
    rp->rio_bufptr = rp->rio_buf;
}

/*
 * rio_read函数是Linux read函数的带缓冲的版本。当调用rio_read要求读n个字节时，
 * 读缓冲区内有 rp->rio_cnt个未读字节。如果缓冲区为空，那么会通过调用read再填满它
 * 这个read调用收到一个不足值并不是错误，只不过读缓冲区是填充了一部分。
 * 一旦缓冲区非空，rio_read就从读缓冲区复制n和rp->rio_cnt中较小值个字节到用户
 * 缓冲区，并返回复制的字节数。
 */
static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n) {
    int cnt;

    while (rp->rio_cnt <= 0) { /* Refill if buf is empty */
        rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
        if (rp->rio_cnt < 0) {
            if (errno != EINTR) /* Interrupted by sig handler return */
            return -1;
        } 
        else if (rp->rio_cnt == 0) /* EOF */
            return 0;
        else 
            rp->rio_bufptr = rp->rio_buf; /* Reset buffer ptr */
    }

    /* Copy min(n, rp->rio_cnt) bytes from internal buf to user buf */
    cnt = n;
    if (rp->rio_cnt < n)
        cnt = rp->rio_cnt;
    memcpy(usrbuf, rp->rio_bufptr, cnt); 
    rp->rio_bufptr += cnt;
    rp->rio_cnt -=cnt;
    return cnt;
}

/*
 * rio_readlineb函数从文件rp读出下一个文本行(包括结尾的换行符)，将它复制到内存位置usrbuf
 * 并且用NULL(零)字符来结束这个文本行。rio_readlineb函数最多读maxlen-1个字节，
 * 余下的一个字符留给结尾的NULL字符。超过maxlen-1字节的文本行被截断，并用一个NULL字符结束。
*/
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen) {
    int n, rc;
    char c, *bufp = usrbuf;

    for (n = 1; n < maxlen; n++) {
        if ((rc = rio_read(rp, &c, 1)) == 1) {
            *bufp++ = c;
            if (c == '\n') {
                n++;
                break;
            }
        } else if (rc == 0) {
            if (n == 1)
                return 0; /* EOF, no data read */
            else
                break;    /* EOF, some data was read */
        } else
            return -1;    /* Error */
    }
    *bufp = 0;
    return n-1;
}


/*
 * rio_readnb函数从文件rp最多读n个字节到内存位置usrbuf。对同一描述符，
 * 对rio_readlineb和rio_readnb的调用可以任意交叉进行。
 * 然后，对这些带缓冲的函数的调用却不应和无缓冲的rio_readn函数交叉使用
*/
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n) {
    size_t nleft = n;
    ssize_t nread;
    char *bufp = usrbuf;

    while (nleft > 0) {
        if ((nread = rio_read(rp, bufp, nleft)) < 0)
            return -1;  /* errno set by read() */
        else if (nread == 0)
            break; /* EOF */
        nleft -= nread;
        bufp += nread;
    }
    return (n - nleft); /* Return >= 0 */
}

int main() {
    rio_t rt;

    int fdx = open("baz.txt", O_RDONLY, 0);
    if (fdx < 0) {
        fprintf(stderr, "%s: %s\n", "open file err", strerror(errno));
        exit(0);
    }

    rio_readinitb(&rt, fdx);

    printf("sizeof(rp->rio_buf) = %lu", sizeof((&rt)->rio_buf));
}