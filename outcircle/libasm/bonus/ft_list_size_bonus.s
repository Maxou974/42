	global ft_list_size
	section .text

ft_list_size:
	xor rax, rax	; 8B for *data, 8B for *next

counter_loop:
	cmp rdi, 0
	jz return
	mov rdi, [rdi + 8]
	inc rax
	jmp counter_loop

return:
	ret