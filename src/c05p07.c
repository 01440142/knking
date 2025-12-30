#include <stdio.h>

int main(void)
{
  int d1, d2, d3, d4, l1, s1, l2, s2, l, s;

  printf("Enter four integers: ");
  scanf("%d%d%d%d", &d1, &d2, &d3, &d4);

  if (d1 > d2) {
    l1 = d1;
    s1 = d2;
  } else {
    l1 = d2;
    s1 = d1;
  }
  if (d3 > d4) {
    l2 = d3;
    s2 = d4;
  } else {
    l2 = d4;
    s2 = d3;
  }

  l = (l1 > l2) ? l1 : l2;
  s = (s1 < s2) ? s1 : s2;
  printf("Largest: %d\n", l);
  printf("Smallest: %d\n", s);

  return 0;
}
