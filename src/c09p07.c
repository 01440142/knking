#include <stdio.h>

int power(int x, int n);

int main(void)
{
  int x, n;

  printf("Enter x: ");
  scanf("%d", &x);
  printf("Enter n: ");
  scanf("%d", &n);
  printf("x^n = %d\n", power(x, n));

  return 0;
}

int power(int x, int n) {
  int temp;

  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    temp = power(x, n / 2);
    return temp * temp;
  }
  return x * power(x, n - 1);
}

