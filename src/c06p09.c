#include <stdio.h>

int main(void)
{
  float a, i, m, r;
  int p, y;

  printf("Enter amount of loan: ");
  scanf("%f", &a);
  printf("Enter interest rate: ");
  scanf("%f", &i);
  printf("Enter monthly payment: ");
  scanf("%f", &m);
  printf("Enter number of payments: ");
  scanf("%d", &p);

  r = (i / 12 / 100) + 1;
  for (y = 1; y <= p; y++) {
    a = (a - m) * r;
    printf("Balance remaining after %d. payment: $%.2f\n", y, a);
  }

  return 0;
}
