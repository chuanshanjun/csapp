	.file	"5-5.c"
	.text
	.globl	poly
	.type	poly, @function
poly:
.LFB0:
	.cfi_startproc
	endbr64
	movapd	%xmm0, %xmm3
	movsd	(%rdi), %xmm0
	movapd	%xmm3, %xmm1
	movl	$1, %eax
.L2:
	cmpq	%rsi, %rax
	jg	.L4
	movapd	%xmm1, %xmm2
	mulsd	(%rdi,%rax,8), %xmm2
	addsd	%xmm2, %xmm0
	mulsd	%xmm3, %xmm1
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
