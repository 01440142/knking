#include <stdio.h>

int main(void)
{
  int digits[10], i;

  printf("Enter %d numbers: ", (int)(sizeof(digits) / sizeof(digits[0])));
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    scanf("%d", &digits[i]);
  }

  printf("In reverse order:");
  for (i = (int)(sizeof(digits) / sizeof(digits[0])) - 1; i >= 0; i--) {
    printf(" %d", digits[i]);
  }
  printf("\n");

  return 0;
}
