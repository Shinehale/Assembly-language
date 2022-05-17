assume cs: code
code segment 
	mov ax, 1000h
	mov ds, ax
	mov ax, 2266h
	mov ds:[0], ax  ; 初始条件

	mov ax, 4c00h
	int 21h
code ends
end