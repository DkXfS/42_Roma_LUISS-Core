global _ft_strdup
extern ___error
extern _malloc
extern _ft_strcpy
extern _ft_strlen

section .text

_ft_strdup :
    call _ft_strlen
    inc rax
    push rdi
    mov rdi, rax
    call _malloc
    cmp rax, 0
    jz malloc_err
    mov rdi, rax
    pop rsi
    call _ft_strcpy
    ret

malloc_err :
    call ___error
    mov r9, 12
    mov [rax], r9
    mov rax, 0
    ret