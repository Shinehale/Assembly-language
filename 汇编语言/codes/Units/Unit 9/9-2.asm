;段内短转移
assume cs:code
code segment
start:	mov ax, 0
	jmp short s
	add ax, 3
s:	inc ax
code ends
end start