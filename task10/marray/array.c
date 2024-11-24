#include "array.h"

const struct str_array_int none_array_int = {{NULL, 0}, false};
const struct value_int64 none_value_int64 = {0};

struct value_int64 some_value_int64(int64_t value)
{
    return (struct value_int64){.value = value, .valid = true};
}

struct str_array_int some_array_int(struct array_int array)
{
    return (struct str_array_int){array, true};
}

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

void array_int_fill(int64_t *array, size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        array[i] = read_int64();
    }
}

struct array_int array_int_read()
{
    size_t size = read_size();
    return (struct array_int){.data = calloc(size, sizeof(int64_t)), .size = size};
}

// Get value of array by index
struct value_int64 array_get(struct array_int a, size_t index)
{
    if (index < a.size)
    {
        return some_value_int64(a.data[index]);
    }
    else
    {
        return none_value_int64;
    }
}

bool array_set(struct array_int a, size_t index, int64_t value)
{
    if (index < a.size)
    {
        a.data[index] = value;
        return true;
    }
    else
    {
        return false;
    }
}

void array_int_print(struct array_int a)
{
    for (size_t i = 0; i < a.size; ++i)
    {
        printf("%" PRId64 " ", a.data[i]);
    }
    printf("\n");
}

struct value_int64 array_min(struct array_int a)
{
    if (!a.size)
    {
        return none_value_int64;
    }
    int64_t *min = &a.data[0];
    for (size_t i = 1; i < a.size; ++i)
    {
        if (a.data[i] < *min)
        {
            min = &a.data[i];
        }
    }
    return some_value_int64(*min);
}

void array_free(struct array_int a)
{
    free(a.data);
}
