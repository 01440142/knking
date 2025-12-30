#include <stdio.h>

int main(void)
{
  char ch;

  printf("Enter parentheses and/or braces: ");
  do {
    scanf("%c", &ch);
    switch (ch) {
    case '(':
    case '{':
      push(ch);
      break;
    case ')':
      if (pop() != '(') {
        printf("Parentheses aren't nested properly\n");
        return;
      }
      break;
    case '}':
      if (pop() != '{') {
        printf("Braces aren't nested properly\n");
        return;
      }
      break;
    }
  } while (ch != '\n');

  if (top != 0) {
    printf("Parentheses/braces aren't nested properly\n");
    return;
  }
  printf("Parentheses/braces are nested properly\n");

  return 0;
}
