#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    int fd1, fd2;
    char c;

    fd1 = open("foobar.txt", O_RDONLY, 0);
    fd2 = open("foobar.txt", O_RDONLY, 0);

    ssize_t rc = read(fd2, &c, 1);
    if (rc < 0) 
        fprintf(stderr, "%s %s\n", "read file err", strerror(errno));
    
    int rc2 = dup2(fd2, fd1);
    if (rc2 < 0)
        fprintf(stderr, "%s %s\n", "read err", strerror(errno));
    
    ssize_t rc3 = read(fd1, &c, 1);
    if (rc3 < 0)
        fprintf(stderr, "%s %s\n", "read err", strerror(errno));
    
    printf("c = %c\n", c);
    exit(0);
}