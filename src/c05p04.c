#include <stdio.h>

int main(void)
{
  int k;

  printf("Enter a wind speed (in knots): ");
  scanf("%d", &k);

  if (k < 1)
    printf("Calm\n");
  else if (k < 4)
    printf("Light air\n");
  else if (k < 28)
    printf("Breeze\n");
  else if (k < 48)
    printf("Gale\n");
  else if (k < 64)
    printf("Storm\n");
  else
    printf("Hurricane\n");

  return 0;
}
