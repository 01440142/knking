#include <ctype.h>
#include <stdio.h>

int main(void)
{
  char ch;
  int h, m;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d %c", &h, &m, &ch);

  ch = toupper(ch);
  if (ch == 'P')
    h += 12;

  printf("%2.2d:%2.2d\n", h, m);

  return 0;
}
