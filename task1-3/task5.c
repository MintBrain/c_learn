#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Дано вещественное число Х(|X| < 1) и целое число N (> 0).
// Найти значе­ние X - Х^2/2 + X^З/З - + (-1 )^N-1X^N/N.
// Полученное число является при­ ближенным значением функции In в точке 1+X.
void task5()
{
  printf("Task5\n");
  double x;
  uint32_t n;
  scanf("%lf%u", &x, &n);

  // Цикл с предусловием
  size_t i = 1;
  double cur_val = 0;
  while (i <= n)
  {
    cur_val += pow(-1, i - 1) * pow(x, i) / i;
    i += 1;
  }
  printf("Цикл с предусловием = ");
  printf("%lf\n", cur_val);

  // Цикл с постусловием
  i = 1;
  cur_val = 0;
  do
  {
    cur_val += pow(-1, i - 1) * pow(x, i) / i;
    i += 1;
  } while (i <= n);
  printf("Цикл с постусловием = ");
  printf("%lf\n", cur_val);

  // Цикл с параметром
  cur_val = 0;
  for (i = 1; i <= n; i++)
  {
    cur_val += pow(-1, i - 1) * pow(x, i) / i;
  }
  printf("Цикл с параметром   = ");
  printf("%lf\n", cur_val);
  printf("\n");
}

void main(){
task5();}
