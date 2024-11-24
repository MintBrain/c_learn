#ifndef _VALID_INT_H_
#define _VALID_INT_H_

#include <stdint.h>
#include <stdbool.h>

struct SValidInt64
{
    int64_t value;
    bool valid;
};

struct SValidInt64 some_int64(int64_t i);

const struct SValidInt64 none_int64;

#endif