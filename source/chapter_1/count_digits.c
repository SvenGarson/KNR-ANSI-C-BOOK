#include <stdio.h>

#define NUMBER_OF_DIGITS 10
/*
    Count the following occurences:
      - digits from 0 to 9 using an array
      - whitespaces using a variable
      - any other using a single additional variable
*/
int main()
{
  int curr_char, digit_index;
  long int count_digits[NUMBER_OF_DIGITS];
  long int count_newlines, count_other;

  /* Initialize the digit count array */
  for (digit_index = 0; digit_index < NUMBER_OF_DIGITS; digit_index++)
  {
    count_digits[digit_index] = 0;
  }

  /* Count the different kinds of entered characters */
  while((curr_char = getchar()) != EOF)
  {
    if (curr_char >= '0' && curr_char <= '9')
    {
      const int relative_digit_index = curr_char - '0';
      ++count_digits[relative_digit_index];
    }
    else if (curr_char == '\n')
      ++count_newlines;
    else
      ++count_other;
  }

  /* Show results */
  printf("\nStatistics about the entered text:");
  printf("\n\tDigits entered:");
  for (digit_index = 0; digit_index < NUMBER_OF_DIGITS; digit_index++)
  {
    printf("\n\t\t%c: %ld", '0' + digit_index, count_digits[digit_index]);
  }
  printf("\n\tNewlines entered: %ld", count_newlines);
  printf("\n\tOther entered   : %ld", count_other);
  putchar('\n');

  /* To OS */
  return 0;
}
