	.file	"5-9.c"
	.text
	.globl	merge
	.type	merge, @function
merge:
.LFB0:
	.cfi_startproc
	endbr64
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %eax
	cmpq	%r8, %rax
	movq	%r8, %r10
	cmovge	%rax, %r10
	cmpq	%rcx, %r10
	jge	.L8
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	jmp	.L4
.L3:
	movq	%r10, %r9
	movq	%rbx, %rax
	cmpq	%r8, %rbx
	movq	%r8, %r10
	cmovge	%rbx, %r10
	cmpq	%rcx, %r10
	jge	.L9
.L4:
	leaq	1(%rax), %rbx
	leaq	1(%r9), %r10
	movq	(%rdi,%rax,8), %r11
	movq	%r11, (%rdx,%r9,8)
	movq	(%rsi,%r8,8), %r11
	cmpq	%r11, 8(%rdi,%rax,8)
	jle	.L3
	addq	$1, %r8
	movq	%r11, (%rdx,%r10,8)
	leaq	2(%r9), %r10
	jmp	.L3
.L9:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L8:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE0:
	.size	merge, .-merge
	.globl	merge2
	.type	merge2, @function
merge2:
.LFB1:
	.cfi_startproc
	endbr64
	movl	$0, %r11d
	movl	$0, %r8d
	movl	$0, %eax
	cmpq	%r8, %rax
	movq	%r8, %r9
	cmovge	%rax, %r9
	cmpq	%rcx, %r9
	jge	.L17
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	jmp	.L13
.L12:
	movq	%r9, (%rdx,%r11,8)
	addq	%rbx, %rax
	movl	$1, %r9d
	subq	%rbx, %r9
	addq	%r9, %r8
	leaq	1(%r11), %r11
	cmpq	%r8, %rax
	movq	%r8, %r9
	cmovge	%rax, %r9
	cmpq	%rcx, %r9
	jge	.L18
.L13:
	movq	(%rdi,%rax,8), %r10
	movq	(%rsi,%r8,8), %r9
	cmpq	%r9, %r10
	setl	%bl
	movzbl	%bl, %ebx
	jge	.L12
	movq	%r10, %r9
	jmp	.L12
.L18:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L17:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE1:
	.size	merge2, .-merge2
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
