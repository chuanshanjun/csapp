/*
    读取用户指令 -> 解析命令 -> 运行程序

    1 读取用户指令
        1.1 打印提示符
        1.2 等待用户在stdin上输入
        1.3 feof判断

    2 解析命令
        2.1 parseline 解析以空格为分隔符的命令行参数
        2.2 & parseline 返回1 表示后台执行, 后台执行父进程不会等待子进程结束
        2.3 检查是否为内置命令 是则直接执行,并返回1 
        2.4 立刻执行shell内置命令
        2.5 在新子进程上下文运行此
*/

#include "young.h"

#define MAXARG 16

int parseline(char *buf, char **argv) {
    int argc = 0;
    char *delim;
    int bg;

    // 用空格替换 \n
    buf[strlen(buf) - 1] = ' ';

    // 如果命令前有空格则指针往后移
    while (*buf && (*buf == ' ')) {
        buf++;
    }

    // 以空格分割
    while (delim = strchr(buf, ' ')) {
        printf("delim = %s\n", delim);
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        printf("buf = %s\n", buf);
        while (*buf && (*buf == ' ')) {
            buf++;
        }
    }

    argv[argc] = NULL;

    for (int i = 0; argv[i]; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // 判断是否后台执行
    if ((bg = (*argv[argc - 1] == '&')) != 0) {
        argv[--argc] = NULL;
    }

    return bg;
}

int built_command(char **argv) {
    char *fcommand = argv[0];

    if (!strcmp(fcommand, "quit")) {
        exit(0);
    }

    return 0;
}


void eval(char* cmdline) {
    char *argv[MAXARG];
    char buf[MAXLINE];
    pid_t pid;

    strcpy(buf, cmdline);

    int bg = parseline(buf, argv);

    printf("bg is %d\n", bg);

    if (!built_command(argv)) {
        // 1 fork 新进程执行命令
        if ((pid = fork()) == 0) {
            // 1.1 子进程执行execv
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not found.\n", argv[0]);
            }
            exit(0);
        }

        // 2 是否前台执行
        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0) < 0) {
                unix_error("waitfg: waitpid error");
            } 
        } else {
            printf("%d %s\n", pid, cmdline);
        }
    }

    return;
}

int main() {
    char cmdline[MAXLINE];
    
    while (1) {
        printf("> ");
        fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin)) {
            printf("read feof from stdin\n");
            exit(0);
        }

        eval(cmdline);
    }
}