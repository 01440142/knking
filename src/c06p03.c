#include <stdio.h>

int main(void) {
  int n, d, x, y, r;

  printf("Enter a fraction: ");
  scanf("%d/%d", &n, &d);
  x = n;
  y = d;

  while (x > 0) {
    r = y % x;
    y = x;
    x = r;
  }

  printf("In lowest terms: %d/%d\n", (n / y), (d / y));

  return 0;
}
