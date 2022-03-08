struct prob {
    int *p;
    struct {
        int x;
        int y;
    } s;
    struct prob *next;
};

void sp_init(struct prob *sp) {
    sp->s.x = sp->s.y;
    sp->p = &(sp->s.x);
    sp->next = sp;
}

// sp_init:
//     // 12字节
//     movl 12(%rdi), %eax Get sp->s.y
//     movl %eax, 8(%rdi) Save in sp->s.x
//     leap 8(%rdi), %rax Compute &(sp->s.x)
//     movq %rax, (%rdi) Store in sp->p
//     movq %rdi, 16(%rdi) Store sp in sp->next
//     ret

// A: p:0
//     s.x:8
//     s.y:12
//     next:16
// B: 8+8+8=24字节
// C:

