#include <math.h>
#include <stdio.h>

int main(void)
{
  double x, y1 = 1.0, y2, z;

  printf("Enter a positive number: ");
  scanf("%lf", &x);
  do {
    y2 = y1;
    z = x / y1;
    y1 = (y1 + z) / 2;
  } while (fabs(y2 - y1) >= 1.e-4);
  printf("Square root: %.5f\n", y1);

  return 0;
}
