#include <stdio.h>

int main(void)
{
  int n, i, j;
  float a, r = 1.0f;

  printf("Enter n: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    a = 1.0f;
    for (j = 1; j <= i; j++)
      a *= j;
    r += 1.0f / a;
  }

  printf("Approximation of e with n = %d is: %f\n", n, r);

  return 0;
}
