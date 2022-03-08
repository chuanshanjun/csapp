#include <stdio.h>
#include <arpa/inet.h>

/**
 * @brief 
 * linux> ./hex2dd 0x8002c2f2
 * 128.2.194.242
 * 
 * @return int 
 */
int main(int argc, char** argv) {
    // 1 获取输入的十六进制地址
    unsigned int addr;
    sscanf(argv[1], "%x", &addr);

    printf("input hex addr =0x%x\n", addr);

    // 2 将地址转换成二进制的网络字节顺序
    unsigned int netaddr = htonl(addr); /* 将32位整数由主机字节顺序转换成网络字节顺序 */
    printf("netaddr =0x%x\n", netaddr);

    struct in_addr addrstruct;
    addrstruct.s_addr = htonl(addr);
    
    char daddr[32];

    inet_ntop(AF_INET, &netaddr, daddr, 32);

    printf("%s\n", daddr);

    inet_ntop(AF_INET, &addrstruct.s_addr, daddr, 32);

    printf("%s\n", daddr);

    inet_ntop(AF_INET, &addrstruct, daddr, 32);

    printf("%s\n", daddr);
}