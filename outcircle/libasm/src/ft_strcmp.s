	global ft_strcmp
	section .text

ft_strcmp:
	xor rcx, rcx				; rcx = 0; i = 0
	jmp start_loop
	
increment:
	inc rcx

start_loop:
	mov al, [rsi + rcx]			; tmp = src[i]
	cmp al, [rdi + rcx]			; compare tmp and dst[i]
	jnz return					; Jump if Not Zero to return

is_end_of_string:
	movzx r8, byte [rdi + rcx]			; r8 += dst[i]
	movzx r9, byte [rsi + rcx]			; r8 += src[i]
	add r8, r9
	cmp r8, 0					; compare r8 and 0
	jnz increment					; Jump if Not Zero to loop

return:
	movzx rax, byte [rdi + rcx]	; rax = dst[i]
	movzx r9, byte [rsi + rcx]	; r9 = src[i]
	sub rax, r9					; rax -= r9 (rax = dst[i] - src[i])
	ret
