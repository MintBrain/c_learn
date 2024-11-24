#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <inttypes.h>
#include <stdio.h>
#include "stack.h"

#define STACK_CAPACITY 10
#define COUNT_OF(x) ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

enum EOpCode
{
    EOC_PUSH,
    EOC_POP,
    EOC_SWAP,
    EOC_DUP,
    EOC_IADD,
    EOC_ISUB,
    EOC_IMUL,
    EOC_IDIV,
    EOC_IMOD,
    EOC_INEG,
    EOC_IPRINT,
    EOC_IREAD,
    EOC_ICMP,
    EOC_JZ,
    EOC_JMP,
    EOC_STOP
};

enum EArgType{
    EAT_NOARG,
    EAT_I64
};

struct SDescr
{
    const char* mnemonic;
    enum EArgType argtype;
    bool affects_ip;
    size_t stack_min;
    int64_t stack_delta;
};

struct SComNoArg
{
    enum EOpCode opcode;
};

struct SComNoArg64
{
    enum EOpCode opcode;
    int64_t arg;
};

union UCom
{
    enum EOpCode opcode;
    struct SComNoArg com_noarg;
    struct SComNoArg64 com_arg64;
};

struct SState
{
    const union UCom *ip;
    struct SStack data_stack;
    bool is_run;
};

extern const struct SDescr instructions[];
extern const size_t instructions_count;

struct SState state_create(const union UCom *ip);
void state_destroy(struct SState *state);

#endif