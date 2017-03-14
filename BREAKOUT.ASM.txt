
	.model tiny
	.code
start:
	cli
;include variables
	mov ax,cs
	mov ds,ax

	mov ax,1234h		; debugger will stop when ax=1234
	mov ax,cs
	mov ds,ax			; allows us to get at variables
; --- YOUR CODE GOES HERE ---

;set up ES register to B800
	mov ax, 0b800h
	mov es, ax
	
;create ball at (40,10)
;((10x80) + 40) x 2 = 1680 + 1 = 691h
	mov si, ballx
	add si, bally
	mov al, 11h
	mov [es:si], al

;create a paddle ranging from (33,20) to (42, 20)
;((20x80) + 33) x 2 = 3266 +1 = cc3h
	mov dl, 1
	mov si, 3200
	add si, paddx
	mov al, 22h
paddle:	mov [es:si], al	
	add dl, 1
	cmp dl, 11
	jz blocks
	add si, 2
	jmp paddle

;create 20 blocks at (11, 3), (13,3), (15,3), ...
;((3x80) + 11) x 2 = 502 + 1 = 1f7h
blocks:	mov dl, 1
	mov bx, 1f3h
more:	mov si, bx
	add bx, 4
	mov al, 55h
	mov [es:si], al	
	add dl, 1
	cmp dl, 21
	jz game
	jmp more
game:

;if bally <= 0, balldy = -balldy
	mov ax, bally
	cmp ax, 0	
	jg topchecked
	mov dx, 0
	mov cx, balldy
	sub dx, cx
	mov balldy, dx
topchecked:
;if ballx <= 0, balldx = -balldx	
	mov ax, ballx
	cmp ax, 0
	jg leftchecked
	mov dx, 0
	mov cx, balldx
	sub dx, cx
	mov balldx, dx
leftchecked:
;if ballx >= 159, balldx = -balldx
	mov ax, ballx
	cmp ax, 159
	jl rightchecked
	mov dx, 0
	mov cx, balldx
	sub dx, cx
	mov balldx, dx
rightchecked:
;if bally >= 3840, return to DOS
	mov ax, bally
	cmp ax, 3840
	jl bottomchecked
	jmp exit
bottomchecked:

;get ball's current address
	mov si, bally
	add si, ballx
;set it's color to 0
	mov al, 0
	mov [es:si], al

;read ballx, balldx into registers, add them and save back into ballx
	mov ax, ballx
	mov bx, balldx
	add ax, bx
	mov ballx, ax

;do the same for bally, balldy
	mov ax, bally
	mov bx, balldy
	add ax, bx
	mov bally, ax

;get the ball's new address and set its color to 11h
	mov si, ballx
	add si, bally
	mov al, 11h
	mov [es:si], al

;after moving the ball, check the following
;is the ball moving downwards, is balldy>0
	mov ax, balldy
	cmp ax, 0
	jle continue
;is it at or past the top of the paddle, is bally>= 3040
	mov ax, bally
	cmp ax, 3040
	jl continue
;is ballx right of paddx, ballx >= paddx
	mov ax, ballx
	mov bx, paddx
	cmp ax, bx
	jl continue
;is ballx left of paddx+20, ballx <= paddx+20
	add bx, 20
	cmp ax, bx
	jg continue
;all of these are true, set balldy to -balldy
	mov ax, 0
	mov bx, balldy
	sub ax, bx
	mov balldy, ax
	
continue:
;delay for a while with a loop
	mov cx, 3000h
delay:	in al, 64h
	and al, 1
	jz finish
	in al, 60h
	cmp al, 4bh
	jz moveleft
	cmp al, 4dh
	jz moveright
	jmp clrbuf
finish:	sub cx, 1
	jnz delay

;go back to step 1 and repeat
	jmp game

moveleft:	mov ax, paddx
	sub ax, 2
	mov paddx, ax
	mov si, 3200
	add si, paddx
	mov al, 22h
	mov [es:si], al
	mov ax, paddx
	add ax, 20
	mov si, 3200
	add si, ax
	mov al, 0
	mov [es:si], al
	jmp finish	

moveright:	mov si, 3200
	add si, paddx
	mov al, 0
	mov [es:si], al
	add si, 20
	mov al, 22h
	mov [es:si], al
	mov ax, paddx
	add ax, 2
	mov paddx, ax
	jmp finish

clrbuf: 	in al, 60h
	jmp finish

;create variables
bally dw 1600
ballx dw 81
balldy dw 0ff60h
balldx dw 2
paddx dw 67

exit:
	mov ah,0			; ah=0 means exit to dos
	int 21h
	end
