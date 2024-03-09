	global ft_atoi_base
	extern ft_strlen
	section .text

ft_atoi_base:
	push r12
	push r13
	push r14
	push r15

	xor rcx, rcx
	xor rax, rax
	xor r8, r8
	xor r9, r9
	xor r10, r10
	xor r11, r11
	xor r12, r12
	xor r13, r13
	xor r14, r14
	xor r15, r15
	cmp rsi, 0
	jz error
	cmp rdi, 0
	jz error
check_base:    ; check if unique and if len >= 2; r8 is i and r9 is j; r10 is srtlen(base); r11 is tmp
	push rdi		; save rdi
	mov rdi, rsi	; put base in rdi to call strlen
	call ft_strlen	; 
	mov r10, rax	; r10 = return of strlen
	pop rdi			; restore rdi to src
	cmp r10, 2
	jl error		; if len < 2 jmp to error

check_base_dup_incr:
	inc r9
	cmp r10, r9				;	j == len(base);
	jne check_base_duplicate; 	j != len jump to check; else
	inc r8					;		i++
	mov r11, r8				;	tmp = i
	inc r11					;	tmp = i + 1
	mov r9, r11				;		j = tmp = i + 1
	cmp r9, r10				;	if j == len(base) again it means everything as been checked
	je check_base_space		;

check_base_duplicate:
	mov r11b, [rsi + r8]
	cmp r11b, [rsi + r9]
	je error
	jmp check_base_dup_incr
	
check_base_space: ; r10 is still len(base), r8 is len(base) - 1
	cmp byte [rsi + r8], 9		; '\t'
	je error
	cmp byte [rsi + r8], 10		; '\n'
	je error
	cmp byte [rsi + r8], 11		; '\v'
	je error
	cmp byte [rsi + r8], 12		; '\f'
	je error
	cmp byte [rsi + r8], 13		; '\r'
	je error
	cmp byte [rsi + r8], 32		; ' '
	je error
	cmp byte [rsi + r8], 43		; '+'
	je error
	cmp byte [rsi + r8], 45		; '-'
	je error
	dec r8
	cmp r8, -1
	jne check_base_space

skip_src_space_incr:
	inc r8
skip_src_space: ; r8 is i
	cmp byte [rdi + r8], 9		; '\t'
	je skip_src_space_incr
	cmp byte [rdi + r8], 10		; '\n'
	je skip_src_space_incr
	cmp byte [rdi + r8], 11		; '\v'
	je skip_src_space_incr
	cmp byte [rdi + r8], 12		; '\f'
	je skip_src_space_incr
	cmp byte [rdi + r8], 13		; '\r'
	je skip_src_space_incr
	cmp byte [rdi + r8], 32		; ' '
	je skip_src_space_incr
	cmp byte [rdi + r8], 0		; '\0'
	je error

	jmp check_sign

skip_sign_incr:
	inc r8
check_sign:
	cmp byte [rdi + r8], 43		; '+'
	je skip_sign_incr
	cmp byte [rdi + r8], 45		; '-'
	je incr_negative

	jmp continue

incr_negative:
	inc r15
	jmp skip_sign_incr

continue:
	mov r9, r8  			; j = i
get_r9_to_src_end:
	cmp byte [rdi + r9], 0
	je init_loop

	xor rcx, rcx
weif:
	cmp byte [rsi + rcx], 0
	je init_loop
	push r9
	mov r9b, [rdi + r9]
	cmp byte [rsi + rcx], r9b
	pop r9
	je incr_r9_to_end
	inc rcx
	jmp weif

incr_r9_to_end:
	inc r9
	jmp get_r9_to_src_end

init_loop:
	sub r9, r8; ; r9(index of '\0') - r8 = len of the number r9=3 if "+321"

find_index_set:
	dec r9 ; 	("+653" r9 = 2 cause six is base power of 2)
	xor rcx, rcx	; rcx is counter to find occurence in base
	mov r12b, [rdi + r8]		; r12 = src[i]
find_index_in_base:
	cmp byte [rsi + rcx], 0     ; we did not find in base
	je error
	cmp [rsi + rcx], r12b	; base[j] == src[i]
	je index_found
	inc rcx
	jmp find_index_in_base 
					; in n x base^rank,
index_found:		; r11 is n, r9 is rank, and base is len(base) wich is r10
 	mov r11, rcx	; rcx holds the index in base wich is n in the calculus
	mov rcx, r9		; we put r9 in rcx, cause rcx will count the power_loop
	jmp to_power
after_power:		; after to_power rax, hold the base^rank 
	mul r11			; mul r11 equivalent to rax *= r11 so rax hold the result for the actual rank
	add r14, rax	; r14 will hold the full sum
	inc r8			
	cmp byte [rdi + r8], 0	; check if end of string
	jne find_index_set		; if not repeat with r8++
	je set_rax				; else set rax

error:
	; mov rax, 0
	jmp set_rax

negate_rax:
	neg rax
	jmp return

set_rax:
	mov rax, r14	; r14 was holding the hole sum
	and r15, 1 
	cmp r15, 1		; r15 = 1 negative; r15 = 0 positive;
	je negate_rax

return:
	pop r15
	pop r14
	pop r13
	pop r12
	ret

to_power: ; rcx is the number of power
	cmp rcx, 0
	je set_rax_1
	xor rax, rax
	mov rax, r10;
to_power_bis:
	dec rcx
	cmp rcx, 0
	je 	after_power		; find continue
	mul r10
	jmp to_power_bis
set_rax_1:
	mov rax, 1
	je 	after_power		; find continue


