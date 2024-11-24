#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "array.h"
#include "stack.h"


int main()
{
    struct stack st = stack_create(3);
    stack_push(&st, 123);
    stack_push(&st, 13453);
    printf("%" PRId64 "\n", stack_pop(&st).value);
    stack_print(&st);
    stack_push(&st, 13123453);
    stack_print(&st);

    stack_destroy(&st);

    return 0;
}