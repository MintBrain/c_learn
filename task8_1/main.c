#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

enum Etype
{
    ET_INT,
    ET_STRING
};

struct SInt_Str
{
    enum Etype type;
    union
    {
        char *s;
        int64_t i;
    };
};

size_t str_len(char *str)
{
    if (str == NULL)
    {
        return 0;
    }
    size_t i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }
    return i;
}

// Copy str2 to str1
void str_cpy(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        return;
    }
    
    size_t i = 0;
    for (; str2[i] != '\0'; ++i)
    {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
}

struct SInt_Str from_string(char *s)
{
    char *s_m = malloc(sizeof(char) * str_len(s));
    str_cpy(s_m, s);
    return (struct SInt_Str){.type = ET_STRING, .s = s_m};
}

struct SInt_Str from_int(int64_t i)
{
    return (struct SInt_Str){.type = ET_INT, .i = i};
}

void string_destroy(struct SInt_Str str)
{
    if (str.type == ET_STRING && str.s != NULL)
    {
        free(str.s);
    }
}

void print(struct SInt_Str val)
{
    switch (val.type)
    {
    case ET_INT:
        printf("int\n");
        break;

    case ET_STRING:
        printf("%s\n", val.s);
        break;

    default:
        break;
    }
}

int main()
{
    char *s = "adsfa";
    struct SInt_Str str = from_string(s);
    print(str);
    string_destroy(str);

    int64_t i = 213123;
    struct SInt_Str str2 = from_int(i);
    print(str2);

    return 0;
}