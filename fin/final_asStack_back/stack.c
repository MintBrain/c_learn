#include "./headers/stack.h"

size_t stack_count(const struct SStack *s)
{
    return s->count;
}

// Create stack
//- size = max element capacity
struct SStack stack_create(size_t size)
{
    return (struct SStack){.count = 0, .data = {.size = size, .data = calloc(size, sizeof(int64_t))}};
}

void stack_destroy(struct SStack *s)
{
    free(s->data.data);
    s->count = 0;
    s->data = none_array_int.value;
}

bool stack_is_empty(const struct SStack *s)
{
    return 0 == s->count;
}

bool stack_is_full(const struct SStack *s)
{
    return s->count >= s->data.size;
}

bool stack_push(struct SStack *s, int64_t value)
{
    if (stack_is_full(s))
    {
        printf("Stack is full\n");
        return false;
    }
    if (array_set(s->data, stack_count(s), value))
    {
        s->count++;
        return true;
    }
    return false;
}

struct SValidInt64 stack_pop(struct SStack *s)
{
    if (stack_is_empty(s))
    {
        printf("Stack is empty\n");
        return none_int64;
    }
    struct SValidInt64 val = array_get(s->data, stack_count(s) - 1);
    if (val.valid)
    {
        s->count--;
        return val;
    }
    return none_int64;
}

void stack_print(const struct SStack *s)
{
    if (stack_is_empty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("\nStack:\n");
    for (size_t i = 0; i < stack_count(s); ++i)
    {
        printf("%" PRId64, array_get(s->data, i).value);
        printf("\n");
    }
}