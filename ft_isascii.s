section	.text

global _ft_isascii

_ft_isascii:
	mov		rax, 0
	cmp		rdi, 0
	jl		end
	cmp		rdi, 127
	jg		end
	mov		rax, 1

end:
ret
