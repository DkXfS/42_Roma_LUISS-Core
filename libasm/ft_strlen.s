        global	_ft_strlen
        section	.text

_ft_strlen:
        xor r10, r10                    ; i = 0

loop:
        cmp BYTE[rdi + r10], 0          ; str[i] == 0 ?
        je  return
        inc r10
        jmp loop
    
return:
        mov rax, r10
        ret
