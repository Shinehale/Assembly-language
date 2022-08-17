assume cs: code
code segment
	mov ax, 1000h
	mov ss, ax

	mov sp, 0010h

	push ax
	push bx 
	push ds

	mov ax, 4c00h
	int 21h
code ends
end