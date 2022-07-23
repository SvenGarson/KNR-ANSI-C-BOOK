#include <stdio.h>

/* Count the number of lines entered up to EOF */
int main()
{
  int current_character;
  long int count_blanks = 0L;
  long int count_tabs = 0L;
  long int count_newlines = 0L;

  while((current_character = getchar()) != EOF)
  {
    switch(current_character)
    {
      case ' ' :
        ++count_blanks;
        break;
      case '\t':
        ++count_tabs;
        break;
      case '\n':
        ++count_newlines;
        break;
    }
  }

  printf("\nTotal occurences of special characters:");
  printf("\n  Blanks  : %ld", count_blanks);
  printf("\n  Tabs    : %ld", count_tabs);
  printf("\n  Newlines: %ld", count_newlines);
  printf("\n\n");

  return 0;
}
