#include "young.h"

int main() {
    pid_t pid;

    /* Child sleeps until SIGKILL signal received, then dies */
    if ((pid = Fork()) == 0) {
        printf("child pid before pause\n");
        Pause();/* Wait for a signal to arrive */
        printf("contorl should never reach here\n");
        exit(0);
    }

    /* Parent sends a SIGKILL signal to a child */
    printf("parent pid start sleep\n");
    Sleep(1);
    printf("parent pid after sleep go to kill child pid\n");
    Kill(pid, SIGKILL);
    exit(0);
}