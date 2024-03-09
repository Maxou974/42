	extern malloc
	extern ft_strlen
	extern ft_strcpy
	global ft_strdup
	section .text

ft_strdup:
	call ft_strlen		; rax = strlen(rdi) len of src
	push rdi			; save rdi wich is the src of strdup
	mov rdi, rax		; put in rdi the len of src
	inc rdi				; inc the len of src for NULL byte
	call malloc	wrt ..plt		; rax = 0 if malloc failed, adress otherwise
	cmp rax, 0			
	jz return			; Jump if Zero to return (malloc failed)
	mov rdi, rax		; rdi = adress from malloc
	pop rsi				; rsi = src ptr
	call ft_strcpy		; 

return:
	ret