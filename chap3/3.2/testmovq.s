	.file	"testmovq.c"
	.text
	.globl	movq
	.type	movq, @function
movq:
.LFB0:
	.cfi_startproc
	endbr64
	addl	%esi, %edi
	movl	%edi, (%rdx)
	ret
	.cfi_endproc
.LFE0:
	.size	movq, .-movq
	.globl	movq2
	.type	movq2, @function
movq2:
.LFB1:
	.cfi_startproc
	endbr64
	addq	%rsi, %rdi
	movq	%rdi, (%rdx)
	ret
	.cfi_endproc
.LFE1:
	.size	movq2, .-movq2
	.globl	movq3
	.type	movq3, @function
movq3:
.LFB2:
	.cfi_startproc
	endbr64
	movl	%esi, %esi
	addq	%rdi, %rsi
	movq	%rsi, (%rdx)
	ret
	.cfi_endproc
.LFE2:
	.size	movq3, .-movq3
	.globl	movq4
	.type	movq4, @function
movq4:
.LFB3:
	.cfi_startproc
	endbr64
	movl	%esi, %esi
	movabsq	$4822678189205111, %rax
	addq	%rax, %rsi
	movq	%rsi, (%rdx)
	ret
	.cfi_endproc
.LFE3:
	.size	movq4, .-movq4
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
