    global _ft_strcpy
    section .text

_ft_strcpy :
        xor rcx, rcx                ; i = 0
    
    loop :
        mov r9b, BYTE[rsi + rcx]    ; using r9 as support register to hold the value
        mov BYTE[rdi + rcx] ,r9b    ; *(dst + i) = (*src + i)
        cmp r9b, 0                  ; if(*(src + i)) == 0
        je  return                  ;   return
        inc rcx                     ; i++
        jmp loop

    return :
        mov rax, rdi                ; placing return value in the return register
        ret