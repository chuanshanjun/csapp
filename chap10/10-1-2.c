#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd1, fd2;

    fd1 = open("foo.txt", O_RDONLY, 0);
    if (fd1 < 0) {
        fprintf(stderr, "%s\n", "open file err");
        exit(0);
    }

    printf("fd1 = %d\n", fd1);

    fd2 = open("baz.txt", O_WRONLY|O_APPEND, 0);
    if (fd2 < 0) {
        fprintf(stderr, "%s\n", "open file err");
        exit(0);
    }

    printf("fd2 = %d\n", fd2);

    int retval = close(fd1);
    if (retval == -1) {
        fprintf(stderr, "%s\n", "close file err");
        exit(0);
    }

    int retval2 = close(fd2);
    if (retval2 == -1) {
        fprintf(stderr, "%s\n", "close file err");
        exit(0);
    }
}