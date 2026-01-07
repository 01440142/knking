#include <ctype.h>
#include <stdio.h>

#define LEN 256

int compute_vowel_count(const char *sentence);

int main(void)
{
  char sentence[LEN], ch;
  char *p = sentence;

  printf("Enter a sentence: ");
  while (p < sentence + (LEN - 1) && (ch = getchar()) != '\n')
    *p++ = ch;
  *p = '\0';
  printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

  return 0;
}

int compute_vowel_count(const char *sentence)
{
  int vowels = 0;

  while (*sentence)
    switch (toupper(*sentence++))
      case 'A': case 'E': case 'I': case 'O': case 'U':
        vowels++;

  return vowels;
}
