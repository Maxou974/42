	global ft_list_remove_if
	extern free
	section .text

	; Create the function ft_list_remove_if which removes from the list, all elements
	; whose data compared to data_ref using cmp, makes cmp return 0.

	; void ft_list_remove_if(t_list **begin_list, 
	;						 void *data_ref, 
	;						 int (*cmp)(), 
	;						 void (*free_fct)(void *));

	;	Function pointed by cmp and by free_fct will be used as follows :
	;		(*cmp)(list_ptr->data, data_ref);
	;		(*free_fct)(list_ptr->data);

	;	rdi: **list; rsi: *data; rdx: *cmp, rcx: *free

ft_list_remove_if:
	cmp rdi, 0
	je return

	push rbp
	mov rbp, rsp
	sub rsp, 40

	mov [rbp - 8], rsi ; store the *data
	mov [rbp - 16], rdx ; store the *cmp
	mov [rbp - 32], rcx	; store the *free
	mov [rbp - 40], rdi ; store the *next that we need to change 
	mov r9, [rdi]	; r9 store the head of the node that we need to compare

	push r12

compare:
	cmp r9, 0
	je return
	mov rdi, [r9]
	mov rsi, [rbp - 8]
	push r9
	call [rbp - 16]
	pop r9
	cmp rax, 0
	jz delete
	jmp move_next

delete:
	mov rdi, [r9]
	mov r12, r9
	add r12, 8
	mov r12, [r12]
	push r9
	call [rbp - 32]
	pop r9
	mov rdi, r9
	call free
	mov r9, r12
	mov r8, [rbp - 40]
	mov [r8], r9
	jmp compare

move_next:
	mov r8, r9
	add r8, 8
	mov [rbp - 40], r8
	mov r9, [r8]
	jmp compare

return:
	pop r12
	mov rsp, rbp
	pop rbp
	ret