#include <stdio.h>

int main(void)
{
  int n, d, m, y;
  float p;

  printf("Enter item number: ");
  scanf("%d", &n);
  printf("Enter unit price: ");
  scanf("%f", &p);
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &m, &d, &y);

  printf("Item\tUnit\tPurchase\n");
  printf("\tPrice\tDate\n");
  printf("%d\t$%-4.2f\t%.2d/%.2d/%d\n", n, p, m, d, y);

  return 0;
}
