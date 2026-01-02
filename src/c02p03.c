#include <stdio.h>

int main(void)
{
  int r;
  printf("Enter radius: ");
  scanf("%d", &r);
  printf("%f\n", (4.0f / 3.0f) * 3.14159f * r * r * r);
  return 0;
}
