section	.data
	bufferSize	equ 4096

section	.bss
	content		resb bufferSize

section	.text

global	_ft_cat

extern	_ft_strlen

_ft_cat:
	mov		r15, rdi

read:
	mov		rdi, r15
	lea		rsi, [rel content]
	mov		rdx, bufferSize
	mov		rax, 0x2000003		;read
	syscall
	cmp		rax, 0
	jz		end

print:
	lea		rdi, [rel content]
	call	_ft_strlen
	mov		rdi, 1
	lea		rsi, [rel content]
	mov		rdx, rax
	mov		rax, 0x2000004		;write
	syscall
	cmp		rax, 0
	jl		end
	jmp		read

end:
	mov		rdi, r15
	mov		rax, 0x2000006		;close
ret
