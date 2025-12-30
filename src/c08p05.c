#include <stdio.h>

int main(void)
{
  int r, y, i, j, k;
  double a[5], s;

  printf("Enter interest rate: ");
  scanf("%d", &r);
  printf("Enter number of years: ");
  scanf("%d", &y);

  printf("Years\t");
  for (i = 0; i < 5; i++) {
    printf("%9d%%", r + i);
    a[i] = 100.0;
  }
  printf("\n");

  for (i = 1; i <= y; i++) {
    printf("%5d\t", i);
    for (j = 0; j < 5; j += 1) {
      s = 0;
      for (k = 0; k < 12; k += 1) {
        s += ((r + j) / 100.0) * a[j];
      }
      a[j] += s;
      printf("%10.2f", a[j]);
    }
    printf("\n");
  }

  return 0;
}
