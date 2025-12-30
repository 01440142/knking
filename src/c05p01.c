#include <stdio.h>

int main(void)
{
  int n, d;

  printf("Enter a number: ");
  scanf("%d", &n);

  if (n < 10)
    d = 1;
  else if (n < 100)
    d = 2;
  else if (n < 1000)
    d = 3;
  else
    d = 4;

  printf("The number %d has %d digit(s)\n", n, d);

  return 0;
}
