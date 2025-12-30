#include <stdio.h>

int main(void)
{
  int a[5][5], i, j, s[2][5] = {0};

  for (i = 0; i < 5; i++) {
    printf("Enter row %d: ", i + 1);
    scanf("%d%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
  }

  printf("Row totals: ");
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j += 1) {
      s[0][i] += a[i][j];
      s[1][i] += a[j][i];
    }
    printf("%d ", s[0][i]);
  }

  printf("\nColumn totals: ");
  for (i = 0; i < 5; i++) {
    printf("%d ", s[1][i]);
  }
  printf("\n");

  return 0;
}
