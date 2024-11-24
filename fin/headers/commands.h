#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>

#define COUNT_OF(x) ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

enum EOpCode
{
    EOC_LD,
    EOC_LDN,
    EOC_ST,
    EOC_STN,
    EOC_S,
    EOC_R,
    EOC_AND,
    EOC_ANDN,
    EOC_OR,
    EOC_ORN,
    EOC_XOR,
    EOC_XORN,
    EOC_NOT,
    EOC_ADD,
    EOC_SUB,
    EOC_MUL,
    EOC_DIV,
    EOC_GT,
    EOC_GE,
    EOC_EQ,
    EOC_NE,
    EOC_LE,
    EOC_LT,
    EOC_JMP,
    EOC_JMPC,
    EOC_JMPCN,
    EOC_RET
};

enum EArgType
{
    EAT_NOARG,
    EAT_I64,
    EAT_BOOL,
    EAT_STR
};

struct SDescr
{
    const char *mnemonic;
    enum EArgType argtype;
    bool affects_ip;
    size_t stack_min;
    int64_t stack_delta;
};

struct SComNoArg
{
    enum EOpCode opcode;
};

struct SComArg64
{
    enum EOpCode opcode;
    int64_t arg;
};

union UCom
{
    enum EOpCode opcode;
    struct SComNoArg com_noarg;
    struct SComArg64 com_arg64;
};

struct SState
{
    const union UCom *ip_base;
    const union UCom *ip;
    int64_t ACC;
    enum EArgType ACC_type;
    bool is_run;
};

extern const struct SDescr instructions[];
extern const size_t instructions_count;

struct SState state_create(const union UCom *ip);
void state_destroy(struct SState *state);

#endif