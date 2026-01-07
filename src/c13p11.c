#include <stdio.h>
#include <string.h>

#define LEN 256

double compute_average_word_length(const char *sentence);

int main(void)
{
  char sentence[LEN], ch;
  char *p = sentence;

  printf("Enter an sentence: ");
  while (p < sentence + (LEN - 1) && (ch = getchar()) != '\n')
    *p++ = ch;
  *p = '\0';
  printf("Average word length: %.1f\n", compute_average_word_length(sentence));

  return 0;
}

double compute_average_word_length(const char *sentence)
{
  int delimiter = 1, words = 0;
  const char *p = sentence;

  while (*p)
    if (*p++ == ' ')
      delimiter++;
    else
      words++;

  return (double) words / delimiter;
}
