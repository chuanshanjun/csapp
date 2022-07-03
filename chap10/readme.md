

### 系统调用时，一定要对返回值做判断

```C
/**
 * 在shell运行时，它是先读完一行文本后再将其写出
 * 这是因为终端的接口决定它必须读入完整的一行后才会
 * 唤醒这段代码
 * 实际上，它只是一次一个字节地将这些字符打印出来
 * /
#include "csapp.h"

int main(void) {
    char c;

    while (Read(STDIN_FILENO, &c, 1) != 0)
        Write(STDOUT_FILENO, &c, 1);
    exit(0); 
}
```
 
### 从读写的角度来说，系统调用的开销是比较打的。这意味着将操作过程全抛给操作系统，执行所谓的上下文切换。为此，它会进入系统内核，调用操作系统函数，按指令完成读、写操作，再切回到先前的工作。这个过程通常需要20000到40000个时钟周期。

### 可以使用strace来追踪每次的系统调用

### 如果接近EOF，假设还剩100个字节，但你指定读入200个字节，第一次调用read时，它将读入100个字节并返回100，然后进行第二次调用，它将返回0。我们实际上是这样检测到EOF的。这与其它不足值情况不同，返回值为0的唯一可能就是遇到EOF。

### 在写代码时不用考虑缓冲区的大小，它将取决于具体的代码实现。总之，写代码时应该考虑到可能出现不足值。不过，使用这种低级I/O的一个麻烦就是，处理不足值，这通常是一种应用程序级的麻烦。因此通常会将此类低级I/O操作封装到正在调用的其它库中。

### 通常在编写使用while循环的代码时，必须考虑到不足值的情况

### 不能对没有行概念的文件进行基于行的I/O操作,
> Text-oriented I/O such as fgets, scanf, rio_readlinb  
> String functions
* strlen, strcpy, strcat 遇到空字节(null)时会停止操作，在发送网络数据包时，一定要避免发生
这些函数处理新行符0xa这个特殊字符时会停止读入  

### 在使用这些函数前 你一定要想清楚

* The Unix bible:
    W.Richard Stevens & Stephen **Advanced Programming in the Unix Enviroment**

* The Linux bible
    Michael Kerrisk, The Linux Programmin Interface

### 10.7 读取目录内容
* 函数opendir以路径名为参数，返回指向**目录流(directory stream)**的指针。流是对条目有序列列表的抽象，在这里是指目录项的列表。

### 10.8 共享文件
内核用三个相关的数据结构来表示打开的文件；