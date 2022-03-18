	.file	"vec.c"
	.text
	.globl	new_vec
	.type	new_vec, @function
new_vec:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbp
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, %rbx
	testq	%rax, %rax
	je	.L1
	movq	%rbp, (%rax)
	testq	%rbp, %rbp
	jg	.L6
	movl	$0, %ebp
.L3:
	movq	%rbp, 8(%rbx)
.L1:
	movq	%rbx, %rax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	movl	$8, %esi
	movq	%rbp, %rdi
	call	calloc@PLT
	movq	%rax, %rbp
	testq	%rax, %rax
	jne	.L3
	movq	%rbx, %rdi
	call	free@PLT
	movq	%rbp, %rbx
	jmp	.L1
	.cfi_endproc
.LFE39:
	.size	new_vec, .-new_vec
	.globl	get_vec_element
	.type	get_vec_element, @function
get_vec_element:
.LFB40:
	.cfi_startproc
	endbr64
	testq	%rsi, %rsi
	js	.L9
	cmpq	%rsi, (%rdi)
	jle	.L10
	movq	8(%rdi), %rax
	movsd	(%rax,%rsi,8), %xmm0
	movsd	%xmm0, (%rdx)
	movl	$1, %eax
	ret
.L9:
	movl	$0, %eax
	ret
.L10:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE40:
	.size	get_vec_element, .-get_vec_element
	.globl	vec_length
	.type	vec_length, @function
vec_length:
.LFB41:
	.cfi_startproc
	endbr64
	movq	(%rdi), %rax
	ret
	.cfi_endproc
.LFE41:
	.size	vec_length, .-vec_length
	.globl	get_vec_start
	.type	get_vec_start, @function
get_vec_start:
.LFB42:
	.cfi_startproc
	endbr64
	movq	8(%rdi), %rax
	ret
	.cfi_endproc
.LFE42:
	.size	get_vec_start, .-get_vec_start
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"after combine1"
	.text
	.globl	combine1
	.type	combine1, @function
combine1:
.LFB43:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	movq	%rdi, %r12
	movq	%rsi, %rbp
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	$0x000000000, (%rsi)
	movl	$0, %ebx
.L14:
	movq	%r12, %rdi
	call	vec_length
	cmpq	%rbx, %rax
	jle	.L18
	movq	%rsp, %rdx
	movq	%rbx, %rsi
	movq	%r12, %rdi
	call	get_vec_element
	movsd	0(%rbp), %xmm0
	mulsd	(%rsp), %xmm0
	movsd	%xmm0, 0(%rbp)
	addq	$1, %rbx
	jmp	.L14
.L18:
	leaq	.LC1(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L19
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L19:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE43:
	.size	combine1, .-combine1
	.globl	combine2
	.type	combine2, @function
combine2:
.LFB44:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	movq	%rdi, %r13
	movq	%rsi, %rbp
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	vec_length
	movq	%rax, %r12
	movq	$0x000000000, 0(%rbp)
	movl	$0, %ebx
.L21:
	cmpq	%r12, %rbx
	jge	.L25
	movq	%rsp, %rdx
	movq	%rbx, %rsi
	movq	%r13, %rdi
	call	get_vec_element
	movsd	0(%rbp), %xmm0
	mulsd	(%rsp), %xmm0
	movsd	%xmm0, 0(%rbp)
	addq	$1, %rbx
	jmp	.L21
.L25:
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L26
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L26:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE44:
	.size	combine2, .-combine2
	.globl	combine3
	.type	combine3, @function
combine3:
.LFB45:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %r12
	movq	%rsi, %rbx
	call	vec_length
	movq	%rax, %rbp
	movq	%r12, %rdi
	call	get_vec_start
	movq	$0x000000000, (%rbx)
	movl	$0, %edx
.L28:
	cmpq	%rbp, %rdx
	jge	.L31
	movsd	(%rax,%rdx,8), %xmm0
	mulsd	(%rbx), %xmm0
	movsd	%xmm0, (%rbx)
	addq	$1, %rdx
	jmp	.L28
.L31:
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE45:
	.size	combine3, .-combine3
	.globl	combine3o2
	.type	combine3o2, @function
combine3o2:
.LFB46:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %r12
	movq	%rsi, %rbx
	call	vec_length
	movq	%rax, %rbp
	movq	%r12, %rdi
	call	get_vec_start
	movq	$0x000000000, (%rbx)
	pxor	%xmm0, %xmm0
	movl	$0, %edx
.L33:
	cmpq	%rbp, %rdx
	jge	.L36
	mulsd	(%rax,%rdx,8), %xmm0
	movsd	%xmm0, (%rbx)
	addq	$1, %rdx
	jmp	.L33
.L36:
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE46:
	.size	combine3o2, .-combine3o2
	.globl	combine4
	.type	combine4, @function
combine4:
.LFB47:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %r12
	movq	%rsi, %rbp
	call	vec_length
	movq	%rax, %rbx
	movq	%r12, %rdi
	call	get_vec_start
	pxor	%xmm0, %xmm0
	movl	$0, %edx
.L38:
	cmpq	%rbx, %rdx
	jge	.L41
	mulsd	(%rax,%rdx,8), %xmm0
	addq	$1, %rdx
	jmp	.L38
.L41:
	movsd	%xmm0, 0(%rbp)
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE47:
	.size	combine4, .-combine4
	.globl	combine5
	.type	combine5, @function
combine5:
.LFB48:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %r13
	movq	%rsi, %r12
	call	vec_length
	movq	%rax, %rbp
	leaq	-1(%rax), %rbx
	movq	%r13, %rdi
	call	get_vec_start
	pxor	%xmm0, %xmm0
	movl	$0, %edx
.L43:
	cmpq	%rbx, %rdx
	jge	.L45
	mulsd	(%rax,%rdx,8), %xmm0
	mulsd	8(%rax,%rdx,8), %xmm0
	addq	$2, %rdx
	jmp	.L43
.L46:
	mulsd	(%rax,%rdx,8), %xmm0
	addq	$1, %rdx
.L45:
	cmpq	%rbp, %rdx
	jl	.L46
	movsd	%xmm0, (%r12)
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE48:
	.size	combine5, .-combine5
	.globl	combine6
	.type	combine6, @function
combine6:
.LFB49:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %r13
	movq	%rsi, %rbp
	call	vec_length
	movq	%rax, %r12
	leaq	-1(%rax), %rbx
	movq	%r13, %rdi
	call	get_vec_start
	pxor	%xmm1, %xmm1
	movapd	%xmm1, %xmm0
	movl	$0, %edx
.L49:
	cmpq	%rbx, %rdx
	jge	.L51
	mulsd	(%rax,%rdx,8), %xmm0
	mulsd	8(%rax,%rdx,8), %xmm1
	addq	$2, %rdx
	jmp	.L49
.L52:
	mulsd	(%rax,%rdx,8), %xmm0
	addq	$1, %rdx
.L51:
	cmpq	%r12, %rdx
	jl	.L52
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, 0(%rbp)
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE49:
	.size	combine6, .-combine6
	.globl	combine7
	.type	combine7, @function
combine7:
.LFB50:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %r13
	movq	%rsi, %r12
	call	vec_length
	movq	%rax, %rbp
	leaq	-1(%rax), %rbx
	movq	%r13, %rdi
	call	get_vec_start
	pxor	%xmm1, %xmm1
	movl	$0, %edx
.L55:
	cmpq	%rbx, %rdx
	jge	.L57
	movsd	8(%rax,%rdx,8), %xmm0
	mulsd	(%rax,%rdx,8), %xmm0
	mulsd	%xmm0, %xmm1
	addq	$2, %rdx
	jmp	.L55
.L58:
	mulsd	(%rax,%rdx,8), %xmm1
	addq	$1, %rdx
.L57:
	cmpq	%rbp, %rdx
	jl	.L58
	movsd	%xmm1, (%r12)
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE50:
	.size	combine7, .-combine7
	.globl	aprod
	.type	aprod, @function
aprod:
.LFB51:
	.cfi_startproc
	endbr64
	movsd	.LC2(%rip), %xmm0
	movl	$0, %eax
.L61:
	leaq	-2(%rsi), %rdx
	cmpq	%rax, %rdx
	jle	.L63
	mulsd	(%rdi,%rax,8), %xmm0
	mulsd	8(%rdi,%rax,8), %xmm0
	mulsd	16(%rdi,%rax,8), %xmm0
	addq	$3, %rax
	jmp	.L61
.L64:
	mulsd	(%rdi,%rax,8), %xmm0
	addq	$1, %rax
.L63:
	cmpq	%rsi, %rax
	jl	.L64
	ret
	.cfi_endproc
.LFE51:
	.size	aprod, .-aprod
	.section	.rodata.str1.1
.LC3:
	.string	"data[%d] = %ld "
.LC4:
	.string	"final val = %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB52:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movl	$4, %edi
	call	new_vec
	movq	%rax, %rbx
	movl	$0, %edx
	jmp	.L66
.L67:
	movslq	%edx, %rax
	salq	$3, %rax
	addq	8(%rbx), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%edx, %xmm0
	movsd	%xmm0, (%rax)
	addl	$1, %edx
.L66:
	cmpl	$3, %edx
	jle	.L67
	movl	$0, %ebp
	jmp	.L68
.L69:
	movslq	%ebp, %rax
	salq	$3, %rax
	addq	8(%rbx), %rax
	movsd	(%rax), %xmm0
	movl	%ebp, %edx
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	addl	$1, %ebp
.L68:
	cmpl	$3, %ebp
	jle	.L69
	movl	$10, %edi
	call	putchar@PLT
	movq	%rsp, %rsi
	movq	%rbx, %rdi
	call	combine1
	movsd	(%rsp), %xmm0
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L72
	movl	$0, %eax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L72:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE52:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	0
	.long	1072693248
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
