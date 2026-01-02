#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int result;

void analyze_hand(int hand[5][2]);
void read_cards(int hand[5][2]);
void print_result(void);

int main(void)
{
  int hand[5][2];

  while (1) {
    read_cards(hand);
    analyze_hand(hand);
    print_result();
  }

  return 0;
}

void read_cards(int hand[5][2]) {
  bool legal;
  char rank, suit;
  int i, j, card = 0;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 2; j++) {
      hand[i][j] = -1;
    }
  }

  while (card < 5) {
    legal = true;

    printf("Enter a card: ");
    scanf(" %c", &rank);
    if (rank == '0') {
      exit(0);
    }
    scanf(" %c", &suit);

    switch (tolower(rank)) {
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      rank = rank - ('0' + 2);
      break;
    case 't': /* ten */
      rank = 8;
      break;
    case 'j': /* joker */
      rank = 9;
      break;
    case 'q': /* queen */
      rank = 10;
      break;
    case 'k': /* king */
      rank = 11;
      break;
    case 'a': /* ace */
      rank = 12;
      break;
    default:
      rank = -1;
      break;
    }

    switch (tolower(suit)) {
    case 'c': /* club */
      suit = 0;
      break;
    case 'd': /* diamond */
      suit = 1;
      break;
    case 'h': /* heart */
      suit = 2;
      break;
    case 's': /* spade */
      suit = 3;
      break;
    default:
      suit = -1;
      break;
    }

    if (rank == -1 || suit == -1) {
      printf("Bad card; ignored.\n");
      legal = false;
    } else {
      for (i = (card - 1); i >= 0; i--) {
        if (hand[i][0] == rank && hand[i][1] == suit) {
          printf("Duplicate card; ignored.\n");
          legal = false;
        }
      }
    }

    if (legal) {
      hand[card][0] = rank;
      hand[card][1] = suit;
      card++;
    }
  }
}

void analyze_hand(int hand[5][2]) {
  int i;
  int rank, suit;
  int consecutive = 0, pairs = 0;
  /* 2, 3, 4, 5, 6, 7, 8, 9, ten, joker, queen, king, ace */
  int ranks[13] = {0};
  /* clubs, diamonds, hearts, spades */
  int suits[4] = {0};

  /*
   * 8 = straight flush
   * 7 = four-of-a-kind
   * 6 = full house
   * 5 = flush
   * 4 = straight
   * 3 = three-of-a-kind
   * 2 = two pairs
   * 1 = pair
   * 0 = high card
   */
  result = 0;

  for (i = 0; i < 5; i++) {
    rank = hand[i][0];
    suit = hand[i][1];
    ranks[rank]++;
    suits[suit]++;
  }

  for (i = 0; i < 4; i++) {
    if (suits[i] > 4) {
      result = 5 /* flush */;
    }
  }

  for (i = 0; i < 13; i++) {
    if (ranks[(i + 12) % 13] == 0) {
      consecutive = 0;
      continue;
    }
    consecutive++;
    if (consecutive == 5) {
      if (result == 5) {
        if (i == 8) {
          result = 9; /* royal flush */
          return;
        }
        result = 8; /* straight flush */
        return;
      }
      result = 4; /* straight */
      break;
    }
  }

  for (i = 0; i < 13; i++) {
    switch (ranks[i]) {
    case 4:
      result = 7; /* four-of-a-kind */
      return;
    case 3:
      if (result < 3) {
        result = 3; /* three-of-a-kind */
      }
      break;
    case 2:
      pairs++;
      break;
    }
  }

  if (result == 3 && pairs >= 1) {
    if (result < 6) {
      result = 6; /* full house */
    }
    return;
  }

  if (result > 2) {
    return;
  }

  if (pairs == 2) {
    result = 2; /* two pairs */
    return;
  }

  result = pairs; /* pair or high card */
}

void print_result(void) {
  switch (result) {
  case 1:
    printf("Pair\n");
    break;
  case 2:
    printf("Two pairs\n");
    break;
  case 3:
    printf("Three of a kind\n");
    break;
  case 4:
    printf("Straight\n");
    break;
  case 5:
    printf("Flush\n");
    break;
  case 6:
    printf("Full house\n");
    break;
  case 7:
    printf("Four of a kind\n");
    break;
  case 8:
    printf("Straight flush\n");
    break;
  case 9:
    printf("Royal flush\n");
    break;
  default:
    printf("High card\n");
    break;
  }
}
