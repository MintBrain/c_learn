#include "./headers/commands.h"

const struct SDescr instructions[] = {
    [EOC_LD] = {"LD", EAT_I64, false, 0, 0},
    [EOC_LDN] = {"LDN", EAT_I64, false, 0, 0},
    [EOC_ST] = {"ST", EAT_NOARG, false, 0, 0},
    [EOC_STN] = {"STN", EAT_NOARG, false, 0, 0},
    [EOC_S] = {"S", EAT_NOARG, false, 0, 0},
    [EOC_R] = {"R", EAT_NOARG, false, 0, 0},
    [EOC_AND] = {"AND", EAT_I64, false, 0, 0},
    [EOC_ANDN] = {"ANDN", EAT_I64, false, 0, 0},
    [EOC_OR] = {"OR", EAT_I64, false, 0, 0},
    [EOC_ORN] = {"ORN", EAT_I64, false, 0, 0},
    [EOC_XOR] = {"XOR", EAT_I64, false, 0, 0},
    [EOC_XORN] = {"XORN", EAT_I64, false, 0, 0},
    [EOC_NOT] = {"NOT", EAT_NOARG, false, 0, 0},
    [EOC_ADD] = {"ADD", EAT_I64, false, 0, 0},
    [EOC_SUB] = {"SUB", EAT_I64, false, 0, 0},
    [EOC_MUL] = {"MUL", EAT_I64, false, 0, 0},
    [EOC_DIV] = {"DIV", EAT_I64, false, 0, 0},
    [EOC_GT] = {"GT", EAT_I64, false, 0, 0},
    [EOC_GE] = {"GE", EAT_I64, false, 0, 0},
    [EOC_EQ] = {"EQ", EAT_I64, false, 0, 0},
    [EOC_NE] = {"NE", EAT_I64, false, 0, 0},
    [EOC_LE] = {"LE", EAT_I64, false, 0, 0},
    [EOC_LT] = {"LT", EAT_I64, false, 0, 0},
    [EOC_JMP] = {"JMP", EAT_STR, true, 0, 0},
    [EOC_JMPC] = {"JMPC", EAT_STR, true, 0, 0},
    [EOC_JMPCN] = {"JMPCN", EAT_STR, true, 0, 0},
    [EOC_RET] = {"RET", EAT_NOARG, true, 0, 0}};

const size_t instructions_count = COUNT_OF(instructions);

struct SState state_create(const union UCom *ip)
{
    return (struct SState){.ip = ip, .ip_base = ip, .ACC = 0, .ACC_type = EAT_NOARG, .is_run = true};
}

void state_destroy(struct SState *state)
{
    if (state)
    {
        //        stack_destroy(&state->data_stack);
    }
}

/*
    LD	    Загрузить значение операнда в аккумулятор
    LDN	    Загрузить обратное значение операнда в аккумулятор
    ST	    Присвоить значение аккумулятора операнду
    STN	    Присвоить обратное значение аккумулятора операнду
    S	    Если значение аккумулятора TRUE, установить логический операнд
    R	    Если значение аккумулятора FALSE, сбросить логический операнд
    AND	    Поразрядное И аккумулятора и операнда
    ANDN	Поразрядное И аккумулятора и обратного операнда
    OR	    Поразрядное ИЛИ аккумулятора и операнда
    ORN	    Поразрядное ИЛИ аккумулятора и обратного операнда
    XOR	    Поразрядное разделительное ИЛИ аккумулятора и операнда
    XORN	Поразрядное разделительное ИЛИ аккумулятора и обратного операнда
    NOT	    Поразрядная инверсия аккумулятора
    ADD	    Сложение аккумулятора и операнда, результат записывается в аккумулятор
    SUB	    Вычитание операнда из аккумулятора, результат записывается в аккумулятор
    MUL	    Умножение аккумулятора на операнд, результат записывается в аккумулятор
    DIV	    Деление аккумулятора на операнд, результат записывается в аккумулятор
    GT	    Значение аккумулятора сравнивается со значением операнда(>(greater than)). Значение (TRUE или FALSE) записывается в аккумулятор
    GE	    Значение аккумулятора сравнивается со значением операнда(>=greater than or equal)). Значение (TRUE или FALSE) записывается в аккумулятор
    EQ	    Значение аккумулятора сравнивается со значением операнда (=(equal)). Значение (TRUE или FALSE) записывается в аккумулятор
    NE	    Значение аккумулятора сравнивается со значением операнда (<>(not equal). Значение (TRUE или FALSE) записывается в аккумулятор
    LE	    Значение аккумулятора сравнивается со значением операнда (<=(less than or equal to)). Значение (TRUE или FALSE) записывается в аккумулятор
    LT	    Значение аккумулятора сравнивается со значением операнда (<(less than)). Значение (TRUE или FALSE) записывается в аккумулятор
    JMP	    Переход к метке
    JMPC	Переход к метке при условии, что значение аккумулятора TRUE
    JMPCN	Переход к метке при условии, что значение аккумулятора FALSE
    RET	    Выход из POU и возврат в вызывающую программу
*/