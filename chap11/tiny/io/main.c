#include "young.h"

int parse_uri(char *uri, char *filename, char *cgiargs) {
    char *ptr;

    if (!strstr(uri, "cgi-bin")) { /* Static content */
        strcpy(cgiargs, "");
        strcpy(filename, ".");
        strcat(filename, uri);
        if (uri[strlen(uri) - 1] == '/')
            strcat(filename, "home.html");
        return 1;
    }
    else {  /* Dynamic content */
        ptr = index(uri, '?');
        if (ptr) {
            strcpy(cgiargs, ptr+1);
            *ptr = '\0';
        }
        else 
            strcpy(cgiargs, "");
        strcpy(filename, ".");
        strcat(filename, uri);
        return 0;
    }
}

extern char **environ;

int main() {
    // char uri[] = "/cgi-bin/hello?hoho";
    // char filename[1024], cgiargs[1024];

    // parse_uri(uri, filename, cgiargs);

    // printf("uri = %s\n", uri);
    // printf("filename = %s\n", filename);
    // printf("cgiargs = %s\n", cgiargs);

    if (Fork() == 0) { /* Child process */
        int fd;
        fd = Open("text.txt", O_WRONLY|O_APPEND, 0);
        printf("fd = %d\n", fd);

        setenv("name", "cool", 1);
        char **s = environ;
        for (; *s; s++) {
            printf("%s\n", *s);
        }

        Dup2(fd, STDOUT_FILENO);

        printf("child process end\n");

        char filename[] = "./hellofile/hello";
        printf("filename = %s\n", filename);

        char *emptylist[] = {NULL};
        Execve(filename, emptylist, environ);

        printf("end of Execve\n");

        Close(3);
    }
    
    Wait(NULL); /* Parent waits for and reaps child */
    printf("parent process end\n");

    
}