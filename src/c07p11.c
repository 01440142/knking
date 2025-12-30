#include <stdio.h>

int main (void)
{
  char ch, temp;

  printf("Enter a first and last name: ");

  while ((ch = getchar()) == ' ')
    ;
  while (getchar() != ' ')
    ;
  while ((temp = getchar()) != '\n') {
    if (temp == ' ')
      continue;
    printf("%c", temp);
  }

  printf(", %c.\n", ch);

  return 0;
}
