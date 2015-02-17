section	.text

global	_ft_strcpy

_ft_strcpy:
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

end:
ret
