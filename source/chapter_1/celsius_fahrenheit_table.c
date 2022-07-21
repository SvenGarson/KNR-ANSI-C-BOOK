#include <stdio.h>

/*
    Print Fahrenheit-Celsius table for Fahrenheit values
    in the range 0, 20, ..., 300
*/
int main()
{
  float fahrenheit, celsius;
  int lower, upper, stepsize;
  lower = 0;
  upper = 300;
  stepsize = 20;

  fahrenheit = lower;
  while (fahrenheit <= upper)
  {
    celsius = (5.0f / 9.0f) * (fahrenheit - 32);
    printf("%3.0f\t%6.1f\n", fahrenheit, celsius);
    fahrenheit += stepsize;
  }

  printf("\nDone ...\n");
}
