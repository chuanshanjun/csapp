#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {
    struct in_addr inaddr;
    uint32_t addr;
    char buf[10240];

    sscanf(argv[1], "%x", &addr);
    inaddr.s_addr = htonl(addr);

    inet_ntop(AF_INET, &inaddr, buf, 10240);

    printf("%s\n", buf);
}