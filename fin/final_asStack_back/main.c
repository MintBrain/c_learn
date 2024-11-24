#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "./headers/stack.h"
#include "./headers/commands.h"
#include "./headers/interpreter.h"
#include "./headers/parser.h"

#define COMMANDS_LIMIT 100

int main()
{
    union UCom command_list[COMMANDS_LIMIT];
    if (parse(command_list, COMMANDS_LIMIT) == -1)
    {
        return 0;
    }
    printf("Readed file\n");
    interpret_program(command_list);

    return 0;
}

/*
// stack
PUSH n
POP
SWAP
DUP

// math
IADD (b a => a + b)
ISUB (b a => a - b)
IMUL (b a => a * b)
IDIV (b a => a / b)
IMOD (b a => a % b)
INEG (a   => -a)

// RW
IPRINT
IREAD
ICMP (b a => if(a < b) -1; if(a > b) 1; if (a == b) 0;)
STOP

//JUMPS
JZ <arg>
JMP <arg>
*/

/*
        {EOC_IREAD},
        {EOC_IREAD},
        {EOC_DUP},
        {.com_arg64 = {EOC_PUSH, .arg = 10}},
        {EOC_IMUL},
        {EOC_IADD},
        {EOC_IADD},
        {EOC_IPRINT},
        {EOC_STOP}
*/