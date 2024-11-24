#include <inttypes.h>
#include <stdlib.h>
#include "min.h"

void perform()
{
    size_t size;
    int64_t *array = array_int_read(&size);
    array_int_fill(array, size);
    intptr_print(array_int_min(array, size));

    free(array);
}

// -9223372036854775808 for test
int main()
{
    perform();

    return 0;
}