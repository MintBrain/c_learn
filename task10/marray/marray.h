#ifndef MARRAY_H
#define MARRAY_H

#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "array.h"

struct array_array_int
{
    struct array_int *data;
    size_t size;
};

struct str_array_int array_array_get_row(struct array_array_int a, size_t i);
bool array_array_set_row(struct array_array_int a, size_t i, struct str_array_int value);

struct value_int64 array_array_int_get(struct array_array_int a, size_t i, size_t j);
bool array_array_int_set(struct array_array_int a, size_t i, size_t j, int64_t value);

struct array_array_int array_array_read();
void array_array_print(struct array_array_int array);

struct value_int64 array_array_min(struct array_array_int array);
void array_array_int_normalize(struct array_array_int a, int64_t value);

void array_array_int_free(struct array_array_int a);

#endif