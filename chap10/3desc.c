#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main() {
    int fd;
    char c;

    fd = open("foobar.txt", O_RDONLY, 0);
    if (fd < 0)
        fprintf(stderr, "%s %s\n", "open file error", strerror(errno));

    pid_t pid = fork();
    if (pid == 0) {
        /* 子进程 */
        ssize_t rc = read(fd, &c, 1);
        if (rc < 0)
            fprintf(stderr, "%s %s\n", "read file error", strerror(errno));
        exit(0);
    }

    printf("child pid = %d\n", pid);

    if ((pid = wait(NULL)) < 0)
        fprintf(stderr, "%s %s\n", "wait pid error", strerror(errno));
    
    printf("child pid = %d exit\n", pid);

    ssize_t rc2 = read(fd, &c, 1);
    if (rc2 < 0)
        fprintf(stderr, "%s %s\n", "read file err", strerror(errno));
    
    printf("c = %c\n", c);
    exit(0);
}