#include <stdio.h>
#include <string.h>

// 1 fgets()
// 2 feof()
// 3 strcpy
// 4 strlen 是否包含 '/0'
// 5 str指针++
// 6 str指针+1
// 7 strchr
// 8 NULL

int Fgets();

int Fgets() {
    FILE *fp;
    char str[60];

    /* 打开用于读取的文件 */
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("打开文件时发生错误");
        return(-1);
    }
    
    if (fgets(str, 60, fp) != NULL) {
        /* 向标准输出 stdout 写入内容 */
        puts(str);
    }
    fclose(fp);

    printf("file msg: %s\n", str);

    return(0);
}

// 2 feoc()
int Feof() {
    FILE *fp;
    int c;

    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("open file error");
        return(-1);
    }

    while(1) {
        c = fgetc(fp);
        if (feof(fp)) {
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
    return(0);
}

// 3 strcpy
void Strcpy() {
    // demo1
    char str1[] = "Sample string";
    char str2[40];
    char str3[40];

    strcpy(str2, str1);
    strcpy(str3, "copy successful");
    printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);

    // demo2
    char src[40];
    char dst[100];
    memset(dst, '\0', sizeof(dst));
    strcpy(src, "This is runoob.com");
    strcpy(dst, src);
    printf("src = %s\ndst= %s\n", src, dst);
}

// str
void Str() {
    // 1 初始化
    char str1[5] = {'L', 'O', 'V', 'E', '\0'};
    char str2[5] = {'L', 'O', 'V', 'E', '\0'};
    char str3[] = "LOVE";

    printf("strlen str1: %ld\nstr2: %ld\nstr3: %ld\n", strlen(str1), strlen(str2), strlen(str3));
    printf("sizeof str1: %ld\nstr2: %ld\nstr3: %ld\n", sizeof(str1), sizeof(str2), sizeof(str3));
}

// str指针++
// &str1 指向字符串第一个字符地址
void Strpp() {
    char str1[] = "ABC";
    int i;

    char *str2 = "DEF"; 

    for (i = 0; i < strlen(str1); i++) {
        printf("str[%d] = %c, ptr = %p\n", i, str1[i], &str1);
    }

    printf("------\n");

    for (i = 0; i < strlen(str1); i++) {
        printf("str[%d] = %c, ptr = %p\n", i, str1[i], &str1[i]);
    }

    printf("------\n");

    printf("strlen(str2)=%ld\n", strlen(str2));

    printf("str2=%s\n", str2);

    printf("*str2=%c ptr=%p\n", *str2, str2);

    printf("str2++=%c ptr=%p\n", *(str2++), str2);

}

// 7 strch 
int Strch() {
    const char str[] = "http://www.runoob.com";
    const char ch = 'p';
    char *ret;

    ret = strchr(str, ch);

    printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);

    return(0);
}

// pointer ++
int Pointerpp() {
    int max = 3;

    int var[] = {10, 100, 200};
    int i, *ptr;

    printf("var addr =%p\n", var);

    printf("var value =%d\n", *var);

    ptr = var;
    for (i = 0; i < max; i++) {
        printf("存储地址 var[%d] = %p\n", i, ptr);
        printf("存储值 var[%d] = %d\n", i, *ptr);

        /* 指向下一个地址 */
        ptr++;
    }
    return 0;
}

int StrPointerpp() {
    int i;
    int max = 3;
    char *str = "ABC";

    for (i = 0; i < max; i++) {
        printf("存储地址 = %p\n存储值 = %c\n", str, *str);
        str++;
    } 

    return(0);
}

int parseline(char *buf, char **argv) {
    char *delim;
    int argc;
    int bg; 

    buf[strlen(buf) - 1] = ' ';
    while (*buf && (*buf == ' '))
        buf++;

    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0)
        return 1;

    if ((bg = (*argv[argc-1] == '&')) != 0) {
        argv[--argc] = NULL;
    } 

    return bg;
}

int main() {
    // Strpp();
    // Pointerpp();
    // StrPointerpp();
    int maxl = 16;

    int *argv[1024];

    char cmd[maxl];

    char* ret;

    if ((ret = fgets(cmd, maxl, stdin)) == NULL) {
        perror("get msg from stdin error");
        exit(1);
    }

    parseline(cmd, argv);

    for (int i = 0; i < sizeof(argv)/sizeof(argv[0]); i++) {
        printf("argv[%d] = addr = %p\n val = %s\n", i, argv[i], *argv[i]);
    }
}
