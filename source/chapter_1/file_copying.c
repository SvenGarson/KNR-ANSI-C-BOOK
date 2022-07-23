#include <stdio.h>

int main()
{
  int next_char;

  next_char = getchar();
  while (next_char != EOF)
  {
    putchar(next_char);
    next_char = getchar();
  }

  printf("\nDone ...\n");

  return 0;
}
