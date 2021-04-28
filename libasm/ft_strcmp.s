    global _ft_strcmp
    section .text

_ft_strcmp :
    xor rax, rax
    xor r9, r9
    mov rcx, -1

loop :
    inc rcx
    mov al, BYTE[rdi + rcx]
    cmp al, BYTE[rsi + rcx]
    jne return
    cmp al, 0
    je return
    jmp loop

return :
    mov r9b, BYTE[rsi + rcx]
    sub rax, r9
    ret