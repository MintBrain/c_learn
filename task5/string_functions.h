#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

size_t str_len(char *str);
uint32_t str_words(char *str);
int32_t str_pos(char *str, char c);
void str_cat(char *str1, char *str2);
void str_cpy(char *str1, char *str2);
int8_t str_cmp(char *str1, char *str2);

#endif