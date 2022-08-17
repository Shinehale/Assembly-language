; 名称：dtoc
; 功能：将word型数据转换成表示十进制数的字符串，字符串以0位结束符
; 参数：(ax) = word型数据 ds:si 指向字符串的首地址
; 返回： 无
; 应用举例: 将12666以十进制的形式在屏幕的8行3列，用绿色显示出来
assume cs:code, ds:data, ss:stack
data segment
	db 32 dup (0)
data ends

stack segment
	db 64 dup (0)
stack ends

code segment
main:	mov ax, data
	mov ds, ax 	;初始化数据段
	mov si, 0
	mov ax, stack
	mov ss, ax 	
	mov sp, 64 	;初始化栈段

	mov ax, 52666
	mov dx, 41236 	;注意这里不是简单的叠加关系，而是(dx)*65536+(ax)

	call dtoc
	mov dh, 8
	mov dl, 3
	mov cl, 10101001B
	call show_str

	mov ax, 4c00h
	int 21h


dtoc:	
	push cx 
	push bx 
	mov cx, 32
	mov bx, 0
s_dtoc1:
	push cx
	mov cx, ax
	jcxz dtoc_over 
	mov cx, 0ah
	call divdw
	mov byte ptr ds:[bx], cl 	;将本次得到的余数放入data中
	inc bx 
	pop cx 
	loop s_dtoc1

dtoc_over:
	pop cx
	pop bx
	pop cx
	ret


;利用下述程序完成%10运算并且将结果放入data段中
divdw:	
	push bx 
	push bp 		;缓存用到的寄存器

	mov bp, cx 	;这样做感觉会有风险
	mov cx, 8
	mov bx, 0
s_divdw1:	
	push word ptr ds:[bx]
	add bx, 2
	loop s_divdw1 		;将用到的存储空间缓存

	mov cx, bp
	mov ds:[0], ax 	;ds:[0]存储原来被除数低16位
	mov ds:[2], dx 	;ds:[0]存储原来被除数高16位
	mov ds:[4], cx 	;ds:[0]存储原来除数

	mov ax, ds:[2]
	mov dx, 0
	div cx
	mov ds:[6], ax 	;ds:[6]存储int(H/N)
	mov ds:[8], dx 	;ds:[8]存储rem(H/N)

	mov dx, ds:[8]
	mov ax, ds:[0]
	div cx

	mov cx, dx 	;将余数放入cx中
	mov dx, ds:[6]	;将结果高16位放入dx中，而结果中低16位就是除法得到的结果


	mov bp, cx
	mov bx, 14
	mov cx, 8
s_over:	pop word ptr ds:[bx]
	add bx, -2
	loop s_over
	mov cx, bp
	
	pop bp
	pop bx 		;释放原来的数据
	ret


; 展示字符串

show_str:
	push si
	push bx
	push ax
	push es
	push di
	push bp
	push cx 		;将用到的寄存器缓存

	mov bp, cx

	mov bx, 12
s_reverse1:
	dec bx 
	mov cx, ds:[bx]
	jcxz s_reverse1
			;完成这样的步骤后就是字符串长度

	inc bx 
	mov cx, bx
	mov bx, 0
s_reverse:
	mov al, ds:[bx]
	mov ah, 0
	inc bx 
	push ax
	loop s_reverse

	mov cx, bx
	mov es, cx 	;将长度暂存至es中
	mov bx, 0
s_reverse0:
	pop ax
	mov ds:[bx], al
	inc bx 
	loop s_reverse0  		;完成字符串的反转

	mov cx, bp

	
	mov al, 160
	mul dh
	mov bx, ax
	mov al, 2
	mul dl
	add bx, ax
	mov di, bx 	

	mov bl, cl 	;将cl颜色转移到bl中

	mov cx, es 	;将长度返回给cx

	mov ax, 0b800h
	mov es, ax 	;完成计算显示开始的位置 es:[di]
s_show1:
	mov al, ds:[si]
	add al, 30h
	mov es:[di], al
	mov es:[di+1], bl
	add di, 2
	add si, 1
	loop s_show1


s_show_back:
	pop cx
	pop bp
	pop di
	pop es 
	pop ax 		
	pop bx
	pop si 		;将用完的寄存器数据还原
	ret



code ends

end main