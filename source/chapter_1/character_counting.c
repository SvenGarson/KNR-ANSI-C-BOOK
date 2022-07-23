#include <stdio.h>

int main()
{
  int current_char;
  long int character_count;

  while((current_char = getchar()) != EOF)
    ++character_count;

  printf("\n\nRead a total of %ld characters. Done ...\n", character_count);

  return 0;
}
