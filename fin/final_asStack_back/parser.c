#include "./headers/parser.h"

int find_command(char* command)
{
    for (size_t i = 0; i < instructions_count; ++i)
    {
        if (0 == strcmp(command, instructions[i].mnemonic))
        {
            return i;
        }
    }
    return -1;
}

// parse commands file
int parse(union UCom* command_list, size_t commands_limit)
{
    FILE * f = fopen("commands.txt", "r");
    if (NULL == f)
    {
        printf("File not found\n");
        return 0;
    }
    char command[8];
    int64_t arg;
    int args = 0;
    size_t cmd_number = 0;

    while(true)
    {
        if (cmd_number - 1 == commands_limit) {
            printf("Command stack overflow. Stop command not found.\nCurrent limit: %zu commands\n", commands_limit);
            return -1;
        }
        args = fscanf(f, "%s%" SCNd64, command, &arg);
        if (args == EOF)
        {
            break;
        }
        int command_id = find_command(command);
        if (command_id == -1)
        {
            printf("Command not found: %s\n", command);
            return -1;
        }
        if (args != 2 && instructions[command_id].argtype==EAT_I64)
        {
            printf("Missing argument for command: %s\n", command);
            return -1;
        } else if (instructions[command_id].argtype==EAT_I64) {
            command_list[cmd_number++] = (union UCom){.com_arg64 = {(enum EOpCode)command_id, .arg=arg}};
            continue;
        }
        command_list[cmd_number++] = (union UCom){(enum EOpCode)command_id};
        if (command_id == EOC_STOP)
        {
            break;
        }
    }
 
    fclose(f);

    return 0;
}
