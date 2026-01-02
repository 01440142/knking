#include <stdio.h>

int main(void)
{
  int n1, d1, n2, d2;

  printf("Enter two fractions separated by a plus sign: ");
  scanf("%d/%d+%d/%d", &n1, &d1, &n2, &d2);
  printf("The sum is %d/%d \n", ((n1 * d2) + (n2 * d1)), (d1 * d2));

  return 0;
}
