	.file	"young.c"
	.text
	.section	.rodata
.LC0:
	.string	"%s: %s\n"
	.text
	.globl	unix_error
	.type	unix_error, @function
unix_error:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rcx
	movq	stderr(%rip), %rax
	movq	-8(%rbp), %rdx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE6:
	.size	unix_error, .-unix_error
	.globl	gai_error
	.type	gai_error, @function
gai_error:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	gai_strerror@PLT
	movq	%rax, %rcx
	movq	stderr(%rip), %rax
	movq	-16(%rbp), %rdx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE7:
	.size	gai_error, .-gai_error
	.section	.rodata
.LC1:
	.string	"%s\n"
	.text
	.globl	app_error
	.type	app_error, @function
app_error:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	stderr(%rip), %rax
	movq	-8(%rbp), %rdx
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE8:
	.size	app_error, .-app_error
	.globl	posix_error
	.type	posix_error, @function
posix_error:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rcx
	movq	stderr(%rip), %rax
	movq	-16(%rbp), %rdx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE9:
	.size	posix_error, .-posix_error
	.section	.rodata
	.align 8
.LC2:
	.string	"getaddrinfo failed (port %s): %s\n"
	.align 8
.LC3:
	.string	"open_listenfd close failed: %s\n"
	.text
	.globl	open_listenfd
	.type	open_listenfd, @function
open_listenfd:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movq	%rdi, -104(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -92(%rbp)
	leaq	-64(%rbp), %rax
	movl	$48, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movl	$1, -56(%rbp)
	movl	$33, -64(%rbp)
	movl	-64(%rbp), %eax
	orb	$4, %ah
	movl	%eax, -64(%rbp)
	leaq	-80(%rbp), %rcx
	leaq	-64(%rbp), %rdx
	movq	-104(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	getaddrinfo@PLT
	movl	%eax, -84(%rbp)
	cmpl	$0, -84(%rbp)
	je	.L6
	movl	-84(%rbp), %eax
	movl	%eax, %edi
	call	gai_strerror@PLT
	movq	%rax, %rcx
	movq	stderr(%rip), %rax
	movq	-104(%rbp), %rdx
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$-2, %eax
	jmp	.L16
.L6:
	movq	-80(%rbp), %rax
	movq	%rax, -72(%rbp)
	jmp	.L8
.L13:
	movq	-72(%rbp), %rax
	movl	12(%rax), %edx
	movq	-72(%rbp), %rax
	movl	8(%rax), %ecx
	movq	-72(%rbp), %rax
	movl	4(%rax), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	socket@PLT
	movl	%eax, -88(%rbp)
	cmpl	$0, -88(%rbp)
	js	.L18
	leaq	-92(%rbp), %rdx
	movl	-88(%rbp), %eax
	movl	$4, %r8d
	movq	%rdx, %rcx
	movl	$2, %edx
	movl	$1, %esi
	movl	%eax, %edi
	call	setsockopt@PLT
	movq	-72(%rbp), %rax
	movl	16(%rax), %edx
	movq	-72(%rbp), %rax
	movq	24(%rax), %rcx
	movl	-88(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	bind@PLT
	testl	%eax, %eax
	je	.L19
	movl	-88(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	testl	%eax, %eax
	jns	.L10
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rdx
	movq	stderr(%rip), %rax
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$-1, %eax
	jmp	.L16
.L18:
	nop
.L10:
	movq	-72(%rbp), %rax
	movq	40(%rax), %rax
	movq	%rax, -72(%rbp)
.L8:
	cmpq	$0, -72(%rbp)
	jne	.L13
	jmp	.L12
.L19:
	nop
.L12:
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	freeaddrinfo@PLT
	cmpq	$0, -72(%rbp)
	jne	.L14
	movl	$-1, %eax
	jmp	.L16
.L14:
	movl	-88(%rbp), %eax
	movl	$1024, %esi
	movl	%eax, %edi
	call	listen@PLT
	testl	%eax, %eax
	jns	.L15
	movl	-88(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	$-1, %eax
	jmp	.L16
.L15:
	movl	-88(%rbp), %eax
.L16:
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L17
	call	__stack_chk_fail@PLT
.L17:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	open_listenfd, .-open_listenfd
	.section	.rodata
.LC4:
	.string	"Accept error"
	.text
	.globl	Accept
	.type	Accept, @function
Accept:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movl	-20(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	accept@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L21
	leaq	.LC4(%rip), %rdi
	call	unix_error
.L21:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	Accept, .-Accept
	.section	.rodata
.LC5:
	.string	"Getnameinfo error"
	.text
	.globl	Getnameinfo
	.type	Getnameinfo, @function
Getnameinfo:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	%r8, -56(%rbp)
	movq	%r9, -64(%rbp)
	movq	-64(%rbp), %rax
	movl	%eax, %r8d
	movq	-48(%rbp), %rax
	movl	%eax, %r10d
	movq	-56(%rbp), %rdi
	movq	-40(%rbp), %rdx
	movl	-28(%rbp), %esi
	movq	-24(%rbp), %rax
	subq	$8, %rsp
	movl	16(%rbp), %ecx
	pushq	%rcx
	movl	%r8d, %r9d
	movq	%rdi, %r8
	movl	%r10d, %ecx
	movq	%rax, %rdi
	call	getnameinfo@PLT
	addq	$16, %rsp
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L25
	movl	-4(%rbp), %eax
	leaq	.LC5(%rip), %rsi
	movl	%eax, %edi
	call	gai_error
.L25:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	Getnameinfo, .-Getnameinfo
	.section	.rodata
.LC6:
	.string	"Close error"
	.text
	.globl	Close
	.type	Close, @function
Close:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L28
	leaq	.LC6(%rip), %rdi
	call	unix_error
.L28:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	Close, .-Close
	.section	.rodata
.LC7:
	.string	"Open_listenfd error"
	.text
	.globl	Open_listenfd
	.type	Open_listenfd, @function
Open_listenfd:
.LFB14:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	open_listenfd
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L30
	leaq	.LC7(%rip), %rdi
	call	unix_error
.L30:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	Open_listenfd, .-Open_listenfd
	.globl	rio_readinitb
	.type	rio_readinitb, @function
rio_readinitb:
.LFB15:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	$0, 4(%rax)
	movq	-8(%rbp), %rax
	leaq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	rio_readinitb, .-rio_readinitb
	.globl	Rio_readinitb
	.type	Rio_readinitb, @function
Rio_readinitb:
.LFB16:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	rio_readinitb
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	Rio_readinitb, .-Rio_readinitb
	.type	rio_read, @function
rio_read:
.LFB17:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	jmp	.L35
.L39:
	movq	-24(%rbp), %rax
	leaq	16(%rax), %rcx
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	$8192, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4(%rax)
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	testl	%eax, %eax
	jns	.L36
	call	__errno_location@PLT
	movl	(%rax), %eax
	cmpl	$4, %eax
	je	.L35
	movq	$-1, %rax
	jmp	.L37
.L36:
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	testl	%eax, %eax
	jne	.L38
	movl	$0, %eax
	jmp	.L37
.L38:
	movq	-24(%rbp), %rax
	leaq	16(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
.L35:
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	testl	%eax, %eax
	jle	.L39
	movq	-40(%rbp), %rax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	cltq
	cmpq	%rax, -40(%rbp)
	jbe	.L40
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, -4(%rbp)
.L40:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memcpy@PLT
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	subl	-4(%rbp), %eax
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4(%rax)
	movl	-4(%rbp), %eax
	cltq
.L37:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	rio_read, .-rio_read
	.globl	rio_readlineb
	.type	rio_readlineb, @function
rio_readlineb:
.LFB18:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	$1, -24(%rbp)
	jmp	.L42
.L49:
	leaq	-25(%rbp), %rcx
	movq	-40(%rbp), %rax
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	rio_read
	movl	%eax, -20(%rbp)
	cmpl	$1, -20(%rbp)
	jne	.L43
	movq	-16(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, -16(%rbp)
	movzbl	-25(%rbp), %edx
	movb	%dl, (%rax)
	movzbl	-25(%rbp), %eax
	cmpb	$10, %al
	jne	.L44
	addl	$1, -24(%rbp)
	jmp	.L45
.L43:
	cmpl	$0, -20(%rbp)
	jne	.L46
	cmpl	$1, -24(%rbp)
	jne	.L52
	movl	$0, %eax
	jmp	.L50
.L46:
	movq	$-1, %rax
	jmp	.L50
.L44:
	addl	$1, -24(%rbp)
.L42:
	movl	-24(%rbp), %eax
	cltq
	cmpq	%rax, -56(%rbp)
	ja	.L49
	jmp	.L45
.L52:
	nop
.L45:
	movq	-16(%rbp), %rax
	movb	$0, (%rax)
	movl	-24(%rbp), %eax
	subl	$1, %eax
	cltq
.L50:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L51
	call	__stack_chk_fail@PLT
.L51:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	rio_readlineb, .-rio_readlineb
	.section	.rodata
.LC8:
	.string	"Rio_readlineb error"
	.text
	.globl	Rio_readlineb
	.type	Rio_readlineb, @function
Rio_readlineb:
.LFB19:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	rio_readlineb
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jns	.L54
	leaq	.LC8(%rip), %rdi
	call	unix_error
.L54:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	Rio_readlineb, .-Rio_readlineb
	.globl	rio_writen
	.type	rio_writen, @function
rio_writen:
.LFB20:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L57
.L61:
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rcx
	movl	-36(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write@PLT
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jg	.L58
	call	__errno_location@PLT
	movl	(%rax), %eax
	cmpl	$4, %eax
	jne	.L59
	movq	$0, -16(%rbp)
	jmp	.L58
.L59:
	movq	$-1, %rax
	jmp	.L60
.L58:
	movq	-16(%rbp), %rax
	subq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	addq	%rax, -8(%rbp)
.L57:
	cmpq	$0, -24(%rbp)
	jne	.L61
	movq	-56(%rbp), %rax
.L60:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE20:
	.size	rio_writen, .-rio_writen
	.section	.rodata
.LC9:
	.string	"Rio_writen error"
	.text
	.globl	Rio_writen
	.type	Rio_writen, @function
Rio_writen:
.LFB21:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movl	-4(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	rio_writen
	movq	-24(%rbp), %rdx
	cmpq	%rdx, %rax
	je	.L64
	leaq	.LC9(%rip), %rdi
	call	unix_error
.L64:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE21:
	.size	Rio_writen, .-Rio_writen
	.section	.rodata
.LC10:
	.string	"Open error"
	.text
	.globl	Open
	.type	Open, @function
Open:
.LFB22:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L66
	leaq	.LC10(%rip), %rdi
	call	unix_error
.L66:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE22:
	.size	Open, .-Open
	.section	.rodata
.LC11:
	.string	"mmap error"
	.text
	.globl	Mmap
	.type	Mmap, @function
Mmap:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movl	%ecx, -40(%rbp)
	movl	%r8d, -44(%rbp)
	movq	%r9, -56(%rbp)
	movq	-56(%rbp), %r8
	movl	-44(%rbp), %edi
	movl	-40(%rbp), %ecx
	movl	-36(%rbp), %edx
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rax
	movq	%r8, %r9
	movl	%edi, %r8d
	movq	%rax, %rdi
	call	mmap@PLT
	movq	%rax, -8(%rbp)
	cmpq	$-1, -8(%rbp)
	jne	.L69
	leaq	.LC11(%rip), %rdi
	call	unix_error
.L69:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE23:
	.size	Mmap, .-Mmap
	.section	.rodata
.LC12:
	.string	"munmap error"
	.text
	.globl	Munmap
	.type	Munmap, @function
Munmap:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	munmap@PLT
	testl	%eax, %eax
	jns	.L73
	leaq	.LC12(%rip), %rdi
	call	unix_error
.L73:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE24:
	.size	Munmap, .-Munmap
	.section	.rodata
.LC13:
	.string	"Fork error"
	.text
	.globl	Fork
	.type	Fork, @function
Fork:
.LFB25:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	call	fork@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L75
	leaq	.LC13(%rip), %rdi
	call	unix_error
.L75:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE25:
	.size	Fork, .-Fork
	.section	.rodata
.LC14:
	.string	"Execve error"
	.text
	.globl	Execve
	.type	Execve, @function
Execve:
.LFB26:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	execve@PLT
	testl	%eax, %eax
	jns	.L79
	leaq	.LC14(%rip), %rdi
	call	unix_error
.L79:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE26:
	.size	Execve, .-Execve
	.section	.rodata
.LC15:
	.string	"Dup2 error"
	.text
	.globl	Dup2
	.type	Dup2, @function
Dup2:
.LFB27:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-24(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	dup2@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L81
	leaq	.LC15(%rip), %rdi
	call	unix_error
.L81:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE27:
	.size	Dup2, .-Dup2
	.section	.rodata
.LC16:
	.string	"Wait error"
	.text
	.globl	Wait
	.type	Wait, @function
Wait:
.LFB28:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	wait@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L84
	leaq	.LC16(%rip), %rdi
	call	unix_error
.L84:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE28:
	.size	Wait, .-Wait
	.section	.rodata
	.align 8
.LC17:
	.string	"getaddrinfo failed (%s:%s): %s\n"
	.align 8
.LC18:
	.string	"open_clientfd: close failed: %s\n"
	.text
	.globl	open_clientfd
	.type	open_clientfd, @function
open_clientfd:
.LFB29:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movq	%rdi, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	movl	$48, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movl	$1, -56(%rbp)
	movl	$1024, -64(%rbp)
	movl	-64(%rbp), %eax
	orl	$32, %eax
	movl	%eax, -64(%rbp)
	leaq	-80(%rbp), %rcx
	leaq	-64(%rbp), %rdx
	movq	-112(%rbp), %rsi
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	getaddrinfo@PLT
	movl	%eax, -84(%rbp)
	cmpl	$0, -84(%rbp)
	je	.L87
	movl	-84(%rbp), %eax
	movl	%eax, %edi
	call	gai_strerror@PLT
	movq	%rax, %rsi
	movq	stderr(%rip), %rax
	movq	-112(%rbp), %rcx
	movq	-104(%rbp), %rdx
	movq	%rsi, %r8
	leaq	.LC17(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$-2, %eax
	jmp	.L96
.L87:
	movq	-80(%rbp), %rax
	movq	%rax, -72(%rbp)
	jmp	.L89
.L94:
	movq	-72(%rbp), %rax
	movl	12(%rax), %edx
	movq	-72(%rbp), %rax
	movl	8(%rax), %ecx
	movq	-72(%rbp), %rax
	movl	4(%rax), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	socket@PLT
	movl	%eax, -88(%rbp)
	cmpl	$0, -88(%rbp)
	js	.L98
	movq	-72(%rbp), %rax
	movl	16(%rax), %edx
	movq	-72(%rbp), %rax
	movq	24(%rax), %rcx
	movl	-88(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect@PLT
	cmpl	$-1, %eax
	jne	.L99
	movl	-88(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	testl	%eax, %eax
	jns	.L91
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	strerror@PLT
	movq	%rax, %rdx
	movq	stderr(%rip), %rax
	leaq	.LC18(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$-1, %eax
	jmp	.L96
.L98:
	nop
.L91:
	movq	-72(%rbp), %rax
	movq	40(%rax), %rax
	movq	%rax, -72(%rbp)
.L89:
	cmpq	$0, -72(%rbp)
	jne	.L94
	jmp	.L93
.L99:
	nop
.L93:
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	freeaddrinfo@PLT
	cmpq	$0, -72(%rbp)
	jne	.L95
	movl	$-1, %eax
	jmp	.L96
.L95:
	movl	-88(%rbp), %eax
.L96:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L97
	call	__stack_chk_fail@PLT
.L97:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE29:
	.size	open_clientfd, .-open_clientfd
	.section	.rodata
.LC19:
	.string	"Open_clientfd error"
	.text
	.globl	Open_clientfd
	.type	Open_clientfd, @function
Open_clientfd:
.LFB30:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	open_clientfd
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L101
	leaq	.LC19(%rip), %rdi
	call	unix_error
.L101:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE30:
	.size	Open_clientfd, .-Open_clientfd
	.section	.rodata
.LC20:
	.string	"Fclose error"
	.text
	.globl	Fclose
	.type	Fclose, @function
Fclose:
.LFB31:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	testl	%eax, %eax
	je	.L105
	leaq	.LC20(%rip), %rdi
	call	unix_error
.L105:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE31:
	.size	Fclose, .-Fclose
	.section	.rodata
.LC21:
	.string	"Fdopen error"
	.text
	.globl	Fdopen
	.type	Fdopen, @function
Fdopen:
.LFB32:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rdx
	movl	-20(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	fdopen@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L107
	leaq	.LC21(%rip), %rdi
	call	unix_error
.L107:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE32:
	.size	Fdopen, .-Fdopen
	.section	.rodata
.LC22:
	.string	"Fgets error"
	.text
	.globl	Fgets
	.type	Fgets, @function
Fgets:
.LFB33:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rdx
	movl	-28(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	fgets@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L110
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	ferror@PLT
	testl	%eax, %eax
	je	.L110
	leaq	.LC22(%rip), %rdi
	call	app_error
.L110:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE33:
	.size	Fgets, .-Fgets
	.section	.rodata
.LC23:
	.string	"Fopen error"
	.text
	.globl	Fopen
	.type	Fopen, @function
Fopen:
.LFB34:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L113
	leaq	.LC23(%rip), %rdi
	call	unix_error
.L113:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE34:
	.size	Fopen, .-Fopen
	.section	.rodata
.LC24:
	.string	"Fputs error"
	.text
	.globl	Fputs
	.type	Fputs, @function
Fputs:
.LFB35:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs@PLT
	cmpl	$-1, %eax
	jne	.L117
	leaq	.LC24(%rip), %rdi
	call	unix_error
.L117:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE35:
	.size	Fputs, .-Fputs
	.section	.rodata
.LC25:
	.string	"Fread error"
	.text
	.globl	Fread
	.type	Fread, @function
Fread:
.LFB36:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	fread@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	cmpq	-40(%rbp), %rax
	jnb	.L119
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	ferror@PLT
	testl	%eax, %eax
	je	.L119
	leaq	.LC25(%rip), %rdi
	call	unix_error
.L119:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE36:
	.size	Fread, .-Fread
	.section	.rodata
.LC26:
	.string	"Fwrite error"
	.text
	.globl	Fwrite
	.type	Fwrite, @function
Fwrite:
.LFB37:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	cmpq	%rax, -24(%rbp)
	jbe	.L123
	leaq	.LC26(%rip), %rdi
	call	unix_error
.L123:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE37:
	.size	Fwrite, .-Fwrite
	.section	.rodata
.LC27:
	.string	"Signal error"
	.text
	.globl	Signal
	.type	Signal, @function
Signal:
.LFB38:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$336, %rsp
	movl	%edi, -324(%rbp)
	movq	%rsi, -336(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-336(%rbp), %rax
	movq	%rax, -320(%rbp)
	leaq	-320(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	sigemptyset@PLT
	movl	$268435456, -184(%rbp)
	leaq	-160(%rbp), %rdx
	leaq	-320(%rbp), %rcx
	movl	-324(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	sigaction@PLT
	testl	%eax, %eax
	jns	.L125
	leaq	.LC27(%rip), %rdi
	call	unix_error
.L125:
	movq	-160(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L127
	call	__stack_chk_fail@PLT
.L127:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE38:
	.size	Signal, .-Signal
	.section	.rodata
.LC28:
	.string	"Select error"
	.text
	.globl	Select
	.type	Select, @function
Select:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	%r8, -56(%rbp)
	movq	-56(%rbp), %rdi
	movq	-48(%rbp), %rcx
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rsi
	movl	-20(%rbp), %eax
	movq	%rdi, %r8
	movl	%eax, %edi
	call	select@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L129
	leaq	.LC28(%rip), %rdi
	call	unix_error
.L129:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE39:
	.size	Select, .-Select
	.section	.rodata
.LC29:
	.string	"Pthread_create error"
	.text
	.globl	Pthread_create
	.type	Pthread_create, @function
Pthread_create:
.LFB40:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	pthread_create@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L133
	movl	-4(%rbp), %eax
	leaq	.LC29(%rip), %rsi
	movl	%eax, %edi
	call	posix_error
.L133:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE40:
	.size	Pthread_create, .-Pthread_create
	.section	.rodata
.LC30:
	.string	"Pthread_cancel error"
	.text
	.globl	Pthread_cancel
	.type	Pthread_cancel, @function
Pthread_cancel:
.LFB41:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	pthread_cancel@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L136
	movl	-4(%rbp), %eax
	leaq	.LC30(%rip), %rsi
	movl	%eax, %edi
	call	posix_error
.L136:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE41:
	.size	Pthread_cancel, .-Pthread_cancel
	.section	.rodata
.LC31:
	.string	"Pthread_join error"
	.text
	.globl	Pthread_join
	.type	Pthread_join, @function
Pthread_join:
.LFB42:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	pthread_join@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L139
	movl	-4(%rbp), %eax
	leaq	.LC31(%rip), %rsi
	movl	%eax, %edi
	call	posix_error
.L139:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE42:
	.size	Pthread_join, .-Pthread_join
	.section	.rodata
.LC32:
	.string	"Pthread_detach error"
	.text
	.globl	Pthread_detach
	.type	Pthread_detach, @function
Pthread_detach:
.LFB43:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	pthread_detach@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L142
	movl	-4(%rbp), %eax
	leaq	.LC32(%rip), %rsi
	movl	%eax, %edi
	call	posix_error
.L142:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE43:
	.size	Pthread_detach, .-Pthread_detach
	.globl	Pthread_exit
	.type	Pthread_exit, @function
Pthread_exit:
.LFB44:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE44:
	.size	Pthread_exit, .-Pthread_exit
	.globl	Pthread_self
	.type	Pthread_self, @function
Pthread_self:
.LFB45:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	pthread_self@PLT
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE45:
	.size	Pthread_self, .-Pthread_self
	.globl	Pthread_once
	.type	Pthread_once, @function
Pthread_once:
.LFB46:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	pthread_once@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE46:
	.size	Pthread_once, .-Pthread_once
	.section	.rodata
.LC33:
	.string	"Malloc error"
	.text
	.globl	Malloc
	.type	Malloc, @function
Malloc:
.LFB47:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L148
	leaq	.LC33(%rip), %rdi
	call	unix_error
.L148:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE47:
	.size	Malloc, .-Malloc
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
