#include "./headers/valid_int.h"

const struct SValidInt64 none_int64 = {0};

struct SValidInt64 some_int64(int64_t i)
{
    return (struct SValidInt64){.value = i, .valid = true};
}