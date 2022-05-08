#include "young.h"

int main(int argc, char **argv, char **envp) {
    printf("Command-line arguments:\n");
    for (int i = 0; argv[i] != NULL; i++) {
        printf("argv[%2d] : %s\n", i, argv[i]);
    }

    printf("Enviroment variables:\n");
    for (int j = 0; envp[j] != NULL; j++) {
        printf("envp[%2d]: %s\n", j, envp[j]);
    }

    exit(0);
}