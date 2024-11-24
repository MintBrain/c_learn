#ifndef _PARSER_H_
#define _PARSER_H_

#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <malloc.h>
#include "commands.h"

struct SJMP
{
    int64_t *jmp_arg_ptr;
    char *label;
};

struct SLabel
{
    char *label;
    size_t command_id;
};

struct SJMP_L
{
    struct SJMP *jmps;
    struct SLabel *labels;
    size_t jmps_count;
    size_t labels_count;
};

int parse(union UCom *command_list, size_t commands_limit);

#endif