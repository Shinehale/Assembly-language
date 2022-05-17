assume cs:code
code segment
	mov ax, 0
	mov ds, ax
	mov ds:[26h], ax

	mov ax, 4c00h
	int 21h
	;代码将引起DOS死机，因此不要向未知位置的地址写入数据
code ends
end