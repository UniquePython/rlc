#include "io.h"

#include "syscall.h"
#include "syscallnums.h"

Res_long write(uint fileDescriptor, const void *buffer, ulong count)
{
    long ret = syscall3(WRITE, fileDescriptor, (long)buffer, count);

    if (ret < 0)
        return (Res_long){
            .isErr = 1,
            .res.err = errno_to_rlc(ret),
        };
    else
        return (Res_long){
            .isErr = 0,
            .res.val = ret,
        };
}

ErrCode writeAll(uint fileDescriptor, const void *buffer, ulong count)
{
    const uchar *buf = (const uchar *)buffer;
    ulong totalWritten = 0;

    while (totalWritten < count)
    {
        Res_long result = write(
            fileDescriptor,
            buf + totalWritten,
            count - totalWritten);

        if (result.isErr)
            return result.res.err;

        /*
         * write() returning 0 generally should not happen for
         * regular writes, but guard against infinite loops.
         */
        if (result.res.val == 0)
            return IO_ERR;

        totalWritten += (ulong)result.res.val;
    }

    return NO_ERR;
}

Res_long read(uint fileDescriptor, void *buf, ulong count)
{
    long ret = syscall3(READ, fileDescriptor, (long)buf, count);

    if (ret < 0)
        return (Res_long){
            .isErr = 1,
            .res.err = errno_to_rlc(ret),
        };
    else
        return (Res_long){
            .isErr = 0,
            .res.val = ret,
        };
}

ErrCode readAll(uint fileDescriptor, void *buf, ulong count)
{
    uchar *buffer = (uchar *)buf;
    ulong totalRead = 0;

    while (totalRead < count)
    {
        Res_long result = read(
            fileDescriptor,
            buffer + totalRead,
            count - totalRead);

        if (result.isErr)
            return result.res.err;

        /*
         * EOF before reading everything requested.
         */
        if (result.res.val == 0)
            return IO_ERR;

        totalRead += (ulong)result.res.val;
    }

    return NO_ERR;
}