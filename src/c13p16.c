#include<stdio.h>
#include<string.h>

#define LEN 80

void reverse(char *message);

int main(void)
{
  char ch;
  char message[LEN+1] = {0};
  char *p = message;

  printf("Enter a message: ");
  while ((ch = getchar()) != '\n' && p < message + LEN)
    *p++ = ch;
  reverse(message);
  printf("Reversal is: %s\n", message);

  return 0;
}

void reverse(char *message)
{
  char *p = message;
  char *q = message + (strlen(message)-1);
  char temp;

  while (p < q) {
    temp = *p;
    *p++ = *q;
    *q-- = temp;
  }
}
