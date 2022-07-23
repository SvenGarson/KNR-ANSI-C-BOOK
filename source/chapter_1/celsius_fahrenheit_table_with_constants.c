#include <stdio.h>

#define FAHRENHEIT_FLOOR 0      /* Lower limit of the conversion table */
#define FAHRENHEIT_CEILING 300  /* Upper limit of the conversion table */
#define FAHRENHEIT_STEP_SIZE 20 /* Step size ... */

/*
    Print Fahrenheit-Celsius table for Fahrenheit values
    in the range 300; 280; ...; 0 using a tight for loop
    with symbolic constants
*/
int main()
{

  int fahrenheit;
  printf("\nFahrenheit\t\tCelsius");
  for(fahrenheit = FAHRENHEIT_CEILING; fahrenheit >= FAHRENHEIT_FLOOR; fahrenheit -= FAHRENHEIT_STEP_SIZE)
  {
    printf("\n%-10.1f\t\t%-6.1f", (float)fahrenheit, (5.0f / 9.0f) * (fahrenheit - 32));
  }

  printf("\n\nDone\n");
}
