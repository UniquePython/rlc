#include "include/io.h"

int main(void)
{
    writeAll(STDOUT, "Hello World!\n", sizeof("Hello World!\n") - 1);
    return 0;
}