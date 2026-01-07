#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define LEN 26

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
  char word1[LEN], word2[LEN];

  printf("Enter first word: ");
  scanf("%26s", word1);
  printf("Enter second word: ");
  scanf("%26s", word2);

  if (are_anagrams(word1, word2))
    printf("The words are anagrams.\n");
  else 
    printf("The words are not anagrams.\n");

  return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
  char alphabet[LEN] = {0};
  const char *p;

  for (p = word1; p < word1 + (LEN - 1); p++)
    *(alphabet + (tolower(*p) - 'a')) += 1;
  for (p = word2; p < word2 + (LEN - 1); p++)
    *(alphabet + (tolower(*p) - 'a')) -= 1;

  for (p = alphabet; p < alphabet + LEN; p++)
    if (*p != 0)
      return false;

  return true;
}
