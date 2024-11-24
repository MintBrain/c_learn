#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>


size_t read_size();
int64_t read_int64();
int64_t *array_int_read(size_t *size);
void array_int_fill(int64_t *array, size_t size);
void print_array(int64_t *array, int64_t *lim);
int64_t *array_int_min(int64_t *array, size_t size);


#endif