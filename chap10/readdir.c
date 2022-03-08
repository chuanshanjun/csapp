#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    DIR *streamp;
    struct dirent *dep;

    streamp = opendir(argv[1]);
    if (!streamp)
        fprintf(stderr, "%s %s\n", "open dir err", strerror(errno));
    
    errno = 0;
    while ((dep = readdir(streamp)) != NULL) {
        printf("Found file: %s\n", dep->d_name);
    }
    if (errno != 0)
        fprintf(stderr, "%s %s\n", "read dir err", strerror(errno));

    if (closedir(streamp) < 0)
        fprintf(stderr, "%s %s\n", "close dir err", strerror(errno));
    
    exit(0);
}