.intel_syntax noprefix

.global _start

.extern main
.extern exit

_start:
    mov rdi, [rsp]             # Load argc
    lea rsi, [rsp+8]           # Load argv
    lea rdx, [rsi + rdi*8 + 8] # Load envp

    call main

    mov rdi, rax # Move return value of main to rdi so that exit syscall can use it

    call exit

.section .note.GNU-stack,"",@progbits