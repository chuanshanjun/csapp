#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argv[1] == NULL) {
        printf("Error! need file name, like > ./xxx.xxx\n");
    }

    int fd = open(argv[1], O_RDONLY);

    struct stat sb;

    fstat(fd, &sb);

    printf("file size = %ld\n", sb.st_size);

    char *buf;

    buf = (char *)mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);

    printf("buf is %s\n", buf);

    write(STDOUT_FILENO, buf, sb.st_size);
}