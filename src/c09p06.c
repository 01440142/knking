#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int polynomial(int x);

int main(void)
{
  int x;

  printf("Enter value for x: ");
  scanf("%d", &x);
  printf("%d\n", polynomial(x));

  return 0;
}

int polynomial(int x) {
  int result = 0;

  result += 3 * (x * x * x * x * x);
  result += 2 * (x * x * x * x);
  result -= 5 * (x * x * x);
  result -= 1 * (x * x);
  result += 7 * (x);
  result -= 6;

  return result;
}
