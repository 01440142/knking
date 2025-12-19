#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define RANKS 13
#define SUITS 4
#define CARDS 5

void read_cards(int ranks[RANKS], int suits[SUITS]);
void analyze_hand(int ranks[RANKS], int suits[SUITS], int *straight, int *flush,
                  int *four, int *three, int *pairs);
void print_result(int *straight, int *flush, int *four, int *three, int *pairs);

int main(void) {
  int straight, flush, four, three, pairs;
  int ranks[RANKS], suits[SUITS];

  while (1) {
    read_cards(ranks, suits);
    analyze_hand(ranks, suits, &straight, &flush, &four, &three, &pairs);
    print_result(&straight, &flush, &four, &three, &pairs);
  }

  return 0;
}

void read_cards(int ranks[RANKS], int suits[SUITS]) {
  char c;
  int cards[RANKS][SUITS] = {{0}, {0}};
  int i, rank, suit, illegal, read = 0;

  for (i = 0; i < RANKS; i++) {
    ranks[i] = 0;
  }

  for (i = 0; i < SUITS; i++) {
    suits[i] = 0;
  }

  while (read < CARDS) {
    illegal = 0;

    printf("Enter a card: ");
    scanf(" %c", &c);

    switch (tolower(c)) {
    case '0':
      exit(0);
      break;
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      rank = c - ('0' + 2);
      break;
    case 't':
      rank = 8;
      break;
    case 'j':
      rank = 9;
      break;
    case 'q':
      rank = 10;
      break;
    case 'k':
      rank = 11;
      break;
    case 'a':
      rank = 12;
      break;
    default:
      illegal = 1;
      break;
    }

    scanf(" %c", &c);
    switch (tolower(c)) {
    case 'c':
      suit = 0;
      break;
    case 'd':
      suit = 1;
      break;
    case 'h':
      suit = 2;
      break;
    case 's':
      suit = 3;
      break;
    default:
      illegal = 1;
      break;
    }

    if (illegal) {
      printf("Bad card; ignored.\n");
      return;
    }
    if (cards[rank][suit]) {
      printf("Duplicated card; ignored.\n");
      return;
    }
    ranks[rank]++;
    suits[suit]++;
    cards[rank][suit] = 1;
    read++;
  }
}

void analyze_hand(int ranks[RANKS], int suits[SUITS], int *straight, int *flush,
                  int *four, int *three, int *pairs) {
  int consecutive = 0, i;
  *straight = *flush = *four = *three = *pairs = 0;

  for (i = 0; i < SUITS; i++) {
    if (suits[i] == CARDS) {
      *flush = 1;
      break;
    }
  }

  i = 0;
  while (ranks[i] == 0) {
    i++;
  }

  for (; i < RANKS && ranks[i] > 0; i++) {
    consecutive++;
  }

  if (consecutive == CARDS) {
    *straight = 1;
    return;
  }

  for (i = 0; i < CARDS; i++) {
    switch (ranks[i]) {
    case '4':
      *four = 1;
      return;
      break;
    case '3':
      *three = 1;
      return;
      break;
    case '2':
      *pairs += 1;
      break;
    }
  }
}

void print_result(int *straight, int *flush, int *four, int *three,
                  int *pairs) {
  if (*straight && *flush) {
    printf("Straight flush");
  } else if (*four) {
    printf("Four of a kind");
  } else if (*three && *pairs == 1) {
    printf("Full house");
  } else if (*flush) {
    printf("Flush");
  } else if (*straight) {
    printf("Straight");
  } else if (*three) {
    printf("Three of a kind");
  } else if (*pairs == 2) {
    printf("Two pairs");
  } else if (*pairs == 1) {
    printf("Pair");
  } else {
    printf("High card");
  }
  printf("\n");
}
