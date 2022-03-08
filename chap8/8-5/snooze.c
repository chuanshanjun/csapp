#include "young.h"

unsigned int snooze(unsigned int secs);
void sigint_handler(int sig);

unsigned int snooze(unsigned int secs) {
    unsigned int rc;
    rc = sleep(secs);
    printf("slept for %d of %d\n", secs - rc, secs);

    return rc;
}

void sigint_handler(int sig) {
    printf("Caught SIGINT!\n");
    return;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <secs>\n", argv[0]);
        exit(0);
    }
    
    // 1 获取argv参数
    char* secs = argv[1];
    int secss = atoi(secs);

    // 2 注册信号handler,中断后不退出
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        unix_error("signal error");
    }

    // 3 休眠
    (void)snooze(secss);

    return(0);
}
