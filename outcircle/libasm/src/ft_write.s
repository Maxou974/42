	global ft_write
	extern __errno_location
	section .text
ft_write:
	mov rax, 1
	syscall
	cmp rax, 0
	jge return
	mov r8, rax
	neg r8
	call __errno_location wrt ..plt
	mov [rax], r8
	mov rax, -1

return:
	ret