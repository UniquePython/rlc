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

#endif /* SYSCALL_H_ */