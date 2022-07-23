#include <stdio.h>

/*
    Print Fahrenheit-Celsius table for Fahrenheit values
    in the range 300; 280; ...; 0 using a tight for loop
*/
int main()
{

  int fahrenheit;
  printf("\nFahrenheit\t\tCelsius");
  for(fahrenheit = 300; fahrenheit >= 0; fahrenheit -= 20)
  {
    printf("\n%-10.1f\t\t%-6.1f", (float)fahrenheit, (5.0f / 9.0f) * (fahrenheit - 32));
  }

  printf("\n\nDone\n");
}
