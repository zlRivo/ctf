; Checks if a character is hex
helper:
        lea     edx, [rdi-48]
        mov     eax, 1
        cmp     edx, 9
        jbe     .L2
        and     edi, -33
        xor     eax, eax
        sub     edi, 65
        cmp     edi, 5
        setbe   al
.L2:
        ret



.LC0:
        .string "%2x"
f:
        push    r15
        xor     eax, eax
        or      rcx, -1
        push    r14
        push    r13
        push    r12
        mov     r12, rsi
        push    rbp
        mov     rbp, rsi
        push    rbx
        mov     rbx, rdi
        sub     rsp, 24
        repnz scasb
        not     rcx ;                   RCX <- 0
        lea     r14, [rbx-1+rcx]
.L6:
        cmp     rbx, r14
        ja      .L24
        movsx   eax, BYTE PTR [rbx]
        lea     r13, [rbx+1]
        mov     r15, r13
        cmp     eax, 43
        mov     DWORD PTR [rsp+12], eax
        jne     .L7
        mov     DWORD PTR [rsp+12], 32
        jmp     .L8
.L7:
        cmp     eax, 37
        jne     .L8
        movsx   edi, BYTE PTR [rbx+1]
        call    helper
        test    eax, eax
        jne     .L9
.L11:
        or      eax, -1
        jmp     .L10
.L9:
        movsx   edi, BYTE PTR [rbx+2]
        lea     r13, [rbx+3]
        call    helper
        test    eax, eax
        je      .L11
        lea     rdx, [rsp+12]
        xor     eax, eax
        mov     esi, OFFSET FLAT:.LC0
        mov     rdi, r15
        call    __isoc99_sscanf
        test    eax, eax
        je      .L11
.L8:
        test    r12, r12
        je      .L12
        mov     eax, DWORD PTR [rsp+12]
        mov     BYTE PTR [rbp+0], al
.L12:
        inc     rbp
        mov     rbx, r13
        jmp     .L6
.L24:
        mov     eax, ebp
        sub     eax, r12d
.L10:
        add     rsp, 24
        pop     rbx
        pop     rbp
        pop     r12
        pop     r13
        pop     r14
        pop     r15
        ret