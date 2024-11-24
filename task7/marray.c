#include "marray.h"

int64_t **marray_read(size_t *rows, size_t *sizes[])
{
    *rows = read_size();
    int64_t **array = (int64_t **)calloc(*rows, sizeof(int64_t *));
    *sizes = (size_t *)calloc(*rows, sizeof(size_t));

    for (size_t i = 0; i != *rows; ++i)
    {
        array[i] = array_int_read(&(*sizes)[i]);
        array_int_fill(array[i], (*sizes)[i]);
    }
    return array;
}

void marray_print(int64_t **marray, size_t *sizes, size_t rows)
{
    printf("\nArray:\n");
    for (size_t i = 0; i != rows; ++i)
    {
        print_array(marray[i], marray[i] + sizes[i]);
    }
}

void marray_free(int64_t **marray, size_t rows)
{
    for (size_t i = 0; i != rows; ++i)
    {
        free(marray[i]);
    }
    if (marray)
    {
        free(marray);
        marray = NULL;
    }
}

int64_t *int64_ptr_min(int64_t *x, int64_t *y)
{
    if (*x <= *y && x != NULL)
    {
        return x;
    }
    return y;
}

int64_t *marray_int_min(int64_t **marray, size_t *sizes, size_t rows)
{
    int64_t *min = NULL;
    int64_t min_val = INT64_MAX;
    for (size_t i = 0; i != rows; ++i)
    {
        for (size_t j = 0; j != sizes[i]; ++j)
        {
            min = int64_ptr_min(&marray[i][j], &min_val);
            min_val = *min;
        }
    }
    return min;
}

void marray_normalize(int64_t **marray, size_t sizes[], size_t rows, int64_t m)
{
    for (size_t i = 0; i != rows; ++i)
    {
        for (size_t j = 0; j != sizes[i]; ++j)
        {
            marray[i][j] -= m;
        }
    }
}