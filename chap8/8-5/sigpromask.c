#include "young.h"

void pr_mask(const char *str) {
    sigset_t sigset;
    int errno_save;

    sigaddset(&sigset, SIGALRM);

    sigprocmask(SIG_BLOCK, &sigset, 0);

    errno_save = errno; /* We can be called by signal handlers */
        
    if (sigprocmask(0, NULL, &sigset) < 0) {
        unix_error("sigprocmask error");
    } else {
        printf("%s", str);
        if (sigismember(&sigset, SIGINT))
            printf(" SIGINT");
        if (sigismember(&sigset, SIGQUIT))
            printf(" SIGQUIT");
        if (sigismember(&sigset, SIGALRM))
            printf(" sigalrm");

        printf("\n");
    }
    
    errno = errno_save;
}

int main() {
    char str[] = "tets sig";

    

    pr_mask(str);
}