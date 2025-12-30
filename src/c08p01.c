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
  }
  printf("Repeated digit(s): ");
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    if (digits[i] > 1) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}
