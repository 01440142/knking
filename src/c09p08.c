#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool play_game(void);
int roll_dice(void);

int main(void)
{
  char ch;
  int wins = 0, losses = 0;

  srand((unsigned)time(NULL));

  do {
    if (play_game()) {
      wins++;
    } else {
      losses++;
    };
    printf("Play again? ");
    scanf(" %c", &ch);
  } while (tolower(ch) == 'y');

  printf("Wins: %-2d Losses: %-2d\n", wins, losses);

  return 0;
}

int roll_dice(void) {
  int d1, d2;

  d1 = (rand() % 6) + 1;
  d2 = (rand() % 6) + 1;

  return d1 + d2;
}

bool play_game(void) {
  int point, roll;
  point = roll = roll_dice();

  printf("You rolled: %d\n", roll);
  printf("Your point is: %d\n", point);
  switch (roll) {
  case 2:
  case 3:
  case 12:
    printf("You lose!\n");
    return false;
    break;
  case 7:
  case 11:
    printf("You win!\n");
    return true;
    break;
  }

  while ((roll = roll_dice()) != 7) {
    printf("You rolled: %d\n", roll);
    if (roll == point) {
      printf("You win!\n");
      return true;
    }
  };

  printf("You rolled: %d\n", roll);
  printf("You lose!\n");
  return false;
}
