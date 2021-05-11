;    void ft_list_sort(t_list **begin_list, int (*cmp)());
;                           r11                 r13
;       rcx = current start element
;       r10 = current min element
;       r9  = loop element
;       r8  = temp reg

global _ft_list_sort

_ft_list_sort :
    push r13
    mov r10, [rdi]
    mov r11, rdi
    mov r13, rsi
    cmp r10, 0
    jz return
    mov rcx, r10
    mov r9, [r11 + 8]
    xor rdi, rdi
    mov rdi, [rcx]
    jmp compare

loop :
    mov r8, [r9 + 8]
    mov r9, [r8]
    cmp r9, 0
    jz swap
    jmp compare

compare :
    mov rsi, [r9]
    push rcx
    push r9
    call r13
    pop r9
    pop rcx
    cmp rax, 0
    jg new_min
    jmp loop

new_min :
    mov r10, r9
    jmp loop

swap :
    mov r8, [rcx]
    mov rdx, [r10]
    mov [rcx], rdx
    mov [r10], r8
    mov rcx, [rcx + 8]
    cmp rcx, 0
    jz return
    mov r9, rcx
    mov rdi, [rcx]
    jmp loop

return :
    pop r13
    xor rax, rax
    ret