#include "./headers/interpreter.h"

void (*(interprets[]))(struct SState *state) =
    {
        [EOC_LD] = inter_LD,
        [EOC_LDN] = inter_LDN,
        [EOC_ST] = inter_ST,
        [EOC_STN] = inter_STN,
        [EOC_S] = inter_S,
        [EOC_R] = inter_R,
        [EOC_AND] = inter_AND,
        [EOC_ANDN] = inter_ANDN,
        [EOC_OR] = inter_OR,
        [EOC_ORN] = inter_ORN,
        [EOC_XOR] = inter_XOR,
        [EOC_XORN] = inter_XORN,
        [EOC_NOT] = inter_NOT,
        [EOC_ADD] = inter_ADD,
        [EOC_SUB] = inter_SUB,
        [EOC_MUL] = inter_MUL,
        [EOC_DIV] = inter_DIV,
        [EOC_GT] = inter_GT,
        [EOC_GE] = inter_GE,
        [EOC_EQ] = inter_EQ,
        [EOC_NE] = inter_NE,
        [EOC_LE] = inter_LE,
        [EOC_LT] = inter_LT,
        [EOC_JMP] = inter_JMP,
        [EOC_JMPC] = inter_JMPC,
        [EOC_JMPCN] = inter_JMPCN,
        [EOC_RET] = inter_RET};

void interpret(struct SState *state)
{
    while (state->ip && state->is_run)
    {
        const enum EOpCode op = state->ip->opcode;

        if (interprets[op])
        {
            interprets[op](state);
        }
        else
        {
            printf("Command not found: %d\n", op);
            return;
        }

        if (!instructions[op].affects_ip)
        {
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