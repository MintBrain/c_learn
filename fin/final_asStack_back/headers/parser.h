#ifndef _PARSER_H_
#define _PARSER_H_

#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "commands.h"

int parse(union UCom* command_list, size_t commands_limit);


#endif