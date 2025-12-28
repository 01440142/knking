#include <stdio.h>

#define LEN 64

int main(void) {
  char ch, sentence[LEN], *word_position[LEN / 2];
  char *p = sentence, **q = word_position, *r;

  *q++ = p;
  printf("Enter a sentence: ");
  while (p < sentence + LEN)
    switch (ch = getchar()) {
      case ' ':
        *q++ = p;
        break;
      case '.':
      case '?':
      case '!':
        *q = p;
        goto end;
        break;
      default:
        *p++ = ch;
        break;
    }

  end:
  printf("Reversal of sentence:");
  while (p >= sentence) { 
    r = *q;
    while (r <= p)
      printf("%c", *r++);
    printf(" ");
    p = *q--;
    p--;
  }
  printf("\b%c\n", ch);

  return 0;
}
