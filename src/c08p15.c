#include <stdio.h>

int main(void)
{
  int n, i = 0;
  char ch, m[80] = {0};

  printf("Enter message to be encrypted: ");
  while ((ch = getchar()) != '\n' && i < (int)(sizeof(m) / sizeof(m[0]))) {
    m[i] = ch;
    i++;
  }

  printf("Enter shift amount (1-25): ");
  scanf("%d", &n);

  for (i = i; i >= 0; i--) {
    if (m[i] >= 'A' && m[i] <= 'Z') {
      m[i] = (((m[i] - 'A') + n) % 26) + 'A';
    } else if (m[i] >= 'a' && m[i] <= 'z') {
      m[i] = (((m[i] - 'a') + n) % 26) + 'a';
    }
  }

  printf("Encrypted message: ");
  while (m[i] != 0 && i < (int)(sizeof(m) / sizeof(m[0]))) {
    printf("%c", m[i]);
    i++;
  }
  printf("\n");

  return 0;
}
