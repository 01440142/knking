#include <stdio.h>

int main(void)
{
  int i, j;
  float e, a, r = 1.0f;

  printf("Enter epsilon: ");
  scanf("%f", &e);

  for (i = 1; r < e; i++) {
    a = 1.0f;
    for (j = 1; j <= i; j++)
      a *= j;
    r += 1.0f / a;
  }

  printf("Approximation of e with epsilon = %f is: %f\n", e, r);

  return 0;
}
