section	.text

global _ft_isprint

_ft_isprint:
	mov		rax, 0
	cmp		rdi, ' '
	jl		end
	cmp		rdi, '~'
	jg		end
	mov		rax, 1

end:
ret
