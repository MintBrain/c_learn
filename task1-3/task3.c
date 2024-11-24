#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Написать блок схему и программу вычисления функции y(x) для всех различных вариантов входных параметров.
// Ввести с клавиатуры x, вывести значение функции для всех вариантов.
double calc(double x, double a, double b, double z)
{
  if (x <= 5 * a)
  {
    return 2.5 * b * b + a * x - 4.5 * cos(x * z);
  }
  else if (x > b)
  {
    return pow((a * a - 5.4 * x), 3) + log(x * z);
  }
  else
  {
    return sqrt(6.5 * b * b + (a - x * x * x * z));
  }
}

void task3()
{
  printf("Task3\n");
  double x;
  scanf("%lf", &x);

  printf("%lf\n", calc(x, 0.5, 4.5, exp(0.5 * x)));
  printf("%lf\n", calc(x, 0.5, 3.7, exp(2 * 0.5 * x)));
  printf("%lf\n", calc(x, 0.5, 2.7, exp(2.5 * 0.5 * x)));
  printf("\n");
}