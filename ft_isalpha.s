section	.text

global _ft_isalpha

_ft_isalpha:
	mov		rax, 0

if:
	cmp		rdi, 'a'
	jl		else
	cmp		rdi, 'z'
	jg		end
	mov		rax, 1
	jmp		end

else:
	cmp		rdi, 'A'
	jl		end
	cmp		rdi, 'Z'
	jg		end
	mov		rax, 1

end:
ret
