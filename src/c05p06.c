#include <stdio.h>

int main(void)
{
  int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, c, s1, s2, t;

  printf("Enter a UPC: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
    &d1, &d2, &d3, &d4, &d5, &d6,
    &d7, &d8, &d9, &d10, &d11, &c
  );

  s1 = d1 + d3 + d5 + d7 + d9 + d11;
  s2 = d2 + d4 + d6 + d8 + d10;
  t = 9 - ((((3 * s1) + s2) - 1) % 10);

  if (t == c)
    printf("VALID\n");
  else
    printf("NOT VALID\n");

  return 0;
}
