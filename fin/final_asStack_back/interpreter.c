#include "./headers/interpreter.h"

void (*(interprets[]))(struct SState *state) =
{
    [EOC_PUSH] = inter_push,
    [EOC_POP] = inter_pop,
    [EOC_SWAP] = inter_swap,
    [EOC_DUP] = inter_dup,

    [EOC_IADD] = inter_iadd,
    [EOC_ISUB] = inter_isub,
    [EOC_IMUL] = inter_imul,
    [EOC_IDIV] = inter_idiv,
    [EOC_IMOD] = inter_imod,
    [EOC_INEG] = inter_ineg,

    [EOC_IPRINT] = inter_iprint,
    [EOC_IREAD] = inter_iread,

    [EOC_ICMP] = inter_icmp,
    [EOC_JZ] = inter_jz,
    [EOC_JMP] = inter_jmp,
    [EOC_STOP] = inter_stop
};

void interpret(struct SState *state)
{
    while (state->ip && state->is_run)
    {
        const enum EOpCode op = state->ip->opcode;
        const struct SDescr* descr = instructions + op;
        
        if (descr->stack_min > state->data_stack.count)
        {
            printf("Stack underflow\n");
            return;
        }

        if (descr->stack_delta + state->data_stack.count > state->data_stack.data.size)
        {
            printf("Stack overflow\n");
            return;
        }
        
        if (interprets[op])
        {
            interprets[op](state);
        } else {
            printf("Command not found: %d\n", op);
            return;
        }

        if (!instructions[op].affects_ip){
            ++state->ip;
            }
    }
}

void interpret_program(const union UCom *program)
{
    struct SState state = state_create(program);
    interpret(&state);
    state_destroy(&state);
}