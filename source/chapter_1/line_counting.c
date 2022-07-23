#include <stdio.h>

/* Count the number of lines entered up to EOF */
int main()
{
  int current_character;
  long int line_count = 0;

  while((current_character = getchar()) != EOF)
    if(current_character == '\n')
      ++line_count;

  printf("\n\nTotal of %ld lines read up to EOF\n", line_count);

  return 0;
}
