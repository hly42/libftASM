section	.text

global	_ft_memcpy

_ft_memcpy:
	push	rdi
	push	rsi
	mov		rcx, rdx
	cld
rep	movsb

end:
	pop		rsi
	pop		rdi
	mov		rax, rdi
ret
