#include <stdio.h>

void reduce(int num, int den, int *rnum, int *rden);

int main(void) {
  int num, den, rnum, rden;

  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &den);
  reduce(num, den, &rnum, &rden);

  printf("In lowest terms: %d/%d\n", rnum, rden);
  return 0;
}

void reduce(int num, int den, int *rnum, int *rden) {
  int x = num, y = den, remainder;

  while (x > 0) {
    remainder = y % x;
    y = x;
    x = remainder;
  }

  *rnum = num / y;
  *rden = den / y;
}
