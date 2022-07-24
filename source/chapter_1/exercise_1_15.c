#include <stdio.h>

#define FAHRENHEIT_FLOOR 0      /* Lower limit of the conversion table */
#define FAHRENHEIT_CEILING 300  /* Upper limit of the conversion table */
#define FAHRENHEIT_STEP_SIZE 20 /* Step size ... */

/*
    Print Fahrenheit-Celsius table for Fahrenheit values
    in the range 300; 280; ...; 0 using a tight for loop
    with symbolic constants.

    This time use a function for the conversion!
*/
float fahrenheit_to_celsius(float fahrenheit_value);

int main()
{

  int fahrenheit;
  printf("\nFahrenheit\t\tCelsius");
  for(fahrenheit = FAHRENHEIT_CEILING; fahrenheit >= FAHRENHEIT_FLOOR; fahrenheit -= FAHRENHEIT_STEP_SIZE)
  {
    printf("\n%-10.1f\t\t%-6.1f", (float)fahrenheit, fahrenheit_to_celsius(fahrenheit));
  }

  printf("\n\nDone\n");
}

float fahrenheit_to_celsius(float fahrenheit_value)
{
  return (5.0f / 9.0f) * (fahrenheit_value - 32);
}
