#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {
    struct in_addr addr;
    unsigned int addrr;
    char *hexaddr = argv[1];
    if (hexaddr == NULL)
        fprintf(stderr, "%s %s\n", "argv err", strerror(errno));

    void* dst;
    if (inet_pton(AF_INET, hexaddr, &addrr) <= 0)
        fprintf(stderr, "%s %s\n", "argv err", strerror(errno));

    printf("%p\n", ntohl(addrr));
}