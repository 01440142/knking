#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define LEN 64

int main(void) {
  bool palindrome = true;
  char message[LEN], ch, *p, *q;

  printf("Enter a message: ");
  for (p = message; p < message + LEN;) {
    ch = getchar();
    if (ch == '\n')
      break;
    if (isalpha(ch)) {
      *p = tolower(ch);
      p++;
    }
  }

  for (p--, q = message; p >= q; p--, q++)
    if (*p != *q) {
      palindrome = false;
      break;
    }

  if (palindrome)
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");

  return 0;
}
