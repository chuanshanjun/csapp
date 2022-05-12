#include "young.h"

void sigint_hanlder(int sig) {
    printf("Caught SIGINT\n");
    exit(0);
}

int main() {
    
    if ((signal(SIGINT, sigint_hanlder)) == SIG_ERR)
        unix_error("Caught SIGINT\n");

    pause();
    
    exit(0); 
}