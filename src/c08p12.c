#include <ctype.h>
#include <stdio.h>

int main(void)
{
  int s = 0, i;
  char p[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10},
       a[26], c;

  for (i = 0; i < (int)(sizeof(a) / sizeof(a[0])); i++) {
    a[i] = i + 65;
  }

  printf("Enter a word: ");
  while ((c = toupper(getchar())) != '\n') {
    for (i = 0; i < (int)(sizeof(a) / sizeof(a[0])); i++) {
      if (c == a[i]) {
        s += p[i];
        break;
      }
    }
  }

  printf("Scrabble value: %d\n", s);

  return 0;
}
