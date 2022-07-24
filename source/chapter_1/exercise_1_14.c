#include <stdio.h>

#define NUMBER_OF_CHARS_IN_CHARSET 256
#define HISTOGRAM_TERMINAL_CHARS_PER_FREQUENCY 25
/*
    This program draws a horizontal histogram of the frequency of input
    characters in terms of the total number of characters input.

    Do this for the full ASCII character range and output only frequencies
    for which a character was entered i.e do not output zero freqeuncies.

    The graph is not scaled to some max width in terms of terminal
    characters.

      Input character sequence: aaccababca
      Statistics:
        - Total chars: 10
        - 'a's       : 5
        - 'b's       : 2
        - 'c's       : 3

      Frequencies as floats:
        - 'a's       : 5 / 10 = 0.5
        - 'b's       : 2 / 10 = 0.2
        - 'c's       : 3 / 10 = 0.3

    The scaled histogram for a width of 10

      Scale integer frequencies:
        - 'a's       : 10 * 0.5 = 5
        - 'b's       : 10 * 0.2 = 2
        - 'c's       : 10 * 0.3 = 3

    1 | =====
    2 | ==
    3 | ===

*/

int main()
{
  /* Datapoints */
  int current_character;

  /* Establish the buffers to hold input data statistics */
  long int per_character_input_statistics[NUMBER_OF_CHARS_IN_CHARSET];
  float indexed_character_frequency;
  int terminal_scaled_character_frequency;
  int histo_column_index;
  int indexed_character_occurences;
  long int total_number_of_input_characters = 0;
  int input_stat_index;
  for (input_stat_index = 0; input_stat_index < NUMBER_OF_CHARS_IN_CHARSET; input_stat_index++)
    per_character_input_statistics[input_stat_index] = 0;

  /* Read all input and record the count of all input characters */
  printf("\n\nEnter a single line of text to generate a histogram of the input character frequency: ");
  while((current_character = getchar()) != EOF && current_character != '\n')
  {
    /* Increment the count of every sinlge input ASCII  */
    ++per_character_input_statistics[current_character];
    ++total_number_of_input_characters;
  }

  /*
      Determine the relevant frequencies based on the total number of
      input characters and output the histogram.
  */
  for (input_stat_index = 0; input_stat_index < NUMBER_OF_CHARS_IN_CHARSET; input_stat_index++)
  {
    indexed_character_occurences = per_character_input_statistics[input_stat_index];
    if (indexed_character_occurences == 0) continue;

    /*
        Adjust all shown int frequencies for when a character has a frequeny of less than one, which
        truncates to zero in the terminal scaled frequency value
    */
    indexed_character_frequency = (float)indexed_character_occurences / (float)total_number_of_input_characters;
    indexed_character_frequency += 1.0;
    terminal_scaled_character_frequency = (int)(indexed_character_frequency * HISTOGRAM_TERMINAL_CHARS_PER_FREQUENCY);

    printf("\n%3d - %3d | ", input_stat_index, input_stat_index);
    for (histo_column_index = 0; histo_column_index < terminal_scaled_character_frequency; histo_column_index++)
      putchar('=');
  }

  /* Distance to the next terminal output */
  printf("\n\n");

  /* To OS */
  return 0;
}
