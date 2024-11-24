#include "string_functions.h"

size_t str_len(char *str)
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }
    return i;
}

// ' ', '\t', '\n'
// Count words in string
uint32_t str_words(char *str)
{
    size_t i = 0;
    uint32_t count = 0;
    bool whitespace = false;
    bool word_started = false;
    while (str[i] != '\0')
    {
        whitespace = str[i] == ' ' || str[i] == '\t' || str[i] == '\n';
        if (word_started && whitespace && count != 0)
        {
            word_started = false;
        }
        if (!word_started && !whitespace)
        {
            ++count;
            word_started = true;
        }
        ++i;
    }
    return count;
}

// Return position of char in string
// Return -1 if char is not found
int32_t str_pos(char *str, char c)
{
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == c)
        {
            return (int32_t)i;
        }
    }
    return -1;
}

// Concatenate str2 to str1
void str_cat(char *str1, char *str2)
{
    size_t str1_len = str_len(str1);
    size_t i = 0;
    for (; str2[i] != '\0'; ++i)
    {
        str1[str1_len + i] = str2[i];
    }
    str1[str1_len + i] = '\0';
}

// Copy str2 to str1
void str_cpy(char *str1, char *str2)
{
    size_t i = 0;
    for (; str2[i] != '\0'; ++i)
    {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
}

// Compare strings
// 0  - strings are equal
// 1  - str1 > str2
// -1 - str1 < str2
int8_t str_cmp(char *str1, char *str2)
{
    size_t i = 0;
    for (; str1[i] != '\0'; ++i)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }
    if (str2[i])
    {
        return -1;
    }
    else
    {
        return 0;
    }
}