#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include <inttypes.h>
#include "commands.h"
#include "io.h"

int64_t i64_add(int64_t a, int64_t b);
int64_t i64_sub(int64_t a, int64_t b);
int64_t i64_mul(int64_t a, int64_t b);
int64_t i64_div(int64_t a, int64_t b);
int64_t inv_ACC(struct SState *state);

void inter_LD(struct SState *state);
void inter_LDN(struct SState *state);
void inter_ST(struct SState *state);
void inter_STN(struct SState *state);
void inter_S(struct SState *state);
void inter_R(struct SState *state);
void inter_AND(struct SState *state);
void inter_ANDN(struct SState *state);
void inter_OR(struct SState *state);
void inter_ORN(struct SState *state);
void inter_XOR(struct SState *state);
void inter_XORN(struct SState *state);
void inter_NOT(struct SState *state);
void inter_ADD(struct SState *state);
void inter_SUB(struct SState *state);
void inter_MUL(struct SState *state);
void inter_DIV(struct SState *state);
void inter_GT(struct SState *state);
void inter_GE(struct SState *state);
void inter_EQ(struct SState *state);
void inter_NE(struct SState *state);
void inter_LE(struct SState *state);
void inter_LT(struct SState *state);
void inter_JMP(struct SState *state);
void inter_JMPC(struct SState *state);
void inter_JMPCN(struct SState *state);
void inter_RET(struct SState *state);

#endif