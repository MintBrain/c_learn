#ifndef MARRAY_H
#define MARRAY_H

#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#include "array.h"


int64_t **marray_read(size_t *rows, size_t *sizes[]);
void marray_free(int64_t **marray, size_t rows);
void marray_print(int64_t **marray, size_t *sizes, size_t rows);
int64_t *int64_ptr_min(int64_t *x, int64_t *y);
int64_t *marray_int_min(int64_t **marray, size_t *sizes, size_t rows);
void marray_normalize(int64_t **marray, size_t sizes[], size_t rows, int64_t m);


#endif