#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define LEN 64

bool is_palindrome(const char *message);

int main(void) {
  char ch;
  char message[LEN+1] = {0};
  char *p = message;

  printf("Enter a message: ");
  while ((ch = getchar()) != '\n' && p < message + LEN)
    if (isalpha(ch))
      *p++ = tolower(ch);

  if (is_palindrome(message))
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");

  return 0;
}

bool is_palindrome(const char *message)
{
  const char *p = message;
  const char *q = message + (strlen(message)-1);

  while (p < q)
    if (*p++ != *q--)
      return false;
  return true;
}
