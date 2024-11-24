#include "marray.h"

struct str_array_int array_array_get_row(struct array_array_int a, size_t i)
{
    if (i < a.size)
    {
        return some_array_int(a.data[i]);
    }
    else
    {
        return none_array_int;
    }
}

bool array_array_set_row(struct array_array_int a, size_t i, struct str_array_int value)
{
    if (i < a.size)
    {
        a.data[i] = value.value;
        return true;
    }
    else
    {
        return false;
    }
}

struct value_int64 array_array_int_get(struct array_array_int a, size_t i, size_t j)
{
    if (i < a.size)
    {
        if (j < a.data[i].size)
        {
            return some_value_int64(a.data[i].data[j]);
        }
    }
    return none_value_int64;
}

bool array_array_int_set(struct array_array_int a, size_t i, size_t j, int64_t value)
{
    if (i < a.size)
    {
        if (j < a.data[i].size)
        {
            a.data[i].data[j] = value;
            return true;
        }
    }
    return false;
}

struct array_array_int array_array_read()
{
    size_t rows_count = read_size();
    struct array_int *marray = calloc(rows_count, sizeof(struct array_int *));

    for (size_t i = 0; i < rows_count; ++i)
    {
        marray[i] = array_int_read();
        array_int_fill(marray[i].data, marray[i].size);
    }
    return (struct array_array_int){.data = marray, .size = rows_count};
}

void array_array_print(struct array_array_int array)
{
    printf("\nArray:\n");
    for (size_t i = 0; i != array.size; ++i)
    {
        array_int_print(array.data[i]);
    }
}

struct value_int64 array_array_min(struct array_array_int array)
{
    struct value_int64 min_val = array_min(array.data[0]);
    for (size_t i = 1; i < array.size; ++i)
    {
        struct value_int64 min_val_temp = array_min(array.data[i]);
        if (!min_val_temp.valid)
        {
            continue;
        }
        if (!min_val.valid || (min_val.valid && min_val.value > min_val_temp.value))
        {
            min_val = min_val_temp;
        }
    }
    return min_val;
}

void array_array_int_normalize(struct array_array_int a, int64_t value)
{
    for (size_t i = 0; i < a.size; ++i)
    {
        for (size_t j = 0; j < a.data[i].size; ++j)
        {
            struct value_int64 val = array_array_int_get(a, i, j);
            if (val.valid)
            {
                if (!array_array_int_set(a, i, j, val.value - value))
                {
                    printf("Error in array_array_int_set()");
                }
            }
        }
    }
}

void array_array_int_free(struct array_array_int a)
{
    for (size_t i = 0; i != a.size; ++i)
    {
        free(a.data[i].data);
    }
    a.data = NULL;
    a.size = 0;
}