#include "./headers/parser.h"

int find_command(char *command)
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

void processe_jmp(struct SJMP_L *jmp_labl)
{
    size_t connected_jmp = 0;
    for (size_t i = 0; i < jmp_labl->jmps_count; ++i)
    {
        for (size_t j = 0; j < jmp_labl->labels_count; ++j)
        {
            if (0 == strcmp(jmp_labl->jmps[i].label, jmp_labl->labels[j].label))
            {
                *jmp_labl->jmps[i].jmp_arg_ptr = jmp_labl->labels[j].command_id;
                ++connected_jmp;
                free(jmp_labl->labels[j].label);
                free(jmp_labl->jmps[i].label);
            }
        }
    }
    if (connected_jmp != jmp_labl->jmps_count)
    {
        printf("Only %zu jumpers connected\n");
    }
}

void print_cmd_list(union UCom *command_list)
{
    union UCom *cur = command_list;
    while (cur->opcode != EOC_RET)
    {
        printf("%s %" PRId64 "\n", instructions[cur->opcode].mnemonic, cur->com_arg64.arg);
        cur++;
    }
}

// parse commands file
int parse(union UCom *command_list, size_t commands_limit)
{
    FILE *f = fopen("commands.txt", "r");
    if (NULL == f)
    {
        printf("File not found\n");
        return 0;
    }
    char command[8];
    char arg1[100];
    int64_t arg;
    int args = 0;
    size_t cmd_number = 0;

    struct SJMP jumpers[commands_limit / 2];
    struct SLabel labels[commands_limit / 2];
    struct SJMP_L jmp_labl = {.jmps = jumpers, .labels = labels, .jmps_count = 0, .labels_count = 0};

    while (true)
    {
        if (cmd_number - 1 == commands_limit)
        {
            printf("Command stack overflow. Stop command not found.\nCurrent limit: %zu commands\n", commands_limit);
            return -1;
        }
        int f_cur_pos = f->_cnt;
        args = fscanf(f, "%s %" SCNd64, command, &arg);

        if (args == EOF)
        {
            break;
        }

        int command_id = find_command(command);
        if (command_id == -1)
        {
            if (command[strlen(command) - 1] == ':')
            {
                command[strlen(command) - 1] = '\0';
                char *temp = malloc(sizeof(char) * 50);
                strcpy(temp, command);
                jmp_labl.labels[jmp_labl.labels_count].label = temp;
                jmp_labl.labels[jmp_labl.labels_count].command_id = cmd_number;
                ++jmp_labl.labels_count;
                continue;
            }
            printf("Command not found: %s\n", command);
            return -1;
        }

        if (instructions[command_id].argtype == EAT_STR)
        {
            fseek(f, f->_cnt - f_cur_pos, SEEK_CUR);
            args = fscanf(f, "%s %s", command, arg1);
            if (args != 2)
            {
                printf("Missing argument for command: %s\n", command);
                return -1;
            }
            char *temp = malloc(sizeof(char) * 50);
            strcpy(temp, arg1);
            command_list[cmd_number++] = (union UCom){.com_arg64 = {(enum EOpCode)command_id, .arg = 0}};
            jmp_labl.jmps[jmp_labl.jmps_count].label = temp;
            jmp_labl.jmps[jmp_labl.jmps_count].jmp_arg_ptr = &command_list[cmd_number - 1].com_arg64.arg;
            ++jmp_labl.jmps_count;
            continue;
        }
        
        if (args != 2 && instructions[command_id].argtype == EAT_I64)
        {
            printf("Missing argument for command: %s\n", command);
            return -1;
        }
        else if (instructions[command_id].argtype == EAT_I64)
        {
            command_list[cmd_number++] = (union UCom){.com_arg64 = {(enum EOpCode)command_id, .arg = arg}};
            continue;
        }

        command_list[cmd_number++] = (union UCom){(enum EOpCode)command_id};
        if (command_id == EOC_RET)
        {
            break;
        }
    }
    processe_jmp(&jmp_labl);
    //    print_cmd_list(command_list);
    fclose(f);

    return 0;
}
