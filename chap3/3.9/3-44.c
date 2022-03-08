// 每个字段的偏移量 结构总的大小

struct P1 {int i; char c; int j; char d;};
// i offset 0
// c offset 4
// j offset 8
// d offset 12
// total size = 16?
// 4

struct P2 {int i; char c; char d; long j;};
// i 0
// c 4
// d 5
// j 8
// total size 16
// 8

struct P3 {short w[3]; char c[3]};
// w 0
// c 6
// 10
// 2

struct P4 {short w[5]; char *c[3]};
// w 0
// c 16
// 40
// 8

struct P5 {struct P3 a[2]; struct P2 t};
// a 0
// t 24
// 48 
16