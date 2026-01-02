#include <stdio.h>

int main(void)
{
  float a, i, m, r;

  printf("Enter amount of loan: ");
  scanf("%f", &a);
  printf("Enter interest rate: ");
  scanf("%f", &i);
  printf("Enter monthly payment: ");
  scanf("%f", &m);

  r = (i / 12 / 100) + 1;
  a = (a - m) * r;
  printf("Balance remaining after first payment: $%.2f\n", a);
  a = (a - m) * r;
  printf("Balance remaining after second payment: $%.2f\n", a);
  a = (a - m) * r;
  printf("Balance remaining after third payment: $%.2f\n", a);

  return 0;
}
