#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define BIT(number, index) ((number >> index) & 0x1)


// Логическое выражение не(не X и Y) или (X и не Z) записать нa алгоритмиче­ском языке и составить для него таблицу истинности ,
// то есть опреде­лить его значение для всех возможных значений логических переменных X У Z.
void task1()
{
    printf("Task1\n");
    printf("X\tY\tZ\t!(!X and Y) or (X and !Z)\n");
    for (uint8_t i = 0; i != 8; i++)
    {
        bool x = BIT(i, 2);
        bool y = BIT(i, 1);
        bool z = BIT(i, 0);

        printf("%d\t%d\t%d\t", x, y, z);
        printf("%d\n", !(!x && y) || (x && !z));
    }
    printf("\n");
}
