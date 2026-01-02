#include <ctype.h>
#include <stdio.h>

#define MAX_DIGITS 10

char digits[3][4 * MAX_DIGITS];
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

void clear_digits_array(void);
void print_digits_array(void);
void process_digit(int digit, int position);

int main(void) {
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
  return 0;
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

