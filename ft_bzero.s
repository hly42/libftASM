section .text

global	_ft_bzero

_ft_bzero:
	push	rdi

loop:
	cmp		rsi, 0
	jz		end
	dec		rsi
	mov		BYTE [rdi], 0
	inc		rdi
	jmp		loop

end:
	pop		rdi
ret
