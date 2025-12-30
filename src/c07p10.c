#include <ctype.h>
#include <stdio.h>

int main(void)
{
  char ch;
  int vowels = 0;

  printf("Enter a sentence: ");

  while ((ch = toupper(getchar())) != '\n')
    switch (ch) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        vowels++; break;
    }
  printf("Your sentence contains %d vowels.\n", vowels);

  return 0;
}
