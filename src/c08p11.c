#include <stdio.h>

int main(void)
{
  char c[15];
  int i;

  printf("Enter phone number: ");
  for (i = 0; i < (int)(sizeof(c) / sizeof(c[0])); i++) {
    if ((c[i] = getchar()) == '\n') {
      break;
    }
    switch (c[i]) {
    case 'A':
    case 'B':
    case 'C':
      c[i] = '2';
      break;
    case 'D':
    case 'E':
    case 'F':
      c[i] = '3';
      break;
    case 'G':
    case 'H':
    case 'I':
      c[i] = '4';
      break;
    case 'J':
    case 'K':
    case 'L':
      c[i] = '5';
      break;
    case 'M':
    case 'N':
    case 'O':
      c[i] = '6';
      break;
    case 'P':
    case 'R':
    case 'S':
      c[i] = '7';
      break;
    case 'T':
    case 'U':
    case 'V':
      c[i] = '8';
      break;
    case 'W':
    case 'X':
    case 'Y':
      c[i] = '8';
      break;
    }
  }

  printf("In numeric form: ");
  for (i = 0; i < (int)(sizeof(c) / sizeof(c[0])); i++) {
    printf("%c", c[i]);
    if (c[i] == '\n') {
      break;
    }
  }

  return 0;
}
