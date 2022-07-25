#include <stdio.h>

#define SPACES_PER_TAB_COLUMN 3
#define DEBUG_TAB_COLUMNS_TO_DRAW 10
/*
    Requirements:
      - read from the stdinput
      - replace tabs with the number spaces to fill the gap until the
        next tab spot
      - assume the tabs to be at fixed column width position
      - account for characters breaking the tab boundary and fill with
        spaces accordingly

    Edge-cases:
      - [OK] empty input
      - [OK] input tabs at the tab column so the numbers of blanks is the width
        of a tab
      - [OK] input breaks over a tab boundary, requiring less blanks to the
        next 'tab column'

    Illustration:

      Say a tab at a fixed interval of 3
      TINT: tab interval = 3

      --T--T--T--T--T
      >>  2
      x>  1
      xx> 0
      xxx>> 2
      xxxx> 1
      xxxxx> 0

      skips = TINT - 1 - n
            = 2 - (n % TINT)
      skips = (TINT - 1) - (n % TING)

      n:0 => s:2 => ctrl=0
      n:1 => s:1 => ctrl=1
      n:2 => s:0 => ctrl=0
      n:3 => s:2 => ctrl=2
      n:4 => s:1 => ctrl=1
      n:5 => s:0 => ctrl=0

    Elaborations:
      - when a tab is hit, padd the input with blanks up to the next tab position
      - print a guideline for checking the algorithm visually
      - [OK] stop when hitting newline or EOF

    Pseudo:
      - for every character at index (starting at 0)
        - when EOF or newline -> done
        - if char is a tab
          - pad with blanks to next tab column
        - else
          - log the char
*/
int main()
{
  int current_character;
  int line_character_index = 0;
  int blanks_til_next_tab_column;
  int blank_fill_index;
  int character_column_index;
  int tab_column_index;

  while((current_character = getchar()) != EOF && current_character != '\n')
  {
    if (current_character == '\t')
    {
      /* Padd to next tab column start */
      blanks_til_next_tab_column =
        (SPACES_PER_TAB_COLUMN - 1) - (line_character_index % SPACES_PER_TAB_COLUMN);
      for(blank_fill_index = 0; blank_fill_index < blanks_til_next_tab_column; ++blank_fill_index)
        putchar(' ');
    }
    else
    {
      putchar(current_character);
    }

    ++line_character_index;
  }

  /* Draw tab columns for visual testing */
  putchar('\n');
  for(tab_column_index = 0; tab_column_index < DEBUG_TAB_COLUMNS_TO_DRAW; ++tab_column_index)
  {
    for(character_column_index = 0; character_column_index < SPACES_PER_TAB_COLUMN; ++character_column_index)
    {
      if (character_column_index >= SPACES_PER_TAB_COLUMN - 1)
        putchar('T');
      else
        putchar('-');
    }
  }
  printf("\n");

  printf("\nDone!\n\n");

  return 0;
}
