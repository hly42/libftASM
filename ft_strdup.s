section	.text

extern	_malloc
extern	_ft_strlen
extern	_ft_memcpy

global	_ft_strdup

_ft_strdup:
	push	rdi
	call	_ft_strlen
	cmp		rax, 0
	jz		allocateMem
	inc		rax

allocateMem:
	push	rax
	mov		rdi, rax
	call 	_malloc
	cmp		rax, 0
	jz		error
	mov		rdi, rax
	add		rsp, 8
	pop		rsi
	sub		rsp, 16
	pop		rdx
	call	_ft_memcpy
	jmp		end

error:
	add		rsp, 8
	mov		rax, 0

end:
	pop		rdi

ret
