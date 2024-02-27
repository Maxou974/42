	global ft_strcpy
	section .text
ft_strcpy:
	xor rcx, rcx				; rcx = 0; i = 0
	cmp rsi, 0					; compare rsi with 0; src == 0
	jz return					; Jump if Zero to return label

loop:							; rsi is src  rdi is dst
	mov al, [rsi + rcx] 		; tmp = src[i]
	mov byte [rdi + rcx], al	; dst = tmp
	inc rcx						; i++
	cmp al, 0					; compare tmp with 0
	jnz loop					; Jump if Not Zero to loop label

return:	
	mov rax, rdi				; rax = rdi; return dst
	ret							; pop rip