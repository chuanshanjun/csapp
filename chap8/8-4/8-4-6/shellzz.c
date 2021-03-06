#include "young.h"
#define MAXARGS 128

/* Funciont prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

int main() {
    char cmdline[MAXLINE]; /* Command line */

    while (1) {
        /* Read */
        printf("> ");
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);

        /* Evaluate */
        eval(cmdline);
    }
}

/* eval - Evaluate a command line */
void eval(char *cmdline) {
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Hols modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;

    strcpy(buf, cmdline); // 传进来的字符转先复制一份，因为你不知道他什么没有
    bg = parseline(buf, argv);
    if (argv[0] == NULL) {
        return;          /* Ignore empty lines */
    }

    if (!builtin_command(argv)) {
        if ((pid = Fork()) == 0) { /* Child runs user job */
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not found. \n", argv[0]);
                exit(0);
            }
        }

        /* Parents waits for foreground job to terminate */
        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0) < 0) {
                unix_error("waitfg: waitpid error");
            } else {
                printf("%d %s", pid, cmdline);
            }
        }
        return;
    }
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv) {
    if (!strcmp(argv[0], "quit")) { /* quit command */
        exit(0);
    }

    if (!strcmp(argv[0], "&")) { /* Ignore singleton */
        return 1;
    }
    return 0;
}

/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv) {
    char *delim; /* Points to first space deliiter */
    int argc;    /* Number of args */
    int bg;      /* Background job? */

    buf[strlen(buf) - 1] = ' '; /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
        buf++;

    /* Build the argv list */
    argc = 0;
    while (delim = strchr(buf, ' ')) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' ')) /* Ignore spaces */
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0) /* Ignore blank line */
        return 1;

    /* Shoud the job run in the backgroud? */
    if ((bg = (*argv[argc-1] == '&')) != 0) {
        argv[--argc] = NULL;
    }

    return bg;
}