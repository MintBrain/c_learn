#ifndef ARRAY_H
#define ARRAY_H

struct array_int
{
    int64_t *data;
    size_t size;
};

struct value_int64
{
    int64_t value;
    bool valid;
};

struct str_array_int
{
    struct array_int value;
    bool valid;
};

const struct str_array_int none_array_int;
const struct value_int64 none_value_int64;

size_t read_size();
void array_int_fill(int64_t *array, size_t size);

struct array_int array_int_read();
struct value_int64 array_get(struct array_int a, size_t index);
bool array_set(struct array_int a, size_t index, int64_t value);
void array_int_print(struct array_int a);

struct value_int64 array_min(struct array_int a);
void array_free(struct array_int a);

struct str_array_int some_array_int(struct array_int array);
struct value_int64 some_value_int64(int64_t value);

#endif