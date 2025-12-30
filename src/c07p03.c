#include <stdio.h>

int main(void)
{
  double n, s = 0.0;

  printf("This program sums a series of decimal numbers.\n");
  printf("Enter decimal numbers (0 to terminate): ");

  do {
    scanf("%lf", &n);
    s += n;
  } while (n != 0);

  printf("The sum is %f\n", s);

  return 0;
}
