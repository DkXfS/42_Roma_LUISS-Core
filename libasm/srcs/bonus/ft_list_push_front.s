;    void ft_list_push_front(t_list **begin_list, void *data)

global  _ft_list_push_front
extern ___error
extern _malloc
section .text

_ft_list_push_front :
    cmp [rdi], 0
    je empty_list
    mov rdx, [rdi]

put_elem :
    push rdi
    push rsi
    push rdx
    mov rdi, 16
    xor rax, rax
    call _malloc
    cmp rax, 0
    jz malloc_err
    pop rdx
    pop rsi
    pop rdi
    mov [rdi], rax
    mov [rax], BYTE rsi
    mov [rax + 8], BYTE rdx
    xor rax, rax
    ret

empty_list :
    mov rdx, 0
    jmp put_elem

malloc_err :
    call ___error
    mov r9, 12
    mov [rax], r9
    mov rax, 0
    ret