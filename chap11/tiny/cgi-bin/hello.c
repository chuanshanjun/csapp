#include "young.h"

int main() {
    char buf[] = "Hello World!";
    Rio_writen(STDOUT_FILENO, buf, strlen(buf));
}