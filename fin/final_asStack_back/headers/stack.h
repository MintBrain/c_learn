#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include "array.h"
#include "valid_int.h"

struct SStack
{
    size_t count;
    struct array_int data;
};

size_t stack_count(const struct SStack *s);

// Create stack
//- size = max element capacity
struct SStack stack_create(size_t size);

void stack_destroy(struct SStack *s);

bool stack_is_empty(const struct SStack *s);

bool stack_is_full(const struct SStack *s);

bool stack_push(struct SStack *s, int64_t value);

struct SValidInt64 stack_pop(struct SStack *s);

void stack_print(const struct SStack *s);

#endif