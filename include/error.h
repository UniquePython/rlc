#ifndef ERROR_H_
#define ERROR_H_

typedef enum error_code
{
    NO_ERR = 0,
    OP_NOT_PERMITTED,
    NO_FILE_DIR,
    NO_PROC,
    IO_ERR,
    NO_DEVICE_ADDR,
    TOO_LONG_ARG,
    EXEC_FORMAT_ERR,
    BAD_FD,
    NO_CHILD_PROC,
    TRY_AGAIN,
    OUT_OF_MEMORY,
    PERM_DENIED,
    BAD_ADDR,
    BLOCK_DEVICE_REQD,
    DEVICE_RESOURCE_BUSY,
    FILE_EXISTS,
    CROSS_DEVICE_LINK,
    NO_DEVICE,
    NOT_DIR,
    IS_DIR,
    INVALID_ARG,
    FILE_TABLE_OVERFLOW,
    TOO_MANY_OPEN_FILES,
    NO_TTY,
    TXT_FILE_BUSY,
    FILE_TOO_LARGE,
    NO_SPACE_DEVICE,
    ILLEGAL_SEEK,
    RDONLY_FS,
    TOO_MANY_LINKS,
    BROKEN_PIPE,
    ARG_OUT_OF_DOMAIN,
    NOT_REPRESENTABLE
} ErrCode;

static inline ErrCode errno_to_rlc(long kernel_err)
{
    return (ErrCode)(-kernel_err);
}

#define RESULT(T)             \
    typedef struct result_##T \
    {                         \
        short isErr;          \
        union                 \
        {                     \
            T val;            \
            ErrCode err;      \
        } res;                \
    } Res_##T;

#define IS_ERR(result) ((result).isErr)

RESULT(long)

#endif /* ERROR_H_ */