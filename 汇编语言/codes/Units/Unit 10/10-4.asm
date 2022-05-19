;计算data段中第一数据的3次方，结果保存在后面一组dword单元中
assume cs:code, ds:data

data segment
	dw 1,2,3,4,5,6,7,8
	dd 0,0,0,0,0,0,0,0
data ends

code segment
main:	mov ax, data
	mov ds, ax
	mov si, 0	;记录第一组数据
	mov di, 16	;记录第二组数据

	mov cx, 8
s:	mov bx, [si]
	call cube	
	mov [di], ax
	mov [di].2, dx
	add si, 2
	add di, 4
	loop s

	mov ax, 4c00h
	int 21h

cube:	mov ax, bx
	mul bx
	mul bx 
	ret	;完成cube功能结果存放在ax中


code ends
end main