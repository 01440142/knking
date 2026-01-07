#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  int sum = 0;

  for (argc -= 1; argc > 0; argc--)
    sum += atoi(argv[argc]);
  printf("Total: %d\n", sum);

  return 0;
}
