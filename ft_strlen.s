section .text

global	_ft_strlen

_ft_strlen:
		push	rdi
		push	rcx			;save rcx value using the stack
		xor		rcx, rcx	;put rcx to zero
		xor		rax, rax	;put rax to zero
		not		rcx			;set rcx to the highest value possible
		cld					;set direction flag to 0
repne	scasb				;cmp each byte of the argument to the value in AL(rax)
		not		rcx
		dec		rcx
		mov		rax, rcx

return:
		pop		rcx			;restore rcx value
		pop		rdi

end:
ret
