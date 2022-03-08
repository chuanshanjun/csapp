// typedef union {
//     struct {
//         long u;
//         short v;
//         char w;
//     } t1;
//     struct {
//         int a[2];
//         char *p;
//     } t2;    
// } u_type;

// // up in %rdi, dest in %rsi
// void get(u_type *up, long *dest) {
//     // movq (%rdi), %rax
//     // movq %rax, (%rsi)
//     *dest = up->t1.u;
// }

// // up in %rdi, dest in %rsi
// void get(u_type *up, short *dest) {
//     // movw 8(%rdi), %rax
//     // movw %rax, (%rsi)
//     *dest = up->t1.v;
// }

// // up in %rdi, dest in %rsi
// void get(u_type *up, char *dest) {
//     // leaq 10(%rdi), %rsi
//     *dest = &up->t1.w;
// }

// // up in %rdi, dest in %rsi
// void get(u_type *up, int *dest) {
//     // movl (%rdi), %rax
//     // movl %rax, (%rsi)
//     *dest = up->t2.a;
// }

// // up in %rdi, dest in %rsi
// void get(u_type *up, int *dest) {
//     // movq (%rdi), %rax
//     // movq 8(%rdi, %rax, 4), %rax
//     // movq %rax, (%rsi)
//     *dest = up->t2.a[up->t1.u];
// }

// // up in %rdi, dest in %rsi
// void get(u_type *up, char *dest) {
//     // movq 8(%rdi), %rax
//     // movq %rax, %rsi
//     *dest = *up->t2.p;
// }

// //  3.1
// %rax 0x100
// 0x104 0xAB
// $0x108 0x108
// (%rax) 0xFF
// 4(%rax) 0xAB
// 9(%rax, %rdx) 0x11
// 260(%rcx, %rdx) 0x13
// 0xFC(,%rcx,4) 0xFF
// (%rax, %rdx, 4) 0x11

// Registers: r in %rdi
// movl (%rdi), %eax Get r->i
// movl %eax, 4(%rdi) Store in r->j

// // r in %rdi, i in %rsi
// // Registers: r in %rdi, i %rsi
// leaq 8(%rdi, %rsi, 4), %rax Set %rax to &r->a[i]

// r->p = &r->a[r->i + r->j];

// // 3.41
// struct prob {
//     int *p;
//     struct {
//         int x;
//         int y;
//     } s;
//     struct prob *next;
// };

// void sp_init(struct prob *sp) {
//     sp->s.x = sp->s.y;
//     sp->p = &(sp->s.x);
//     sp->next = sp;
// };

typedef union {
    struct {
        long u;
        short v;
        char w;
    } t1;
    struct {
        int a[2];
        char *p;
    } t2;
} u_type;

// up in %rdi, dest in %rsi
void get(u_type *up, long dest) {
    movq (%rdi), %rax // up->t1.u
    movq %rax, (%rsi) // *dest = up->t1.u
    dest = up->t1.u;
}

// up in %rdi, dest in %rsi
void get(u_type *up, short dest) {
    movw 8(%rdi), %ax
    movw %ax, (%rsi)
    dest = up->t1.v
}

// up in %rdi, dest in %rsi
void get(u_type *up, char *dest) {
    addq $, %rdi
    movq %rdi, (%rsi)
    dest = &(up->t1.w);
}

// up in %rdi, dest in %rsi
void get(u_type *up, int *dest) {
    movq %rdi, %rsi
    *dest = up->t2.a;
}

void get(u_type *up) {
    movq (%rdi), %rax up->t1.u
    movl (%rdi, %rax, 4), %eax
    movl %eax,(%rsi)
    up->t2.a[up->t1.u]
}

void get(u_type *up, char dest) {
    movq 8(%rdi), %rax
    movb (%rax), %al
    movb %al, (%rsi)
    dest = *up->t2.p;
}