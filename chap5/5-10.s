	.file	"5-10.c"
	.text
	.globl	copy_array
	.type	copy_array, @function
copy_array:
.LFB0:
	.cfi_startproc
	endbr64
	testq	%rdx, %rdx
	jle	.L1
	movl	$0, %eax
.L3:
	movq	(%rdi,%rax,8), %rcx
	movq	%rcx, (%rsi,%rax,8)
	addq	$1, %rax
	cmpq	%rax, %rdx
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	copy_array, .-copy_array
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
