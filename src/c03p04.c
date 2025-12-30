#include <stdio.h>

void main(void)
{
  int f, s, t;

  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%d)%d-%d", &f, &s, &t);
  printf("You entered %d.%d.%d\n", f, s, t);

  return 0;
}
