#include <stdio.h>

int main(void)
{
  int n, i, s, o;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  for (i = 1, s = 1, o = 3; i <= n; i++, s += o, o += 2)
    printf("%10d%10d\n", i, s);

  return 0;
}
