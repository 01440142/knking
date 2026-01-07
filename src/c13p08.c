#include <ctype.h>
#include <stdio.h>

int compute_scrabble_value(const char *word);

int main(void)
{
  char word[64];

  printf("Enter a word: ");
  scanf("%64s", word);
  printf("Scrabble value: %d\n", compute_scrabble_value(word));

  return 0;
}

int compute_scrabble_value(const char *word)
{
  const char *p;
  int sum = 0;

  for (p = word; *p; p++)
    switch (toupper(*p)) {
      case 'D': case 'G':
        sum += 2; break;
      case 'B': case 'C': case 'M': case 'P':
        sum += 3; break;
      case 'F': case 'H': case 'V': case 'W': case 'Y':
        sum += 4; break;
      case 'K':
        sum += 5; break;
      case 'J': case 'X':
        sum += 8; break;
      case 'Q': case 'Z':
        sum += 10; break;
      default:
        sum++; break;
    }

  return sum;
}
