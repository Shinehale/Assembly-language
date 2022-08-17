;名称：show_str
;功能：在指定的位置,用指定的颜色,显示一个以0结尾的字符串
;参数：(dh) = 行号(取值范围0~24), (dl) = 列号(取值范围0~79)
;      (cl) = 颜色, ds:si 指向字符串的首地址
;返回：无
;应用举例: 在屏幕的8行3列，用绿色显示data段中的字符串
assume cs:code, ds: data

data segment
	db 'Welcome to masm! This program is produced by Shine_hale',0
data ends

code segment
main:	mov dh, 8
	mov dl, 3
	mov cl, 11011111B
	mov ax, data
	mov ds, ax
	mov si, 0
	call show_str

	mov ax, 4c00h
	int 21h

show_str:
	push ax
	push es
	push di
	push cx 		;将用到的寄存器缓存

	mov ax, 0b800h
	mov es, ax
	mov al, 160
	mul dh
	mov bx, ax
	mov al, 2
	mul dl
	add bx, ax
	mov di, bx 	;完成计算显示开始的位置 es:[di]

	mov bl, cl 	;将cl颜色转移到bl中

	mov cx, 128
for_show:
	push cx
	mov cl, ds:[si]
	mov ch, 0
	jcxz over_show
	mov es:[di], cx
	mov es:[di+1], bl
	add di, 2
	add si, 1
	pop cx
	loop for_show


over_show:
	pop cx
	pop cx
	pop di
	pop es 
	pop ax 		;将用完的寄存器数据还原
	ret


code ends
end main