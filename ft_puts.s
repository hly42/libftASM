section	.data
newline db	10					;ascii value of the newline character
null	db	"(null)"

section	.text

extern	_ft_strlen

global	_ft_puts

_ft_puts:
	call	_ft_strlen
	cmp		rax, 0				;check string's length
	jz		nullstr
	mov		rdx, rax			;string's length
	mov		rsi, rdi			;string
	mov		rdi, 1				;stdout
	mov		rax, 0x2000004		;syscall write
	syscall
	cmp		rax, 0				;check write return value
	jl		error

appendNewline:
	mov		rdi, 1				;stdout
	lea		rsi, [rel newline]	;string
	mov		rdx, 1				;string's length
	mov		rax, 0x2000004		;syscall write
	syscall
	cmp		rax, 0				;check write return value
	jl		error
	mov		rax, 1				;set return value
	jmp		end

error:
	mov		rax, -1				;set return value
	jmp		end

nullstr:
	mov		rdi, 1				;stdout
	lea		rsi, [rel null]		;string
	mov		rdx, 6				;string's length
	mov		rax, 0x2000004		;syscall write
	syscall
	cmp		rax, 0				;check write return value
	jl		error
	jmp		appendNewline

end:
ret
