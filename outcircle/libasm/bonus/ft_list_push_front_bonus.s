	global ft_list_push_front
	extern malloc
	section .text

ft_list_push_front:
	push rsp
	push rdi
	push rsi
	mov rdi, 0x10
	call malloc		; malloc 16B
	pop rsi
	pop rdi
	cmp rax, 0
	jz return
	mov [rax], rsi	; put *data in new element
	mov qword [rax + 8], 0

	cmp qword [rdi], 0
	jz	set_new_list
	jmp append_front

set_new_list:
	mov [rdi], rax
	jmp return

append_front:
	mov r8, [rdi]
	mov [rax + 8], r8
	mov [rdi], rax

return:
	pop rsp
	ret