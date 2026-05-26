#ifndef SYSCALL_H_
#define SYSCALL_H_

static inline long syscall0(long syscallNum)
{
    long ret;

    asm volatile(
        "syscall"
        : "=a"(ret)
        : "0"(syscallNum)
        : "rcx", "r11", "memory");

    return ret;
}

static inline long syscall1(long syscallNum, long rdi)
{
    long ret;

    asm volatile(
        "syscall"
        : "=a"(ret)
        : "0"(syscallNum), "D"(rdi)
        : "rcx", "r11", "memory");

    return ret;
}

static inline long syscall2(long syscallNum, long rdi, long rsi)
{
    long ret;

    asm volatile(
        "syscall"
        : "=a"(ret)
        : "0"(syscallNum), "D"(rdi), "S"(rsi)
        : "rcx", "r11", "memory");

    return ret;
}

static inline long syscall3(long syscallNum, long rdi, long rsi, long rdx)
{
    long ret;

    asm volatile(
        "syscall"
        : "=a"(ret)
        : "0"(syscallNum), "D"(rdi), "S"(rsi), "d"(rdx)
        : "rcx", "r11", "memory");

    return ret;
}

static inline long syscall4(long syscallNum, long rdi, long rsi, long rdx, long r10)
{
    long ret;

    register long r10val asm("r10") = r10;

    asm volatile(
        "syscall"
        : "=a"(ret)
        : "0"(syscallNum), "D"(rdi), "S"(rsi), "d"(rdx), "r"(r10val)
        : "rcx", "r11", "memory");

    return ret;
}

static inline long syscall5(long syscallNum, long rdi, long rsi, long rdx, long r10, long r8)
{
    long ret;

    register long r10val asm("r10") = r10;
    register long r8val asm("r8") = r8;

    asm volatile(
        "syscall"
        : "=a"(ret)
        : "0"(syscallNum), "D"(rdi), "S"(rsi), "d"(rdx), "r"(r10val), "r"(r8val)
        : "rcx", "r11", "memory");

    return ret;
}

static inline long syscall6(long syscallNum, long rdi, long rsi, long rdx, long r10, long r8, long r9)
{
    long ret;

    register long r10val asm("r10") = r10;
    register long r8val asm("r8") = r8;
    register long r9val asm("r9") = r9;

    asm volatile(
        "syscall"
        : "=a"(ret)
        : "0"(syscallNum), "D"(rdi), "S"(rsi), "d"(rdx), "r"(r10val), "r"(r8val), "r"(r9val)
        : "rcx", "r11", "memory");

    return ret;
}

#endif /* SYSCALL_H_ */