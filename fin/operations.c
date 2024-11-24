#include "./headers/operations.h"

int64_t i64_add(int64_t a, int64_t b) { return a + b; }
int64_t i64_sub(int64_t a, int64_t b) { return a - b; }
int64_t i64_mul(int64_t a, int64_t b) { return a * b; }
int64_t i64_div(int64_t a, int64_t b) { return a / b; }

int64_t inv_ACC(struct SState *state)
{
    if (state->ACC_type == EAT_I64)
    {
        return -state->ACC;
    }
    if (state->ACC_type == EAT_BOOL)
    {
        return !((bool)state->ACC);
    }
    return 0;
}

// Загрузить обратное значение операнда в аккумулятор
void inter_LDN(struct SState *state)
{
    state->ACC = -state->ip->com_arg64.arg;
    state->ACC_type = EAT_I64;
}

void inter_LD(struct SState *state)
{
    state->ACC = state->ip->com_arg64.arg;
    state->ACC_type = EAT_I64;
}

// Поразрядная инверсия аккумулятора
void inter_NOT(struct SState *state)
{
    state->ACC = inv_ACC(state);
}

void inter_ADD(struct SState *state) { state->ACC = i64_add(state->ACC, state->ip->com_arg64.arg); }
void inter_SUB(struct SState *state) { state->ACC = i64_sub(state->ACC, state->ip->com_arg64.arg); }
void inter_MUL(struct SState *state) { state->ACC = i64_mul(state->ACC, state->ip->com_arg64.arg); }
void inter_DIV(struct SState *state) { state->ACC = i64_div(state->ACC, state->ip->com_arg64.arg); }

// Значение аккумулятора сравнивается со значением операнда(>(greater than)). Значение (TRUE или FALSE) записывается в аккумулятор
void inter_GT(struct SState *state)
{
    state->ACC = state->ACC > state->ip->com_arg64.arg;
    state->ACC_type = EAT_BOOL;
}

// Значение аккумулятора сравнивается со значением операнда(>=greater than or equal)). Значение (TRUE или FALSE) записывается в аккумулятор
void inter_GE(struct SState *state)
{
    state->ACC = state->ACC >= state->ip->com_arg64.arg;
    state->ACC_type = EAT_BOOL;
}

// Значение аккумулятора сравнивается со значением операнда (=(equal)). Значение (TRUE или FALSE) записывается в аккумулятор
void inter_EQ(struct SState *state)
{
    state->ACC = state->ACC == state->ip->com_arg64.arg;
    state->ACC_type = EAT_BOOL;
}

// Значение аккумулятора сравнивается со значением операнда (<>(not equal). Значение (TRUE или FALSE) записывается в аккумулятор
void inter_NE(struct SState *state)
{
    state->ACC = state->ACC != state->ip->com_arg64.arg;
    state->ACC_type = EAT_BOOL;
}

// Значение аккумулятора сравнивается со значением операнда (<=(less than or equal to)). Значение (TRUE или FALSE) записывается в аккумулятор
void inter_LE(struct SState *state)
{
    state->ACC = state->ACC <= state->ip->com_arg64.arg;
    state->ACC_type = EAT_BOOL;
}

// Значение аккумулятора сравнивается со значением операнда (<(less than)). Значение (TRUE или FALSE) записывается в аккумулятор
void inter_LT(struct SState *state)
{
    state->ACC = state->ACC < state->ip->com_arg64.arg;
    state->ACC_type = EAT_BOOL;
}

// Если значение аккумулятора TRUE, установить логический операнд
void inter_S(struct SState *state)
{
    if (state->ACC_type == EAT_BOOL && 1 == state->ACC)
    {
        printf("TRUE\n");
    }
}

// Если значение аккумулятора FALSE, сбросить логический операнд
void inter_R(struct SState *state)
{
    if (state->ACC_type == EAT_BOOL && 0 == state->ACC)
    {
        printf("FALSE\n");
    }
}

//   Поразрядное И аккумулятора и операнда
void inter_AND(struct SState *state)
{
    state->ACC = state->ACC && state->ip->com_arg64.arg;
    state->ACC_type = EAT_BOOL;
}

//	Поразрядное И аккумулятора и обратного операнда
void inter_ANDN(struct SState *state)
{
    state->ACC = state->ACC && !((bool)state->ip->com_arg64.arg);
    state->ACC_type = EAT_BOOL;
}

//  Поразрядное ИЛИ аккумулятора и операнда
void inter_OR(struct SState *state)
{
    state->ACC = state->ACC || state->ip->com_arg64.arg;
    state->ACC_type = EAT_BOOL;
}

//   Поразрядное ИЛИ аккумулятора и обратного операнда
void inter_ORN(struct SState *state)
{
    state->ACC = state->ACC || !((bool)state->ip->com_arg64.arg);
    state->ACC_type = EAT_BOOL;
}

//   Поразрядное разделительное ИЛИ аккумулятора и операнда
void inter_XOR(struct SState *state)
{
    state->ACC = state->ACC ^ state->ip->com_arg64.arg;
    state->ACC_type = EAT_BOOL;
}

//	Поразрядное разделительное ИЛИ аккумулятора и обратного операнда
void inter_XORN(struct SState *state)
{
    state->ACC = state->ACC ^ !((bool)state->ip->com_arg64.arg);
    state->ACC_type = EAT_BOOL;
}

void inter_ST(struct SState *state)
{
    print_int64(state->ACC);
    print_newline();
}

// Присвоить обратное значение аккумулятора операнду
void inter_STN(struct SState *state)
{
    if (state->ACC_type == EAT_I64)
    {
        print_int64(inv_ACC(state));
        print_newline();
    }
}

// Переход к метке
void inter_JMP(struct SState *state)
{
    int64_t arg = state->ip->com_arg64.arg;
    state->ip = &state->ip_base[arg];
}

// Переход к метке при условии, что значение аккумулятора TRUE
void inter_JMPC(struct SState *state)
{
    if (state->ACC_type == EAT_BOOL && 1 == state->ACC)
    {
        state->ip = &state->ip_base[state->ip->com_arg64.arg];
    }
    else
    {
        state->ip++;
    }
}

// Переход к метке при условии, что значение аккумулятора FALSE
void inter_JMPCN(struct SState *state)
{
    if (state->ACC_type == EAT_BOOL && 0 == state->ACC)
        state->ip = &state->ip_base[state->ip->com_arg64.arg];
    else
    {
        state->ip++;
    }
}

void inter_RET(struct SState *state)
{
    state->is_run = false;
}
