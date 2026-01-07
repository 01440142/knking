#include <stdio.h>
#include <string.h>

#define SENTENCE_LEN 30
#define WORD_LEN 20
int main(void)
{
  char sentence [SENTENCE_LEN][WORD_LEN];
  char ch;
  int n, i, j;

  printf("Enter a sentence: ");
  for (i = 0; i < SENTENCE_LEN; i++) {
    for (j = 0; j < WORD_LEN; j++) {
      ch = getchar();
      if (ch == ' ' || ch == '\n')
        break;
      sentence[i][j] = ch;
    }
    sentence[i][j] = '\0';
    if (ch == '\n')
      break;
  }

  n = strlen(sentence[i]);
  ch = sentence[i][n-1];
  sentence[i][n-1] = '\0';

  printf("Reversal of sentence: ");
  while (i >= 0)
    printf("%s ", sentence[i--]);
  printf("\b%c\n", ch);

  return 0;
}
