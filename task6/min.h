#ifndef MIN_ARRAY_VAL_H
#define MIN_ARRAY_VAL_H

#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>


int64_t read_int64();
size_t read_size();
void array_int_fill(int64_t *array, size_t size);
int64_t *array_int_read(size_t *size);
int64_t *array_int_min(int64_t *array, size_t size);
void intptr_print(int64_t *x);
void print_array(int64_t *array, int64_t *lim);


#endif