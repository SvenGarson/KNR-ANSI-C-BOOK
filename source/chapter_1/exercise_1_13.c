#include <stdio.h>

#define INSIDE_WORD 1
#define OUT_OF_WORD 0
/*
    This program draws a horizontal histogram of the input words.

    The graph is not scaled to some max width in terms of terminal
    characters but the count is taken as is, example:

      Input character sequence: This is gonna go very well indeed
      Word lengths            : 4    2  5     2  4    4    6

    The unscaled histogram:

      1 | ====
      2 | ==
      3 | =====
      4 | ==
      5 | ====
      6 | ====
      7 | ======
*/

int main()
{
  int curr_char, histo_char_index;
  int recorded_word_index = 1;
  int current_word_state = OUT_OF_WORD;
  int previous_word_state = OUT_OF_WORD;
  long int chars_in_current_word = 0L;

  while((curr_char = getchar()) != EOF)
  {
    /*
        Count word length and output and output a single line that represents
        the length of the input for every word in full length
    */
    const int current_char_is_out_of_word =
      (curr_char == ' ' || curr_char == '\t' || curr_char == '\n');
    current_word_state = current_char_is_out_of_word ? OUT_OF_WORD : INSIDE_WORD;

    /* Detecting entering, staying inside and leaving a word*/
    if (previous_word_state == OUT_OF_WORD && current_word_state == INSIDE_WORD)
    {
      /* Entering a word */
      chars_in_current_word = 1;
    }
    else if (previous_word_state == INSIDE_WORD && current_word_state == INSIDE_WORD)
    {
      /* Staying inside a word */
      ++chars_in_current_word;
    }
    else if (previous_word_state == INSIDE_WORD && current_word_state == OUT_OF_WORD)
    {
      /* Exiting inside a word - Draw a histogram line for the recorded length */
      printf("\n%3d | ", recorded_word_index++);
      for(histo_char_index = 0; histo_char_index < chars_in_current_word; histo_char_index++)
      {
        putchar('=');
      }
    }

    /*
        Keep track of the previous word states to differentiate entering
        and staying inside a word on a per character basis
    */
    previous_word_state = current_word_state;

    if (curr_char == '\n') break;
  }

  printf("\n\n");

  /* To OS */
  return 0;
}
