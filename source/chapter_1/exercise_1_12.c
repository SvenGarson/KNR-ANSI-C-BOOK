#include <stdio.h>

#define INSIDE_WORD 1
#define OUT_OF_WORD 0

/*
    Output every word input on a separate line.

    Edge cases:
      - Leading whitespace should be ignored and not be included in a word line
      - The first line should break line for the word only it there is leading
        characters that are not inside a word
*/
int main()
{
  int word_state = OUT_OF_WORD;
  int current_character;
  long int word_count = 0L;

  while((current_character = getchar()) != EOF)
  {
    /* Determine word state */
    const int current_character_is_word_separator =
      (current_character == ' ' || current_character == '\t' || current_character == '\n');
    const int new_word_state = current_character_is_word_separator ? OUT_OF_WORD : INSIDE_WORD;

    /*
      Output character if it is inside a word, and on a fresh line for every word
      apart from the first word
    */
    if (new_word_state == INSIDE_WORD && word_state == OUT_OF_WORD)
    {
      /* We just entered the first character of a word */
      ++word_count;
      putchar('\n');
    }
    word_state = new_word_state;
    putchar(current_character);
  }

  printf("\n\nRead a total of '%ld' words!\n", word_count);

  return 0;
}
