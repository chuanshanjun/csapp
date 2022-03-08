	.file	"3-16.c"
	.text
	.globl	cond
	.type	cond, @function
cond:
.LFB0:
	.cfi_startproc
	endbr64
	testq	%rsi, %rsi // if p == 0 then ZF = 0
	je	.L1 // if ZF == 0 then jump .L1
	cmpq	%rdi, (%rsi) comapre * p with a
	jge	.L1 // if *p >= a then jump .L1
	movq	%rdi, (%rsi) // *p = a
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	cond, .-cond
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
