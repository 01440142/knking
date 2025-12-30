#include <stdio.h>

int main(void)
{
  float x = 0.0f, y;

  do {
    printf("Enter a number: ");
    scanf("%f", &y);
    x = (x < y) ? y : x;
  } while (y > 0);

  printf("\nThe largest number entered was %f\n", x);

  return 0;
}
