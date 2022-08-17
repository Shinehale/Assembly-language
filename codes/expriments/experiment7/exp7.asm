assume ds: data, cs: code,ss: stack, es: table

data segment
	db '1975','1976','1977','1978','1979','1980','1981','1982','1983' 
	db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
	db '1993','1994','1995'
	; above are 21 strings for expressing the 21 years

	dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
	dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
	; above are 21 numbers for the sum of the income in 21 years

	dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
	dw 11542,14430,15257,17800
	; above are 21 numbers for the sum of the employees in 21 years
data ends

stack segment
	dw 0,0,0,0,0,0,0,0
stack ends

table segment 
	db 21 dup ('year summ ne ?? ')
table ends

code segment
start: 	mov ax, data
	mov ds, ax
	mov ax, stack
	mov sp, 16
	mov ax, table
	mov es, ax

	mov cx, 21
	mov bx, 0
	mov bp, 0

s:	push cx 

	mov cx, 4
	mov di, 0
	mov si, 0

s0: 	mov al, ds:[bp+si]
	mov es:[bx+di], al
	inc di
	inc si
	loop s0
	
	; the codes are for filling in the Year
	
	mov cx, 2
	mov di, 5
	mov si, 0

s1: 	mov ax, ds:84[bp+si]
	mov es:[bx+di], ax
	add di, 2
	add si, 2
	loop s1

	; the codes are for filling in the income

	add bx, 10h
	add bp, 4
	pop cx
	loop s
	; finished the first mission


	mov cx, 21
	mov bx, 0
	mov bp, 0

s2:	push cx
	mov si, 0
	mov di, 0ah
	mov ax, ds:168[bp+si]
	mov es:[bx+di], ax
	add bx, 10h
	add bp, 2
	pop cx
	loop s2

	; codes are for filling in the number of the employees

	mov cx, 21
	mov bx, 0

s3:	mov ax, es:[bx+5]
	mov dx, es:[bx+7]
	div word ptr es:[bx+0ah]
	mov es:[bx+0dh], ax
	add bx, 10h
	loop s3
	; codes are for filling in the average income


	mov ax, 4c00h
	int 21h

code ends
end start



	
