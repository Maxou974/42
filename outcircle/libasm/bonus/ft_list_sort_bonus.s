	global ft_list_sort
	extern ft_list_size
	section .text

ft_list_sort:
	push rdi
	push rsi
	mov rdi, [rdi]
	call ft_list_size
	pop rsi
	pop rdi
	mov rcx, rax		; rcx hold len of list
	cmp rcx, 1
	jle return

set_head:
	mov r8, [rdi]
	mov r9, [r8 + 8]
	jmp start_loop

inc_head:
	mov r8, [r8 + 8]	; r8 = head; r9 = head->next
	cmp qword [r8 + 8], 0
	je dec_rcx
	mov r9, [r9 + 8]

start_loop:
	push rdi
	push rsi
	push r8
	push r9
	push r9
	mov r10, rsi	; will hold the rsi function ptr
	mov rdi, [r8]
	mov rsi, [r9]
	call r10
	pop r9
	pop r9
	pop r8
	pop rsi
	pop rdi
	cmp rax, 0
	jg swap
	jmp inc_head

return:
	ret

dec_rcx:
	dec rcx
	cmp rcx, 0
	je return
	jmp set_head

swap:
	push r12
	mov r11, [r8]
	mov r12, [r9]
	mov [r8], r12
	mov [r9], r11
	pop r12
	jmp inc_head