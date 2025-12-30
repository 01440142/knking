#include <stdio.h>
#include <time.h>

int main(void)
{
  int i, j, x = 0, y = 0, n, t, r, b, l, p;
  char grid[10][10], letter = 'A';

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      grid[i][j] = '.';
    }
  }

  srand((unsigned)time(NULL));
  do {
    grid[x][y] = letter++;
    t = r = b = l = 1;

    if ((y - 1) < 0 || grid[x][y - 1] != '.') {
      t = 0;
    }
    if ((x + 1) > 9 || grid[x + 1][y] != '.') {
      r = 0;
    }
    if ((y + 1) > 9 || grid[x][y + 1] != '.') {
      b = 0;
    }
    if ((x - 1) < 0 || grid[x - 1][y] != '.') {
      l = 0;
    }
    p = t + r + b + l;

    while (p > 0) {
      n = rand() % 4;
      if (n == 0 && t == 1) {
        y--;
        break;
      } else if (n == 1 && r == 1) {
        x++;
        break;
      } else if (n == 2 && b == 1) {
        y++;
        break;
      } else if (n == 3 && l == 1) {
        x--;
        break;
      }
    }
  } while (p > 0 && letter <= 'Z');

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}
