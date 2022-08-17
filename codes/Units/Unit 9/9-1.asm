;correspond to problem 9-1
assume cs:code
code segment
start:	mov ax, bx
	mov si, offset start
	mov di, offset s0
	mov ax, cs:[si]
	mov cs:[di], ax

s0:	nop ; seize a position of one byte
	nop

	mov ax, 4c00h
	int 21h
code ends
end start