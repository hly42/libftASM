section	.text

extern	_ft_isalpha
extern	_ft_isdigit

global	_ft_isalnum

_ft_isalnum:
	call	_ft_isdigit
	cmp		rax, 1
	jz		end
	call	_ft_isalpha

end:
ret
