#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include "array.h"

struct stack
{
    size_t count;
    struct array_int data;
};

size_t stack_count(const struct stack *s);

// Create stack
//- size = max element capacity
struct stack stack_create(size_t size);

void stack_destroy(struct stack *s);

bool stack_is_empty(const struct stack *s);

bool stack_is_full(const struct stack *s);

bool stack_push(struct stack *s, int64_t value);

struct value_int64 stack_pop(struct stack *s);

void stack_print(const struct stack *s);

#endif