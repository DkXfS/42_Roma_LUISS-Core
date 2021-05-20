    global  _ft_list_size
    section .text

_ft_list_size :
    xor rax, rax

count_loop :
    cmp rdi, 0
    jz return
    mov rdi, [rdi + 8]
    inc rax
    jmp count_loop

return :
    ret