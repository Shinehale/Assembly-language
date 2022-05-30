;实验11 编写子程序
;
;编写一个子程序，将包含任意字符，以0结尾的字符串中的
;小写字母转变成大写字母。
;
;a-z对应的ASCII码为97-122
;A-Z对应的ASCII码为65-90
;小写转大写：与 1101 1111B
;大写转小写：或 0010 0000B
assume cs:codesg, ds:codesg
datasg segment 
	db "Beginner's All-purpose Symbolic Instruction Code.", 0
datasg ends

codesg segment
begin:
	mov ax, datasg
	mov ds, ax
	mov si, 0
	call letterc
	
	;打印被修改的字符串
	mov dh, 1	;第一行
	mov dl, 0	;第零列
	mov cl, 2	;字体颜色
	call show_str
	
	mov ax, 4c00h
	int 21h

letterc:
	push ax
	push si
iterator:
	mov al, ds:[si]
	;如果al==0
	cmp al, 0
	je letterc_ok
	;如果al<97
	cmp al, 97
	jb incsi
	;如果al>122
	cmp al, 122
	ja incsi
	;如果97<=al<=122
	and al, 11011111B
	mov ds:[si], al
incsi:
	inc si
	jmp short iterator
	
letterc_ok:	
	pop si
	pop ax
	ret

show_str:
	push ax
	push cx
	push dx
	push es
	push si
	push bp
	
	;使用es:bp指向目标显存首地址
	mov ax, 0b800h
	mov es, ax
	
	;计算bp的初值
	mov ax, 160
	mul dh
	mov dh, 0
	add ax, dx
	add ax, dx
	mov bp, ax
	
copy:
	;复制一个字母
	mov al, ds:[si]
	;判断是否是字符串尾部,此处要用到cx，因为cx已被使用，所以要先备份cx
	mov dx, cx
	mov ch, 0
	mov cl, al
	jcxz ok
	mov cx, dx
	;粘贴一个字母
	mov byte ptr es:[bp],al
	;粘贴字母属性
	mov byte ptr es:[bp+1], cl
	add si, 1
	add bp, 2
	jmp short copy
	
ok: 
	pop bp
	pop si
	pop es
	pop dx
	pop cx
	pop ax
	
	ret
	
;=================================================================
codesg ends
end begin