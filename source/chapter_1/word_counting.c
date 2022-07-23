#include <stdio.h>

#define INSIDE_WORD 1
#define OUT_OF_WORD 0

/*
    Count words in the input, where a word is a sequence of characters separated
    by a blank; tab or newline.
*/
int main()
{
  /*
      Start with state to be OUT of a word
      For every input character
        determine if char is in or out of a word (considering blank; tab and newline)
        if IN a word
          increment word count
        if outside a word
          do not care here

      Edge cases:
        - First word detectedd properly
        - separation chars actually separate words:
            A) I am inevitable (spaces and three words)
            B) I \t am \t inevitable (tabs and three words)
            C) I\nam\ninevitable (newlines and three words)
  */

  int word_state = OUT_OF_WORD;
  int current_character;
  long int word_count = 0L;

  while((current_character = getchar()) != EOF)
  {
    /* Determine word state */
    const int current_character_is_word_separator =
      (current_character == ' ' || current_character == '\t' || current_character == '\n');
    const int new_word_state = current_character_is_word_separator ? OUT_OF_WORD : INSIDE_WORD;

    if (new_word_state == INSIDE_WORD && word_state == OUT_OF_WORD)
    {
      /* We just entered the first character of a word */
      printf("\n'%c' starts a new word", current_character);
      ++word_count;
    }
    word_state = new_word_state;
  }

  printf("\n\nRead a total of '%ld' words!\n", word_count);

  return 0;
}
