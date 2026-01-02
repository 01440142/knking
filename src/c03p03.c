#include <stdio.h>

int main(void)
{
  int x, g, p, n, c;

  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d-%d", &x, &g, &p, &n, &c);

  printf("GS1 prefix: %d\n", x);
  printf("Group identifier: %d\n", g);
  printf("Publisher code: %d\n", p);
  printf("Item number: %d\n", n);
  printf("Check digit: %d\n", c);

  return 0;
}
