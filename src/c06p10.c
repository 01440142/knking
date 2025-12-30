#include <stdio.h>

int main(void)
{
  int m1 = 12, d1 = 31, y1 = 99, m2, d2, y2;

  do {
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    if (!m2 || !d2 || !y2)
      break;
    else if (y1 < y2)
      continue;
    else if (y1 == y2 && m1 < m2)
      continue;
    else if (y1 == y2 && m1 == m2 && d1 <= d2)
      continue;

    m1 = m2;
    d1 = d2;
    y1 = y2;
  } while (1);

  printf("%d/%d/%d is the earliest date\n", m1, d1, y1);

  return 0;
}
