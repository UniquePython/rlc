CC      := gcc
AR      := ar

CFLAGS  := -Wall -Wextra -std=c99 -ffreestanding -nostdlib -Iinclude

ASFLAGS := -ffreestanding -nostdlib -Iinclude

LDFLAGS := -nostdlib

LIBNAME := librlc.a

SRC_C   := src/process.c
SRC_S   := src/start.S

OBJ_C   := $(SRC_C:.c=.o)
OBJ_S   := $(SRC_S:.S=.o)

OBJS    := $(OBJ_C) $(OBJ_S)

TEST    := test
TESTSRC := test.c

.PHONY: all clean

all: $(LIBNAME) $(TEST)

# Static library
$(LIBNAME): $(OBJS)
	$(AR) rcs $@ $^

# Compile C
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile assembly
src/%.o: src/%.S
	$(CC) $(ASFLAGS) -c $< -o $@

# Link test program
$(TEST): $(TESTSRC) $(LIBNAME)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -L. -lrlc -o $@

clean:
	rm -f $(OBJS) $(LIBNAME) $(TEST)