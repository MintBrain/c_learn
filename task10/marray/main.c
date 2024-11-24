#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "array.h"
#include "marray.h"

void test()
{
    struct array_array_int array = array_array_read();
    struct value_int64 m = array_array_min(array);

    if (m.valid)
    {
        array_array_int_normalize(array, m.value);
        array_array_print(array);
    }

    array_array_int_free(array);
}

int main()
{
    test();

    return 0;
}