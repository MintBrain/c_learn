#include "./headers/io.h"

uint64_t read_uint64()
{
    uint64_t num;
    scanf("%" SCNu64, &num);
    return num;
}

struct SValidInt64 read_int64()
{
    int64_t value;
    int res = scanf("%" SCNd64, &value);
    if (!res || EOF == res)
    {
        return none_int64;
    }
    return some_int64(value);
}

size_t read_size()
{
    size_t num;
    scanf("%zu", &num);
    return num;
}

void print_uint64(uint64_t value)
{
    printf("%" PRIu64, value);
}

void print_int64(int64_t value)
{
    printf("%" PRId64, value);
}

void print_int64_with_space(int64_t value)
{
    printf("%" PRId64 " ", value);
}

void print_newline(void)
{
    printf("\n");
}