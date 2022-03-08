struct {
    char *a; // 0 
    short b; // 8
    double c; // 16
    char d; // 24
    float e; //25
    char f; // 29
    long g; // 32
    int h; // 36
} rec;

total size 40;

对齐值8

2 + 1 + 1 + 补齐 4
short b
char d
char f 

4 + 4
float e
int h
