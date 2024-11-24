#include "./headers/operations.h"

void set_binop(struct SStack *s, int64_t(f)(int64_t, int64_t))
{
    stack_push(s, f(stack_pop(s).value, stack_pop(s).value));
}

void set_unop(struct SStack *s, int64_t(f)(int64_t))
{
    stack_push(s, f(stack_pop(s).value));
}

int64_t i64_add(int64_t a, int64_t b) {return a+b;}
int64_t i64_sub(int64_t a, int64_t b) {return b-a;}
int64_t i64_mul(int64_t a, int64_t b) {return a*b;}
int64_t i64_div(int64_t a, int64_t b) {return b/a;}
int64_t i64_mod(int64_t a, int64_t b) {return b%a;}
int64_t i64_neg(int64_t a) {return -a;}
int64_t i64_cmp(int64_t b, int64_t a) 
{
    if (a>b) return 1;
    if (a<b) return -1;
    return 0;
}

void inter_push(struct SState *state) {stack_push(&state->data_stack, state->ip->com_arg64.arg); }
void inter_pop(struct SState *state)  {stack_pop(&state->data_stack);}
void inter_swap(struct SState *state) 
{
    int64_t val1 = stack_pop(&state->data_stack).value;
    int64_t val2 = stack_pop(&state->data_stack).value;
    stack_push(&state->data_stack, val1);
    stack_push(&state->data_stack, val2);
}
void inter_dup(struct SState *state)  
{
    int64_t val = stack_pop(&state->data_stack).value;
    stack_push(&state->data_stack, val); 
    stack_push(&state->data_stack, val);
}
void inter_iadd(struct SState *state) {set_binop(&state->data_stack, i64_add);}
void inter_isub(struct SState *state) {set_binop(&state->data_stack, i64_sub);}
void inter_imul(struct SState *state) {set_binop(&state->data_stack, i64_mul);}
void inter_idiv(struct SState *state) {set_binop(&state->data_stack, i64_div);}
void inter_imod(struct SState *state) {set_binop(&state->data_stack, i64_mod);}
void inter_ineg(struct SState *state) {set_unop(&state->data_stack, i64_neg);}

void inter_iprint(struct SState *state) 
{    
    print_int64(stack_pop(&state->data_stack).value);
    print_newline();
}

void inter_iread(struct SState *state) {stack_push(&state->data_stack, read_int64().value);}
void inter_icmp(struct SState *state) {set_binop(&state->data_stack, i64_cmp);}
void inter_jz(struct SState *state) 
{
    int64_t val = stack_pop(&state->data_stack).value;
    if (0 == val)
    {
        state->ip += state->ip->com_arg64.arg;
    } else {
        ++state->ip;
    }
    stack_push(&state->data_stack, val);
}
void inter_jmp(struct SState *state) 
{
    int64_t arg =state->ip->com_arg64.arg; 
    if (arg > 0)
    {
        state->ip += arg;    
    } else {
        ++state->ip;
    }
    
}
void inter_stop(struct SState *state) {state->is_run = false;}
