#include "young.h"

void unix_error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

void app_error(char *msg) /* Application error */
{
    fprintf(stderr, "%s\n", msg);
    exit(0);
}

pid_t Fork() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        unix_error("Fork error");
    }
    return pid;
}

unsigned int Sleep(unsigned int secs) {
    unsigned int rc;

    if ((rc = sleep(secs)) < 0) {
        unix_error("Sleep error");
    }

    return rc;
}

void Pause() {
    /* 调用函数时前面加(void)，是为了显式指明，程序不处理函数返回值。
    这是一种较好的编程规范，增加可读性之类的好处。 */
    (void)pause();
    return;
}

char *Fgets(char *ptr, int n, FILE *stream) 
{
    char *rptr;

    if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream))
	app_error("Fgets error");

    return rptr;
}
