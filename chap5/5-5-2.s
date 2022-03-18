	.file	"5-5-2.c"
	.text
	.globl	poly
	.type	poly, @function
poly:
.LFB0:
	.cfi_startproc
	endbr64
	movapd	%xmm0, %xmm2
	movsd	(%rdi), %xmm0
	movl	$0, %eax
.L2:
	cmpq	%rsi, %rax
	jge	.L4
	movapd	%xmm2, %xmm1
	mulsd	(%rdi,%rax,8), %xmm1
	addsd	%xmm1, %xmm0
	addq	$1, %rax
	jmp	.L2
.L4:
	ret
	.cfi_endproc
.LFE0:
	.size	poly, .-poly
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
