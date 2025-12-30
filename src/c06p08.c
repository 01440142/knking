#include <stdio.h>

int main(void)
{
  int d, w, i;

  printf("Enter number of days in month: ");
  scanf("%d", &d);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &w);

  for (i = w; i > 1; i--)
    printf("   ");
  for (i = 1; i <= d; w++, i++) {
    printf("%2d ", i);
    if (w % 7 == 0)
      printf("\n");
  }
  printf("\n");

  return 0;
}
