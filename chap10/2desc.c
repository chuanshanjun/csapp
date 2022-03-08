#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd1, fd2;
    char c;

    fd1 = open("foobar.txt", O_RDONLY, 0);
    if (fd1 < 0)
        fprintf(stderr, "%s %s", "open foobar.txt err", strerror(errno));
    
    fd2 = open("foobar.txt", O_RDONLY, 0);
    if (fd2 < 0)
        fprintf(stderr, "%s %s", "open foobar.txt err", strerror(errno));
    
    ssize_t rc1 = read(fd1, &c, 1);
    if (rc1 < 0)
        fprintf(stderr, "%s %s", "read foobar.txt err", strerror(errno));

    ssize_t rc2 = read(fd2, &c, 1);
    if (rc2 < 0)
        fprintf(stderr, "%s %s", "read foobar.txt err", strerror(errno));
    
    printf("c = %c\n", c);

    printf("fd1 = %d\n", fd1);
    printf("fd2 = %d\n", fd2);
    exit(0);
}