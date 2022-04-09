entry _start
_start:
    !获取光标位置
    mov ah,#0x03
    !bh设置为0
    xor bh,bh
    int 0x10

    !显示字符串"hello os world, my name is jx"
    !要显示的字符串的长度
    mov cx,#36
    mov bx,#0x0007
    !设置字符串的地址以后要用bp
    mov bp,#msg1

    mov ax,#0x07c0
    !es:bp 显示字符串的地址
    mov es,ax
    mov ax,#0x1301
    int 0x10

    !设置无限循环
inf_loop:    