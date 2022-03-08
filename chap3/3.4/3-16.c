void cond(long a, long *p) {
    if (p && a > *p) {
        *p = a;
    }
}

// 	testq	%rsi, %rsi // if p == 0 then ZF = 0
// 	je	.L1 // if ZF == 0 then jump .L1
// 	cmpq	%rdi, (%rsi) comapre * p with a
// 	jge	.L1 // if *p >= a then jump .L1
// 	movq	%rdi, (%rsi) // *p = a
// .L1:
// 	ret
// 	.cfi_endproc

void gotocond(long a, long *p) {
    if (p == 0) {
        goto done;
    }

    if (*p >= a) {
        goto done;
    }

    *p = a;
done:
    return;
}
