#include <stdio.h>

#define LEN 64

int main(void) {
  char *p, message[LEN];

  printf("Enter a message: ");
  for (p = message; p < message + LEN; p++)
    if ((*p = getchar()) == '\n')
      break;

  printf("Reversal is: ");
  for (p--; p >= message; p--)
    putchar(*p);
  printf("\n");

  return 0;
}
