CC      := gcc
AR      := ar

CFLAGS  := -Wall -Wextra -std=gnu99 -ffreestanding -nostdlib -Iinclude

ASFLAGS := -ffreestanding -nostdlib -Iinclude

LDFLAGS := -nostdlib

BUILDDIR := build
BINDIR   := bin

LIBNAME := $(BINDIR)/librlc.a

SRC_C := $(wildcard src/*.c)
SRC_S := $(wildcard src/*.S)

OBJ_C   := $(patsubst src/%.c,$(BUILDDIR)/%.o,$(SRC_C))
OBJ_S   := $(patsubst src/%.S,$(BUILDDIR)/%.o,$(SRC_S))

OBJS    := $(OBJ_C) $(OBJ_S)

TEST    := $(BINDIR)/test
TESTSRC := test.c

.PHONY: all clean

all: $(LIBNAME) $(TEST)

# Create directories
$(BUILDDIR) $(BINDIR):
	mkdir -p $@

# Static library
$(LIBNAME): $(OBJS) | $(BINDIR)
	$(AR) rcs $@ $^

# Compile C
$(BUILDDIR)/%.o: src/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile assembly
$(BUILDDIR)/%.o: src/%.S | $(BUILDDIR)
	$(CC) $(ASFLAGS) -c $< -o $@

# Link test program
$(TEST): $(TESTSRC) $(LIBNAME) | $(BINDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -L$(BINDIR) -lrlc -o $@

clean:
	rm -rf $(BUILDDIR) $(BINDIR)