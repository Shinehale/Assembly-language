;检测点10-2
assume cs:code
code segment
start:	mov ax, 0
	call s
	inc ax 
s:	pop ax

	mov ax, 4c00h
	int 21h
code ends
end start