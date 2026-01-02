#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
  char walk[10][10];

  generate_random_walk(walk);
  print_array(walk);
  return 0;
}

void generate_random_walk(char walk[10][10]) {
  char letter = 'A';
  int x = 0, y = 0;
  int top, right, bottom, left;
  int next, possible;
  int i, j;

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      walk[i][j] = '.';
    }
  }

  srand((unsigned)time(NULL));
  do {
    walk[x][y] = letter++;
    top = right = bottom = left = 1;

    if ((y - 1) < 0 || walk[x][y - 1] != '.') {
      top = 0;
    }
    if ((x + 1) > 9 || walk[x + 1][y] != '.') {
      right = 0;
    }
    if ((y + 1) > 9 || walk[x][y + 1] != '.') {
      bottom = 0;
    }
    if ((x - 1) < 0 || walk[x - 1][y] != '.') {
      left = 0;
    }
    possible = top + right + bottom + left;

    while (possible > 0) {
      next = rand() % 4;
      if (next == 0 && top == 1) {
        y--;
        break;
      } else if (next == 1 && right == 1) {
        x++;
        break;
      } else if (next == 2 && bottom == 1) {
        y++;
        break;
      } else if (next == 3 && left == 1) {
        x--;
        break;
      }
    }
  } while (possible > 0 && letter <= 'Z');
}

void print_array(char walk[10][10]) {
  int i, j;

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      printf("%c ", walk[i][j]);
    }
    printf("\n");
  }
}
