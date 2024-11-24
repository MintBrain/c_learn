#include <stdio.h>
#include <stdint.h>

// Ввести с клавиатуры три числа. Вывести на экран наименьшее из них.
void task2()
{
  printf("Task2\n");
  int32_t a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a <= b && a <= c)
  {
    printf("%d\n", a);
  }
  else if (b <= c)
  {
    printf("%d\n", b);
  }
  else
  {
    printf("%d\n", c);
  }
  printf("\n");
}