	.file	"shell.c"
	.text
	.globl	PATH
	.data
	.align 32
	.type	PATH, @object
	.size	PATH, 62
PATH:
	.string	"/usr/bin/:/usr/local/bin/:/bin/:/usr/local/games/:/usr/games/"
	.text
	.globl	change_dir
	.type	change_dir, @function
change_dir:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	chdir@PLT
	movq	-16(%rbp), %rax
	movl	$128, %esi
	movq	%rax, %rdi
	call	getcwd@PLT
	movq	-24(%rbp), %rax
	movl	$1, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	change_dir, .-change_dir
	.globl	is_file_exist
	.type	is_file_exist, @function
is_file_exist:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$64, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
	movq	-32(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat@PLT
	movq	-8(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	testl	%eax, %eax
	js	.L4
	movq	-8(%rbp), %rax
	jmp	.L5
.L4:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %eax
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	is_file_exist, .-is_file_exist
	.section	.rodata
.LC0:
	.string	">"
.LC1:
	.string	":"
.LC2:
	.string	"<"
	.text
	.globl	redirection
	.type	redirection, @function
redirection:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1072, %rsp
	movq	%rdi, -1064(%rbp)
	movl	%esi, -1068(%rbp)
	movl	$0, -4(%rbp)
	leaq	PATH(%rip), %rax
	movq	%rax, -16(%rbp)
	movq	$0, -24(%rbp)
	jmp	.L7
.L19:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-1064(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movq	%rdx, -1056(%rbp,%rax,8)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-1064(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L8
	movl	-4(%rbp), %eax
	cltq
	movq	$0, -1056(%rbp,%rax,8)
	leaq	.LC1(%rip), %rsi
	leaq	PATH(%rip), %rdi
	call	strtok@PLT
	movq	%rax, -16(%rbp)
	jmp	.L9
.L12:
	movq	-1064(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	is_file_exist
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L21
	leaq	.LC1(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -16(%rbp)
.L9:
	cmpq	$0, -16(%rbp)
	jne	.L12
	jmp	.L11
.L21:
	nop
.L11:
	movl	-4(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,8), %rdx
	movq	-1064(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	creat@PLT
	movl	%eax, -28(%rbp)
	movl	$1, %edi
	call	close@PLT
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	call	dup@PLT
	leaq	-1056(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	execv@PLT
	jmp	.L13
.L8:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-1064(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L14
	movl	-4(%rbp), %eax
	cltq
	movq	$0, -1056(%rbp,%rax,8)
	leaq	.LC1(%rip), %rsi
	leaq	PATH(%rip), %rdi
	call	strtok@PLT
	movq	%rax, -16(%rbp)
	jmp	.L15
.L18:
	movq	-1064(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	is_file_exist
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L22
	leaq	.LC1(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -16(%rbp)
.L15:
	cmpq	$0, -16(%rbp)
	jne	.L18
	jmp	.L17
.L22:
	nop
.L17:
	movl	-4(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,8), %rdx
	movq	-1064(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -28(%rbp)
	movl	$0, %edi
	call	close@PLT
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	call	dup@PLT
	leaq	-1056(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	execv@PLT
	jmp	.L13
.L14:
	addl	$1, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	cmpl	-1068(%rbp), %eax
	jl	.L19
.L13:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	redirection, .-redirection
	.section	.rodata
.LC3:
	.string	"="
.LC4:
	.string	"token in PS1 : %s\n"
.LC5:
	.string	"PS1"
.LC6:
	.string	""
.LC7:
	.string	"\"\\w$\""
.LC8:
	.string	" "
	.text
	.globl	extract_input
	.type	extract_input, @function
extract_input:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%rcx, -80(%rbp)
	movq	-56(%rbp), %rax
	addq	$3, %rax
	movzbl	(%rax), %eax
	cmpb	$61, %al
	jne	.L24
	movq	-56(%rbp), %rax
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L25
	leaq	.LC6(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	leaq	.LC7(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L26
	movq	-72(%rbp), %rax
	movl	$0, (%rax)
	jmp	.L25
.L26:
	movq	-72(%rbp), %rax
	movl	$1, (%rax)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -32(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L27
.L28:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	addl	$1, -12(%rbp)
.L27:
	movl	-12(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L28
.L25:
	addq	$1, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-8(%rbp), %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
.L24:
	movl	$1024, %edi
	call	malloc@PLT
	movq	%rax, -40(%rbp)
	movq	-56(%rbp), %rax
	leaq	.LC8(%rip), %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -24(%rbp)
	movl	$0, -28(%rbp)
	jmp	.L29
.L30:
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rax, (%rdx)
	leaq	.LC8(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -24(%rbp)
	addl	$1, -28(%rbp)
.L29:
	cmpq	$0, -24(%rbp)
	jne	.L30
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	$0, (%rax)
	movq	-80(%rbp), %rax
	movl	-28(%rbp), %edx
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-40(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	extract_input, .-extract_input
	.section	.rodata
.LC9:
	.string	"\033[0;33m"
.LC10:
	.string	" %s $ "
.LC11:
	.string	"\033[0m"
.LC12:
	.string	"\n"
.LC13:
	.string	"exit"
.LC14:
	.string	"cd"
	.text
	.globl	main
	.type	main, @function
main:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$320, %rsp
	movl	$0, -308(%rbp)
	movl	$0, -312(%rbp)
	movl	$0, -316(%rbp)
	movl	$128, %edi
	call	malloc@PLT
	movq	%rax, -24(%rbp)
	movq	$0, -8(%rbp)
	movq	$0, -16(%rbp)
.L46:
	movl	-312(%rbp), %eax
	testl	%eax, %eax
	jne	.L33
	movl	-316(%rbp), %eax
	testl	%eax, %eax
	jne	.L34
.L33:
	movl	-312(%rbp), %eax
	testl	%eax, %eax
	je	.L35
	movl	-316(%rbp), %eax
	testl	%eax, %eax
	je	.L34
.L35:
	movl	-312(%rbp), %eax
	testl	%eax, %eax
	jne	.L36
	movl	-316(%rbp), %eax
	testl	%eax, %eax
	jne	.L36
.L34:
	leaq	-304(%rbp), %rax
	movl	$128, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	leaq	-304(%rbp), %rax
	movl	$128, %esi
	movq	%rax, %rdi
	call	getcwd@PLT
.L36:
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-304(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	stdin(%rip), %rdx
	leaq	-176(%rbp), %rax
	movl	$128, %esi
	movq	%rax, %rdi
	call	fgets@PLT
	leaq	-176(%rbp), %rax
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	strcspn@PLT
	movb	$0, -176(%rbp,%rax)
	leaq	-308(%rbp), %rcx
	leaq	-312(%rbp), %rdx
	leaq	-304(%rbp), %rsi
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	extract_input
	movq	%rax, -32(%rbp)
	movl	-308(%rbp), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	redirection
	leaq	.LC1(%rip), %rsi
	leaq	PATH(%rip), %rdi
	call	strtok@PLT
	movq	%rax, -16(%rbp)
	jmp	.L37
.L40:
	movq	-32(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	is_file_exist
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L48
	leaq	.LC1(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -16(%rbp)
.L37:
	cmpq	$0, -16(%rbp)
	jne	.L40
	jmp	.L39
.L48:
	nop
.L39:
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L41
	movl	$0, %eax
	jmp	.L47
.L41:
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L43
	leaq	-316(%rbp), %rdx
	leaq	-304(%rbp), %rcx
	movq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	change_dir
.L43:
	call	fork@PLT
	movl	%eax, -36(%rbp)
	cmpl	$0, -36(%rbp)
	jne	.L44
	movq	-32(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	execv@PLT
	jmp	.L46
.L44:
	leaq	-176(%rbp), %rax
	movl	$128, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movl	$0, %edi
	call	wait@PLT
	jmp	.L46
.L47:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	main, .-main
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
