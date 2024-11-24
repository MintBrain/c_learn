#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include <inttypes.h>
#include "commands.h"

void set_binop(struct SStack *s, int64_t(f)(int64_t, int64_t));
void set_unop(struct SStack *s, int64_t(f)(int64_t));

int64_t i64_add(int64_t a, int64_t b);
int64_t i64_sub(int64_t a, int64_t b);
int64_t i64_mul(int64_t a, int64_t b);
int64_t i64_div(int64_t a, int64_t b);
int64_t i64_mod(int64_t a, int64_t b);
int64_t i64_neg(int64_t a);
int64_t i64_cmp(int64_t a, int64_t b);

void inter_push(struct SState *state);
void inter_pop(struct SState *state);
void inter_swap(struct SState *state);
void inter_dup(struct SState *state);
void inter_iadd(struct SState *state);
void inter_isub(struct SState *state);
void inter_imul(struct SState *state);
void inter_idiv(struct SState *state);
void inter_imod(struct SState *state);
void inter_ineg(struct SState *state);
void inter_iprint(struct SState *state);
void inter_iread(struct SState *state);
void inter_icmp(struct SState *state);
void inter_jz(struct SState *state);
void inter_jmp(struct SState *state);
void inter_stop(struct SState *state);

#endif