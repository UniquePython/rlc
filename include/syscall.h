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

static inline long syscall1(long syscallNum, long arg1)
{
    long ret;

    asm volatile(
        "syscall"
        : "=a"(ret)
        : "0"(syscallNum), "D"(arg1)
        : "rcx", "r11", "memory");

    return ret;
}

#endif /* SYSCALL_H_ */