section	.text

global	_ft_strcpy

_ft_strcpy:
	cmp		rdi, 0
	jz		nullptr
	cmp		rsi, 0
	jz		nullptr
	push	rdi
	push	rsi
	mov		rax, rdi

copy:
	cmp		BYTE [rsi], 0
	jz		return
	mov		r15b, [rsi]
	mov		[rdi], r15b
	inc		rdi
	inc		rsi
	jmp		copy

return:
	pop		rsi
	pop		rdi
	jmp		end

nullptr:
	mov		rax, 0

end:
ret
