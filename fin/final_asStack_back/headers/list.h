#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "valid_int.h"
#include "io.h"

struct list
{
    int64_t value;
    struct list *next;
};

struct list *list_node_create(int64_t value);
void list_add_front(struct list **old, int64_t value);
struct list *list_last(struct list *l);
void list_add_back(struct list **old, int64_t value);
size_t list_length(struct list *l);
int64_t list_sum(const struct list *l);
struct SValidInt64 list_at(const struct list *l, size_t index);
void list_destroy(struct list *l);
struct list *list_reverse(const struct list *l);
struct list* list_read();
void list_print(const struct list *l);

#endif