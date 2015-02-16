section	.text

global	_ft_memset

_ft_memset:
	push	rdi
	mov		rax, rsi
	mov		rcx, rdx
	cld
rep	stosb

end:
	pop		rdi
	mov		rax, rdi
ret
