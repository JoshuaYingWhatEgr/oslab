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
    !设置字符串