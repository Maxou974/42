	global ft_strlen
	section .text
ft_strlen:
		xor rax, rax			; rax = 0; i = 0

start_loop:
		cmp BYTE [rdi + rax], 0	; src[i] == 0
		jz return				; Jump if Zero to return
		inc rax					; i++
		jmp start_loop			; jump to start_loop

return:
		ret