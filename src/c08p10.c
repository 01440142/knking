#include <stdio.h>

int main(void)
{
  int a[] = {616, 724, 811, 900, 968, 1075, 280, 1438},
      d[] = {480, 583, 679, 767, 840, 945, 1140, 1305}, h, m, t, i, j = -1, h1,
      m1, c1, h2, m2, c2;

  c1 = c2 = 'a';

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &h, &m);
  t = (h * 60) + m;

  for (i = 0; i < (int)((sizeof(d) / sizeof(d[0])) - 1); i++) {
    if (t < d[i] + (d[i + 1] - d[i]) / 2) {
      j = i;
      break;
    }
  }
  if (j == -1) {
    j = (int)((sizeof(d) / sizeof(d[0])) - 1);
  }

  if ((h1 = (d[j] / 60)) > 12) {
    h1 -= 12;
    c1 = 'p';
  }
  if ((h2 = (a[j] / 60)) > 12) {
    h2 -= 12;
    c2 = 'p';
  }
  m1 = d[j] % 60;
  m2 = a[j] % 60;

  printf("Closest Departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
         h1, m1, c1, h2, m2, c2);

  return 0;
}
