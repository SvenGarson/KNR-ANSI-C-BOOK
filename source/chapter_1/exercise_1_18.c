#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define MIN_LINE_LENGTH_FOR_PRINTING 5

void reverse_line(char reversed_line_target[], char line_source[], int source_line_length);
int getline(char line_target[], int max_line_length);
void copy(char line_target[], char line_source[]);

int main()
{
  int current_line_length, max_line_length;
  char current_line[MAX_LINE_LENGTH];
  char reversed_line[MAX_LINE_LENGTH];

  while((current_line_length = getline(current_line, MAX_LINE_LENGTH)) > 0)
  {
    /* Remove trailing blanks and newline from the input line */
    reverse_line(reversed_line, current_line, current_line_length);
    printf("\nInput   : %s", current_line);
    printf("\nReversed: %s\n\n", reversed_line);
  }

  printf("\nDone!\n\n");

  /* To OS */
  return 0;
}

void reverse_line(char reversed_line_target[], char line_source[], int source_line_length)
{
  /* Assume the reversed line target is big enough to hold the reversed string */
  int copy_index;
  for (copy_index = 0; copy_index < source_line_length; copy_index++)
  {
    reversed_line_target[copy_index] = line_source[source_line_length - 1 - copy_index];
  }

  reversed_line_target[copy_index] = '\0';
}

int getline(char line_target[], int max_line_length)
{
  /* Read a line up to max length - 1 and null terminate the result */
  int next_char, char_idx;
  int copied_string_length = 0;
  for (char_idx = 0; char_idx < max_line_length - 1 && (next_char = getchar()) != EOF && next_char != '\n'; ++char_idx)
  {
    line_target[char_idx] = next_char;
    ++copied_string_length;
  }

  /* If last char was a newline, add it to the end of the tracked string */
  if (next_char == '\n')
  {
    line_target[char_idx] = next_char;
    ++char_idx;
  }

  line_target[char_idx] = '\0';

  return copied_string_length;;
}

void copy(char line_target[], char line_source[])
{
  /* Copy line source into line target - assume the target is big enough*/
  int copy_index = 0;

  while ((line_target[copy_index] = line_source[copy_index]) != '\0')
    ++copy_index;
}
