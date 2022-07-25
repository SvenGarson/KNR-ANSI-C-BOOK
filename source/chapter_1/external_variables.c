#include <stdio.h>

int some_external_value = 15;

void log_external_value(void);
void log_later_external_value(void);

int main()
{
  log_external_value();
  log_later_external_value();

  return 0;
}

void log_external_value(void)
{
  printf("\nExternal value: %d", some_external_value);
}

void log_later_external_value(void)
{
  extern int some_later_external_variable;
  printf("\nLater external value: %d", some_later_external_variable);
}

int some_later_external_variable = 99;
