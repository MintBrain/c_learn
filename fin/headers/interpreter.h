#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include "commands.h"
#include "operations.h"

extern void (*(interprets[]))(struct SState *state);

void interpret_program(const union UCom *program);

#endif