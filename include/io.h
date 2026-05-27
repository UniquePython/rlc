#ifndef IO_H_
#define IO_H_

#include "error.h"
#include "types.h"

#define STDIN ((uint)0)
#define STDOUT ((uint)1)
#define STDERR ((uint)2)

Res_long write(uint fileDescriptor, const void *buffer, ulong count);
ErrCode writeAll(uint fileDescriptor, const void *buffer, ulong count);

#endif /* IO_H_ */