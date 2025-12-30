#include <stdio.h>

int main(void)
{
  int n, x;

  printf("Enter a number: ");
  scanf("%d", &n);

  printf("The reversal is: ");
  do {
    x = n % 10;
    printf("%d", x);
    n /= 10;
  } while (n != 0);
  printf("\n");

  return 0;
}
