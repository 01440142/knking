#include <stdio.h>

int main(void)
{
  int n, s[99][99] = {{0}, {0}}, r = 0, c, m = 1, i, j;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99\n");
  printf("Enter size of magic square: ");
  scanf("%d", &n);

  if (n > 99 || n % 2 == 0) {
    return;
  }

  c = n / 2;
  while (m <= (n * n)) {
    if (s[r][c] != 0) {
      c = (c - 1 + n) % n;
      r = (r + 2 + n) % n;
    }
    s[r][c] = m;
    r = (r + n - 1) % n;
    c = (c + 1) % n;
    m++;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%4d", s[i][j]);
    }
    printf("\n");
  }

  return 0;
}
