#include <stdio.h>

void create_magic_square(int n, char magic_square[99][99]);
void print_magic_square(int n, char magic_square[99][99]);

int main(void)
{
  char magic_square[99][99] = {{0}, {0}};
  int n;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99\n");
  printf("Enter size of magic square: ");
  scanf("%d", &n);

  create_magic_square(n, magic_square);
  print_magic_square(n, magic_square);

  return 0;
}

void create_magic_square(int n, char magic_square[99][99]) {
  int row = 0, column;
  int i;

  column = n / 2;
  for (i = 0; i <= (n * n); i++) {
    if (magic_square[row][column] != 0) {
      column = (column - 1 + n) % n;
      row = (row + 2 + n) % n;
    }
    magic_square[row][column] = i;
    row = (row + n - 1) % n;
    column = (column + 1) % n;
  }
}

void print_magic_square(int n, char magic_square[99][99]) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%4d", magic_square[i][j]);
    }
    printf("\n");
  }
}
