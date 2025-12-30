#include <stdio.h>

int main(void)
{
  int h, m;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &h, &m);
  printf("Equivalent 12-hour time: ");

  if (h < 13)
    printf("%.2d:%.2d AM\n", h, m);
  else
    printf("%.2d:%.2d PM\n", (h - 12), m);

  return 0;
}
