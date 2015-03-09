section	.text

global	_ft_strcat

_ft_strcat:
	push	rdi
	push	rsi
	push	r15
	mov		rax, rdi

endOfString:
	cmp		BYTE [rdi], 0
	jz		copy
	inc		rdi
	jmp		endOfString

copy:
	cmp		BYTE [rsi], 0
	jz		return
	mov		r15, [rsi]
	mov		[rdi], r15b
	inc		rdi
	inc		rsi
	jmp		copy

return:
	mov		BYTE [rdi], 0
	pop		r15
	pop		rsi
	pop		rdi

end:

ret
