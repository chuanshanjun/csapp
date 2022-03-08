#include <stdio.h>
#include <arpa/inet.h>

/**
 * @brief 
 * linux> ./dd2hex 128.2.194.242
 * 0x8002c2f2
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv) {
    char *ddaddr = argv[1];
    printf("input ddaddr: %s\n", ddaddr);

    unsigned int naddr;

    inet_pton(AF_INET, ddaddr, &naddr);

    printf("naddr = 0x%x\n", naddr);

    unsigned int haddr = ntohl(naddr);
    printf("0x%x\n", haddr);
}