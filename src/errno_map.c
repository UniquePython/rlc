#include "error.h"

ErrCode errno_to_rlc(long kernel_err)
{
    if (kernel_err == 9)
        return BAD_FD;
    else if (kernel_err == 14)
        return BAD_ADDRESS;
    else if (kernel_err == 27)
        return FILE_TOO_LARGE;
    else if (kernel_err == 14)
        return BAD_ADDRESS;
    else if (kernel_err == 14)
        return BAD_ADDRESS;
    else if (kernel_err == 14)
        return BAD_ADDRESS;
}