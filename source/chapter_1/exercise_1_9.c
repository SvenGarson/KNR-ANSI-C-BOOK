#include <stdio.h>

/* Copy input to output where multiple blanks are replaced with a single blank */
int main()
{
  /*
      Since reading with getchar up to EOF reads a line up a newline at a time,
      we want to output a blank only if there was no previous blank.

      Some edge cases are:
        - When the previous character is a blank, do not print another blank
        - When we hit a non-blank character, the next blank is output, this
          includes newlines

      Testing
        - multiple blanks output as single blank (use another char for testing)
        - blanks after newline are output once

      Pseudo code:
        While input not EOF
          if current character is not a blank
            print anyhow
          else
            if last character was not a blank
              print blank
          keep track of last character
  */
  const char BLANK_CHARACTER = ' ';
  int current_character;
  int previous_character = 'A';

  while((current_character = getchar()) != EOF)
  {
    /* Skip printing consecutive blank character */
    if (current_character == BLANK_CHARACTER && previous_character == BLANK_CHARACTER)
    {
      previous_character = current_character;
      continue;
    }

    putchar(current_character);
    previous_character = current_character;
  }

  printf("\n\nDone!\n");

  return 0;
}
