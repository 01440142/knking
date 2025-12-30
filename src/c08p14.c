#include <stdio.h>

int main(void)
{
  char c[64] = {' '};
  int i, j, k, n[32] = {0}, a, b;

  printf("Enter a sentence: ");
  for (i = 1, j = 1; i < (int)(sizeof(c) / sizeof(c[0])); i++) {
    c[i] = getchar();
    if (c[i] == ' ') {
      n[j] = i;
      j++;
    } else if (c[i] == '.' || c[i] == '?' || c[i] == '!') {
      a = b = i;
      break;
    }
  }

  printf("Reversal of sentence:");
  for (i = j - 1; i >= 0; i--) {
    for (k = n[i]; k < b; k++) {
      printf("%c", c[k]);
    }
    b = n[i];
  }
  printf("%c\n", c[a]);

  return 0;
}
