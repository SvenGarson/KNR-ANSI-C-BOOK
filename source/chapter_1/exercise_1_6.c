#include <stdio.h>

int main()
{
  int entered_character;

  printf("\nEnter a character for comparison against eof: ");
  entered_character = getchar();

  printf("\nThe expression %c != EOF is '%d'\n\n", entered_character, entered_character != EOF);

  return 0;
}
