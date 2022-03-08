#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

// 将一个任意大小的磁盘文件复制到stdout
// 输入的文件名字必须做为一个命令行参数来传递
int main(int argc, char** argv) {
    // 1 读取参数
    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
    }

    char* fileName = argv[1];
    if (fileName == NULL) {
        fprintf(stderr, "please pass file name!\n");
        exit(1);
    }

    printf("name of file = %s\n", fileName);

    int fd = open(fileName, O_RDONLY);

    struct stat sb;
    
    fstat(fd, &sb);

    void* start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (start == MAP_FAILED) {
        fprintf(stderr, "mmap failed! errno = %s\n", strerror(errno));
        exit(1);
    }

    // printf("%s\n", (char*)start);
    // write(1, start, sb.st_size);
    write(STDOUT_FILENO, start, sb.st_size);

    munmap(start, sb.st_size); /* 解除映射 */

    int ret = close(fd);
    if (ret == 0)
        printf("close success");

    if (ret == 1) {
        fprintf(stderr, "close fd failed filename = %s, errno = %s", fileName, strerror(errno));
        exit(1);
    }
        
    // start = null, size_t 获取文件大小, prot = RROT_READ , fd = 文件描述符, off_t = 0 
    return 0;   
}

