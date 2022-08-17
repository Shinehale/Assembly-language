; 段间远转移
assume cs:codeseg
codeseg segment
start:	mov ax, 0
	mov bx, 0
	jmp far ptr s
	db 256 dup (0)
s:	add ax, 1
	inc ax
codeseg ends
end start