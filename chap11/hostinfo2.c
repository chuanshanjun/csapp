#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    struct addrinfo *p, *listp, hints;
    char buf[MAXLINE];
    int rc, flags;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <domain name>\n", argv[0]);
        exit(0);
    }

    /* Get a list of addrinfo records */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; /* IPv4 only */
    hints.ai_socktype = SOCK_STREAM; /* Connection only */
    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
        exit(1);
    }

    /* Walk the list and display each IP address */
    flags = NI_NUMERICHOST; /* Display address string instead of domain name */
    for (p = listp; p; p = p->ai_next) {
        // 自己做的11.4练习
        // struct sockaddr *addr = p->ai_addr;
        // socklen_t addrlen = p->ai_addrlen;

        // // cast *sockaddr to *sockaddr_in
        // struct sockaddr_in *sin_addr = (struct sockaddr_in*)addr;
        // struct in_addr inaddr = sin_addr->sin_addr;

        // char dst[32];

        // inet_ntop(AF_INET, &inaddr, dst, 32);
        // printf("%s\n", dst);

        // 原方案
        // getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
        // printf("%s\n", buf);

        // 11.4 书上解决方案
        struct sockaddr_in *sockp = (struct sockeraddr_in*)p->ai_addr;
        inet_ntop(AF_INET, &(sockp->sin_addr), buf, MAXLINE);
        printf("%s\n", buf);
    }

    /* Clean up */
    freeaddrinfo(listp);
    
    exit(0);
}