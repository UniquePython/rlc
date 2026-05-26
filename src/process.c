#include "process.h"

#include "syscall.h"
#include "syscallnums.h"

NORETURN void exit(int ret)
{
    (void)syscall1(EXIT, ret);
    UNREACHABLE;
}