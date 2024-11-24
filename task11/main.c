#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define COUNT_OF(x) ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

enum ECity
{
    EC_SARATOV,
    EC_MOSCOW,
    EC_PARIS,
    EC_LOS_ANGELES,
    EC_OTHER
};

const char *SCity[] = {
    [EC_SARATOV] = "Saratov",
    [EC_MOSCOW] = "Moscow",
    [EC_PARIS] = "Paris",
    [EC_LOS_ANGELES] = "Los Angeles",
    [EC_OTHER] = "Other"};

struct SUser
{
    uint64_t id;
    char *name;
    enum ECity city;
};

int user_comparer_id(const struct SUser *x, const struct SUser *y)
{
    if (x->id > y->id)
        return 1;
    if (x->id < y->id)
        return -1;
    return 0;
}

int user_void_comparer_id(const void *x, const void *y)
{
    return user_comparer_id(x, y);
}

int user_comparer_name(const struct SUser *x, const struct SUser *y)
{
    return strcmp(x->name, y->name);
}

int user_void_comparer_name(const void *x, const void *y)
{
    return user_comparer_name(x, y);
}

int user_comparer_city(const struct SUser *x, const struct SUser *y)
{
    return strcmp(SCity[x->city], SCity[y->city]);
}

int user_void_comparer_city(const void *x, const void *y)
{
    return user_comparer_city(x, y);
}

// (int (*)(const void *, const void *))user_comparer_city
void sort_SUser_array(struct SUser users[], size_t count, int compar(const void *, const void *))
{
    if (NULL == users || count <= 1)
    {
        printf("Nothing to sort\n");
        return;
    }
    qsort(users, count, sizeof(struct SUser), compar);
}

void print_SUser_array(struct SUser *users, size_t count)
{
    if (NULL == users)
    {
        printf("Array is empty\n");
        return;
    }
    for (size_t i = 0; i < count; ++i)
    {
        printf("%" PRIu64 " %s %s", users[i].id, users[i].name, SCity[users[i].city]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    struct SUser users[] =
        {
            {10, "Alex", EC_LOS_ANGELES},
            {2, "Maria", EC_MOSCOW},
            {8, "Ivan", EC_SARATOV},
            {12, "Julia", EC_PARIS}};

    const size_t count = COUNT_OF(users);

    sort_SUser_array(users, count, user_void_comparer_id);
    print_SUser_array(users, count);

    sort_SUser_array(users, count, user_void_comparer_name);
    print_SUser_array(users, count);

    sort_SUser_array(users, count, user_void_comparer_city);
    print_SUser_array(users, count);

    return 0;
}