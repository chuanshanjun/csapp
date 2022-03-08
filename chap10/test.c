#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

ssize_t rio_readn(int fd, void *usrbuf, size_t n) {
    size_t nleft = n;
    ssize_t nread;
    char *bufp = usrbuf;

    while (nleft > 0) {
        if ((nread = read(fd, bufp, nleft)) < 0) {
            if (errno == EINTR)
                nread = 0; 
            else
                return -1;
        }
        else if (nread == 0)
            break;
        nleft -= nread;
        bufp += nread;    
    }
    return (n - nleft);
}

void edit(char* buf) {
    printf("%c\n", *buf);
    printf("%p\n", buf);
    *buf++ = 'd';
    printf("%c\n", *buf);
    printf("%p\n", buf);

    printf("%p\n", buf--);
    printf("%s\n", buf);
}

int main() {
    char str[4] = "abc";

    edit(str);
}