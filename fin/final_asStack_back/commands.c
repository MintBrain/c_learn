#include "./headers/commands.h"

const struct SDescr instructions[] = {
    [EOC_PUSH] =   {"push", EAT_I64, false,0,1},
    [EOC_POP] =    {"pop", EAT_NOARG, false,1,0},
    [EOC_SWAP] =   {"swap", EAT_NOARG, false,2,0},
    [EOC_DUP] =    {"dup", EAT_NOARG, false,1,0},
    [EOC_IADD] =   {"iadd",  EAT_NOARG, false,2,0},
    [EOC_ISUB] =   {"isub",  EAT_NOARG, false,2,0},
    [EOC_IMUL] =   {"imul",  EAT_NOARG, false,2,0},
    [EOC_IDIV] =   {"idiv",  EAT_NOARG, false,2,0},
    [EOC_IMOD] =   {"imod",  EAT_NOARG, false,2,0},
    [EOC_INEG] =   {"ineg",  EAT_NOARG, false,1,0},
    [EOC_IPRINT] = {"iprint", EAT_NOARG, false,1,0},
    [EOC_IREAD] =  {"iread", EAT_NOARG, false,0,1},
    [EOC_ICMP] =   {"icmp", EAT_NOARG, false,2,0},
    [EOC_JZ] =     {"jz", EAT_I64, true,0,0},
    [EOC_JMP] =    {"jmp", EAT_I64, true,0,0},
    [EOC_STOP] =   {"stop", EAT_NOARG, true,0,0}
};

const size_t instructions_count = COUNT_OF(instructions);

struct SState state_create(const union UCom *ip)
{
    return (struct SState){.ip = ip, .data_stack = stack_create(STACK_CAPACITY), .is_run=true};
}

void state_destroy(struct SState *state)
{
    if (state)
    {
        stack_destroy(&state->data_stack);
    }
}