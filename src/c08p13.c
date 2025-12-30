#include <stdio.h>

int main(void)
{
  char c1, c2, c[20];
  int i, b;

  printf("Enter a first and last name: ");
  c1 = getchar();

  while (getchar() != ' ') {
    continue;
  }

  for (i = 0; i < (int)(sizeof(c) / sizeof(c[0])); i++) {
    if ((c2 = getchar()) == '\n') {
      b = i;
      break;
    }
    c[i] = c2;
  }

  printf("You entered the name: ");
  for (i = 0; i < b; i++) {
    printf("%c", c[i]);
  }
  printf(", %c.\n", c1);

  return 0;
}
