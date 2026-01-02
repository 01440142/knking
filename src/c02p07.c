#include <stdio.h>

int main(void)
{
  int a, b;

  printf("Enter a dollar amount: ");
  scanf("%d", &a);

  b = a / 20;
  printf("$20 bills: %d\n", b);
  a -= b * 20;
  b = a / 10;
  printf("$10 bills: %d\n", b);
  a -= b * 10;
  b = a / 5;
  printf(" $5 bills: %d\n", b);
  a -= b * 5;
  printf(" $1 bills: %d\n", a);

  return 0;
}
