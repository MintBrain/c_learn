#include "main.h"

static void perform()
{
    size_t rows;
    size_t *sizes;
    int64_t **marray = marray_read(&rows, &sizes);
    int64_t *min = marray_int_min(marray, sizes, rows);
    if (NULL != min)
    {
        marray_normalize(marray, sizes, rows, *min);
        marray_print(marray, sizes, rows);
    }
    else
    {
        printf("Min. value not found\n");
    }
    marray_free(marray, rows);
    free(sizes);
}

int main()
{
    perform();

    return 0;
}