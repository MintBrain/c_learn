#include "headers/main.h"

int main()
{
    union UCom command_list[COMMANDS_LIMIT];
    if (parse(command_list, COMMANDS_LIMIT) == -1)
    {
        return 0;
    }
    printf("Readed file\n");
    interpret_program(command_list);
    printf("Program finished\n");

    return 0;
}