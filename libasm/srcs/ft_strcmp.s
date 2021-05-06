    global _ft_strcmp
    section .text

_ft_strcmp :
    xor rax, rax
    mov rcx, -1

loop :
    inc rcx
    mov al, BYTE[rdi + rcx]
    cmp al, BYTE[rsi + rcx]
    ja return_1
    jb return_neg1
    cmp al, 0
    jz return_0
    jmp loop

return_1:
    mov rax, 1
    ret

return_neg1:
    mov rax, -1
    ret

return_0:
    mov rax, 0
    ret