#include <ctype.h>
#include <stdio.h>

int main(void)
{
  char m[256];
  int i;

  printf("Enter message: ");
  for (i = 0; i < 256; i++) {
    m[i] = getchar();
    if (m[i] == '\n') {
      break;
    }
  }

  printf("In B1FF-speak: ");
  for (i = 0; i < 256; i++) {
    m[i] = toupper(m[i]);
    if (m[i] == '\n') {
      printf("!!!!!!!!!!\n");
      break;
    }
    switch (m[i]) {
    case 'A':
      printf("4");
      break;
    case 'B':
      printf("8");
      break;
    case 'E':
      printf("3");
      break;
    case 'I':
      printf("1");
      break;
    case 'O':
      printf("0");
      break;
    case 'S':
      printf("5");
      break;
    default:
      printf("%c", m[i]);
      break;
    }
  }

  return 0;
}
