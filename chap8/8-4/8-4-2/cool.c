#include "young.h"

int main() {
    pid_t pid;
    int x = 1;

    pid = Fork();  
    if (pid == 0) {
        printf("child : x=%d, pid=%d\n", ++x, pid);
        exit(0);
    }  

    printf("parent: x = %d\n pid=%d\n", --x, pid);
    exit(0);
}