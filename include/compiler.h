#ifndef COMPILER_H_
#define COMPILER_H_

#if defined(__GNUC__) || defined(__clang__)
#define NORETURN __attribute__((noreturn))
#define UNREACHABLE __builtin_unreachable()
#else
#define NORETURN
#define UNREACHABLE
#endif

#endif /* COMPILER_H_ */