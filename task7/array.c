#include "array.h"

size_t read_size()
{
    size_t num;
    scanf("%zu", &num);
    return num;
}

int64_t read_int64()
{
    int64_t num;
    scanf("%" PRId64, &num);
    return num;
}

int64_t *array_int_read(size_t *size)
{
    *size = read_size();
    return calloc(*size, sizeof(int64_t));
}

void array_int_fill(int64_t *array, size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        array[i] = read_int64();
    }
}

int64_t *array_int_min(int64_t *array, size_t size)
{
    if (!size)
    {
        return NULL;
    }
    int64_t *min = &array[0];
    for (size_t i = 1; i != size; ++i)
    {
        if (array[i] < *min)
        {
            min = &array[i];
        }
    }
    return min;
}

void print_array(int64_t *array, int64_t *lim)
{
    for (int64_t *i = array; i < lim; ++i)
    {
        printf("%" PRId64 " ", *i);
    }
    printf("\n");
}
