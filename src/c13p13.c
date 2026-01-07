#include <stdio.h>

#define LEN 80

void encrypt(char *message, int shift);

int main(void)
{
  char ch, message[80];
  int i = 0, shift;

  printf("Enter message to be encrypted: ");
  while ((ch = getchar()) != '\n' && i < LEN)
    message[i++] = ch;
  message[i] = '\0';

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  encrypt(message, shift);
  printf("Encrypted message: %s\n", message);

  return 0;
}

void encrypt(char *message, int shift)
{
  char *p = message;

  while (*p) {
    if (*p >= 'A' && *p <= 'Z')
      *p = (((*p - 'A') + shift) % 26) + 'A';
    else if (*p >= 'a' && *p <= 'z')
      *p = (((*p - 'a') + shift) % 26) + 'a';
    p++;
  }
}
