#include <stdio.h>

int main()
{
  int next_char;
  while ((next_char = getchar()) != EOF)
  {
    putchar(next_char);
  }

  printf("\nReached EOF (%d) - Done ...\n", EOF);

  return 0;
}
