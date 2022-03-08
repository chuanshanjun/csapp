#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t Read(int fd, void *buf, size_t count);
ssize_t Write(int fd, void *buf, size_t count);

int main() {
    char c;

    while (Read(STDIN_FILENO, &c, 1) != 0 ) 
        Write(STDOUT_FILENO, &c, 1);
    exit(0);
}

ssize_t Read(int fd, void *buf, size_t count) {
    ssize_t rc;
    
    if ((rc = read(fd, buf, count)) < 0) {
        fprintf(stderr, "%s\n", "read file error");
        exit(0);
    }
    
    return rc;
}

ssize_t Write(int fd, void *buf, size_t count) {
    ssize_t rc;

    if ((rc = write(fd, buf, count)) < 0) {
        fprintf(stderr, "%s\n", "write file error");
        exit(0);
    }

    return rc;
}