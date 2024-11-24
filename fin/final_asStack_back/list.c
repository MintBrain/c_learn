#include "./headers/list.h"

struct list *list_node_create(int64_t value)
{
    struct list *l = malloc(sizeof(struct list));
    l->value = value;
    l->next = NULL;
    return l;
}

void list_add_front(struct list **old, int64_t value)
{
    if (!old) return;
    struct list *new_l = list_node_create(value);
    new_l->next = *old;
    *old = new_l;
}

struct list *list_last(struct list *l)
{
    if (!l)
    {
        return NULL;
    }
    struct list *current = l;
    while (NULL != current->next)
    {
        current = current->next;
    }
    return current;
}

void list_add_back(struct list **old, int64_t value)
{
    struct list *new_l = list_node_create(value);
    struct list *last_old = list_last(*old);
    if (NULL != last_old)
    {
        last_old->next = new_l;
        return;
    }
    *old = new_l;
}

size_t list_length(struct list *l)
{
    size_t size = 0;
    if (NULL == l)
    {
        return size;
    }

    struct list *current_node = l;
    do
    {
        size++;
        current_node = current_node->next;
    } while (NULL != current_node);

    return size;
}

int64_t list_sum(const struct list *l)
{
    int64_t sum = 0;
    for (const struct list *cur = l; cur != NULL; cur = cur->next)
    {
        sum += cur->value;
    }
    return sum;
}

struct SValidInt64 list_at(const struct list *l, size_t index)
{
    for (const struct list *cur = l; cur != NULL; cur = cur->next)
    {
        if (0 == index)
        {
            return some_int64(cur->value);
        }
        index--;
    }
    return none_int64;
}

void list_destroy(struct list *l)
{
    while (l)
    {
        struct list *current = l;
        l = current->next;
        free(current);
    }
}

struct list *list_reverse(const struct list *l)
{
    struct list *reversed_list = NULL;
    for (const struct list *cur = l; cur != NULL; cur = cur->next)
    {
        list_add_front(&reversed_list, cur->value);
    }
    return reversed_list;
}


struct list *list_read()
{
    struct list *list = NULL;
    struct SValidInt64 new_val = read_int64();
    while (new_val.valid)
    {
        list_add_back(&list, new_val.value);
        new_val = read_int64();
    }
    return list;
}

void list_print(const struct list *l)
{
    if (!l)
    {
        printf("List is empty\n");
        return;
    }
    while (NULL != l)
    {
        print_int64_with_space(l->value);
        l = l->next;
    }
    printf("\n");
}