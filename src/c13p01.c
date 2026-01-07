#include<stdio.h>
#include<string.h>

#define LEN 20
int main(void)
{
  char word[LEN], smallest_word[LEN], largest_word[LEN];

  printf("Enter word: ");
  scanf("%s", word);
  strcpy(smallest_word, word);
  strcpy(largest_word, word);

  while (strlen(word) != 4) {
    printf("Enter word: ");
    scanf("%s", word);
    if (strcmp(word, smallest_word) < 0)
      strcpy(smallest_word, word);
    if (strcmp(word, largest_word) > 0)
      strcpy(largest_word, word);
  }

  printf("\nSmallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);
  return 0;
}
