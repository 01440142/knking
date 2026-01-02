#include <stdio.h>

int main(void)
{
  char ch;
  int delimiter = 0, words = 1;

  printf("Enter an sentence: ");
  while ((ch = getchar()) != '\n')
    ch == ' ' ? delimiter++ : words++;
  printf("Average word length: %.1f\n", (float) words / delimiter);

  return 0;
}
