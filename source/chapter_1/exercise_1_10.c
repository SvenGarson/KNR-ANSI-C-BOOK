#include <stdio.h>

/* Copy input to output where certain control character are replaced by a redable string */
int main()
{

  int current_character;
  while((current_character = getchar()) != EOF)
  {
    switch(current_character)
    {
      case '\t':
        printf("\\t");
        break;
      case '\b':
        printf("\\b");
        break;
      case '\\':
        printf("\\\\");
        break;
      default:
        putchar(current_character);
        break;
    }
  }

  printf("\n\nDone!\n");

  return 0;
}
