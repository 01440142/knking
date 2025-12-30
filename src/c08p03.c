#include <stdio.h>

int main(void)
{
  int digits[10] = {0}, i;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);
  while (n > 0) {
    digits[n % 10] += 1;
    n /= 10;
    printf("Enter a number: ");
    scanf("%ld", &n);
  }

  printf("Digit:\t\t");
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    printf("%d ", i);
  }
  printf("\nOccurrences:\t");
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    printf("%d ", digits[i]);
  }
  printf("\n");

  return 0;
}
