#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    struct stat stats;
    char *type, *readok;

    if (stat(argv[1], &stats) < 0)
        fprintf(stderr, "%s, %s", "stat error", strerror(errno));

    if (S_ISREG(stats.st_mode)) /* Determine file type */
        type = "regular";
    else if (S_ISDIR(stats.st_mode))
        type = "directory";
    else 
        type = "other";
    if ((stats.st_mode & S_IRUSR)) /* Check read access */
        readok = "yes";
    else 
        readok = "no";
    
    printf("type: %s, read: %s\n", type, readok);
    exit(0);
}