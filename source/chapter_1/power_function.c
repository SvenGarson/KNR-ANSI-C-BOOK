#include <stdio.h>

int power(int base, int exponent);

int main()
{
  int base_index;

  for (base_index = 0; base_index <= 10; base_index++)
  {
    printf("\n%10d %10d %10d", base_index, power(2, base_index), power(-3, base_index));
  }

  printf("\n\n");

  return 0;
}

int power(int base, int exponent)
{
  int power_result = 1;
  int exponent_index = 0;

  for (exponent_index = 0; exponent_index < exponent; exponent_index++)
    power_result *= base;

  return power_result;
}
