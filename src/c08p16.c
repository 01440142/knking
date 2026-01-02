#include <ctype.h>
#include <stdio.h>

int main(void)
{
  char ch;
  int a[26] = {0}, i = 0;

  printf("Enter first word: ");
  while ((ch = tolower(getchar())) != '\n') {
    if (isalpha(ch)) {
      a[ch - 'a']++;
    }
  }

  printf("Enter second word: ");
  while ((ch = tolower(getchar())) != '\n') {
    if (isalpha(ch)) {
      a[ch - 'a']--;
    }
  }

  while (a[i] == 0 && i < (int)(sizeof(a) / sizeof(a[0]))) {
    i++;
  }

  if (i == (int)(sizeof(a) / sizeof(a[0])))
    printf("The words are anagrams.\n");
  else 
    printf("The words are not anagrams.\n");

  return 0;
}
