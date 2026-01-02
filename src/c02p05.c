#include <stdio.h>

int main(void) {
  int x, r;

  printf("Enter value for x: ");
  scanf("%d", &x);
  r = (3 * x * x * x * x * x);
  r += (2 * x * x * x * x);
  r -= (5 * x * x * x);
  r -= (x * x);
  r += (7 * x);
  r -= 6;
  printf("%d\n", r);

  return 0;
}
