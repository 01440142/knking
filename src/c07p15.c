#include <stdio.h>

/*
 * (a) 7
 * (b) 19
 * (c) 42
 * (d) 42
 * (e) 34
 * (f) 170
 * (g) 1754
 */
int main(void)
{
  short n, s, i;

  printf("Enter a positive number: ");
  scanf("%hd", &n);

  for (i = s = n; i > 1; i--)
    s *= (i - 1);
  printf("Factiorial of %hd: %hd\n", n, s);

  return 0;
}
