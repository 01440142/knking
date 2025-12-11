/*
 * 01. (a) a, b, c (b) a, d (c) a, d, e (d) a, f
 * 02. (a) b (inside f), c, d
 *     (b) a, b, c (inside g)
 *     (c) a (inside block), b, c (inside g), d
 *     (d) b, c (inside main), d
 * 03. There could be an indefinite amount of i variables. There is no limit
 *     to the number of blocks being created within main.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define MAX_DIGITS 10

char digits[3][4 * MAX_DIGITS];
int contents[STACK_SIZE];
int segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, /* 0 */
    {0, 1, 1, 0, 0, 0, 0}, /* 1 */
    {1, 1, 0, 1, 1, 0, 1}, /* 2 */
    {1, 1, 1, 1, 0, 0, 1}, /* 3 */
    {0, 1, 1, 0, 0, 1, 1}, /* 4 */
    {1, 0, 1, 1, 0, 1, 1}, /* 5 */
    {1, 0, 1, 1, 1, 1, 1}, /* 6 */
    {1, 1, 1, 0, 0, 0, 0}, /* 7 */
    {1, 1, 1, 1, 1, 1, 1}, /* 8 */
    {1, 1, 1, 1, 0, 1, 1}  /* 9 */
};
/* 3x3 grid translation */
int segments_grid[7][2] = {
    {0, 1}, /* segment 1 */
    {1, 2}, /* segment 2 */
    {2, 2}, /* segment 3 */
    {2, 1}, /* segment 4 */
    {2, 0}, /* segment 5 */
    {1, 0}, /* segment 6 */
    {1, 1}  /* segment 7 */
};
int result;
int top = 0;

void c10p1(void);
void c10p2(void);
void c10p3(void);
void c10p4(void);
void c10p5(void);
void c10p6(void);
void c10p7(void);
char pop(void);
void analyze_hand(int hand[5][2]);
void clear_digits_array(void);
void print_digits_array(void);
void print_result(void);
void process_digit(int digit, int position);
void push(char c);
void read_cards(int hand[5][2]);

int main(void) {
  c10p7();
  return 0;
}

void c10p1(void) {
  char ch;

  printf("Enter parentheses and/or braces: ");
  do {
    scanf("%c", &ch);
    switch (ch) {
    case '(':
    case '{':
      push(ch);
      break;
    case ')':
      if (pop() != '(') {
        printf("Parentheses aren't nested properly\n");
        return;
      }
      break;
    case '}':
      if (pop() != '{') {
        printf("Braces aren't nested properly\n");
        return;
      }
      break;
    }
  } while (ch != '\n');

  if (top != 0) {
    printf("Parentheses/braces aren't nested properly\n");
    return;
  }
  printf("Parentheses/braces are nested properly\n");
}

void c10p2(void) {
  /* five hand cards (0-4) with a rank (0) and suit (1) */
  int hand[5][2];
  while (1) {
    read_cards(hand);
    analyze_hand(hand);
    print_result();
  }
}

void c10p3(void) {
  /* five hand cards (0-4) with a rank (0) and suit (1) */
  int hand[5][2];
  while (1) {
    read_cards(hand);
    analyze_hand(hand);
    print_result();
  }
}

void c10p4(void) {
  /* five hand cards (0-4) with a rank (0) and suit (1) */
  int hand[5][2];
  while (1) {
    read_cards(hand);
    analyze_hand(hand);
    print_result();
  }
}

void c10p5(void) {
  /* five hand cards (0-4) with a rank (0) and suit (1) */
  int hand[5][2];
  while (1) {
    read_cards(hand);
    analyze_hand(hand);
    print_result();
  }
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

void c10p6(void) {
  bool next;
  char ch, temp;

  while (1) {
    next = true;
    top = 0;
    printf("Enter an RPN expression: ");
    while (next) {
      scanf(" %c", &ch);
      if (isdigit(ch)) {
        push(ch - '0');
        continue;
      }
      switch (ch) {
      case '+':
        push(pop() + pop());
        break;
      case '-':
        temp = pop();
        push(pop() - temp);
        break;
      case '/':
        temp = pop();
        push(pop() / temp);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '=':
        printf("Value of expression: %d\n", pop());
        next = false;
        break;
      default:
        exit(0);
        break;
      }
    }
  }
}

char pop(void) {
  if (top == 0) {
    printf("Not enough operands in expression\n");
    printf("Can't pop empty stack! Stack Underflow!\n");
    exit(1);
  }
  top--;
  return contents[top];
}

void push(char c) {
  if (top == STACK_SIZE) {
    printf("Expression is too complex\n");
    printf("Can't push full stack! Stack Overflow!\n");
    exit(1);
  }
  contents[top] = c;
  top++;
}

void c10p7(void) {
  char ch;
  int position = 0;

  clear_digits_array();
  printf("Enter a number: ");
  while ((ch = getchar()) != '\n' && position < (MAX_DIGITS * 4)) {
    if (isdigit(ch)) {
      process_digit(ch - '0', position);
      position += 4;
    }
  }
  print_digits_array();
}

void clear_digits_array(void) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < (MAX_DIGITS * 4); j++) {
      digits[i][j] = ' ';
    }
  }
}

void process_digit(int digit, int position) {
  int i, row, column;

  for (i = 0; i < 7; i++) {
    if (segments[digit][i]) {
      row = segments_grid[i][0];
      column = segments_grid[i][1] + position;
      if (i % 3 == 0) {
        digits[row][column] = '_';
      } else {
        digits[row][column] = '|';
      }
    }
  }
}

void print_digits_array(void) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < (MAX_DIGITS * 4); j++) {
      printf("%c", digits[i][j]);
    }
    printf("\n");
  }
}
