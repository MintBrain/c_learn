#ifndef _IO_H_
#define _IO_H_

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include "valid_int.h"

uint64_t read_uint64();

struct SValidInt64 read_int64();

size_t read_size();
void print_uint64(uint64_t);
void print_int64(int64_t);
void print_int64_with_space(int64_t);
void print_newline(void);

#endif