#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 *  1. The expression is no longer valid after the type is changed. Furthermore
 *     the correctness of 't' isn't guaranteed and needs to be checked
 *     elsewhere in the code.
 *  2. digit_count[d-'0']
 *  3. bool weekend[] = {1, 0, 0, 0, 0, 0, 1}
 *  4. bool weekend[] = {[0] = 1, [6] = 1}
 *  5. int fib_numbers[40] = {0, 1};
 *     for (i = 2; i < (sizeof(fib_numbers) / sizeof(fib_numbers[0])); i++) {
 *       fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];
 *     }
 *  6. const int segments[10][7] = {
 *       {1, 1, 1, 1, 1, 1, 0}, // 0
 *       {0, 1, 1, 0, 0, 0, 0}, // 1
 *       {1, 1, 0, 1, 1, 0, 1}, // 2
 *       {1, 1, 1, 1, 0, 0, 1}, // 3
 *       {0, 1, 1, 0, 0, 1, 1}, // 4
 *       {1, 0, 1, 1, 0, 1, 1}, // 5
 *       {1, 0, 1, 1, 1, 1, 1}, // 6
 *       {1, 1, 1, 0, 0, 0, 0}, // 7
 *       {1, 1, 1, 1, 1, 1, 1}, // 8
 *       {1, 1, 1, 1, 0, 1, 1}  // 9
 *     };
 *  7. const int segments[10][7] = {
 *       {1, 1, 1, 1, 1, 1}, // 0
 *       {[1] = 1, 1}, // 1
 *       {1, 1, [3] = 1, 1, [6] = 1}, // 2
 *       {1, 1, 1, 1, [6] = 1}, // 3
 *       {[1] = 1, 1, [5] = 1, 1}, // 4
 *       {1, [2] = 1, 1, [5] = 1, 1}, // 5
 *       {1, [2] = 1, 1, 1, 1, 1}, //6
 *       {1, 1, 1}, // 7
 *       {1, 1, 1, 1, 1, 1, 1}, // 8
 *       {1, 1, 1, 1, [5] = 1, 1 } // 9
 *     };
 *  8. float temperature_readings[30][24];
 *  9. for (i = 0; i < 30; i++) {
 *       for (j = 0; j < 24; j++) {
 *         a += temperature_readings[i][j];
 *       }
 *     }
 *     m /= 30 * 24;
 * 10. const int chess_board[8][8] = {
 *       {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
 *       {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
 *       {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 *       {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
 *       {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 *       {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
 *       {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
 *       {'R', 'N', 'B'. 'Q', 'K', 'B', 'N', 'R'}
 *     };
 * 11. char checker_board[8][8];
 *     for (i = 0; i < 8; i++) {
 *       for(j = 0; j < 8; j++) {
 *         if ((i + j) % 2) {
 *           checker_board[i][j] = 'R';
 *         } else {
 *           checker_board[i][j] = 'B';
 *         }
 *       }
 *     }
 */

void c8p1() {
  int digits[10] = {0}, i;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digits[n % 10] += 1;
    n /= 10;
  }
  printf("Repeated digit(s): ");
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    if (digits[i] > 1) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

void c8p2() {
  int digits[10] = {0}, i;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digits[n % 10] += 1;
    n /= 10;
  }

  printf("Digit:\t\t");
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    printf("%d ", i);
  }
  printf("\nOccurrences:\t");
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    printf("%d ", digits[i]);
  }
  printf("\n");
}

void c8p3() {
  int digits[10] = {0}, i;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);
  while (n > 0) {
    digits[n % 10] += 1;
    n /= 10;
    printf("Enter a number: ");
    scanf("%ld", &n);
  }

  printf("Digit:\t\t");
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    printf("%d ", i);
  }
  printf("\nOccurrences:\t");
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    printf("%d ", digits[i]);
  }
  printf("\n");
}

void c8p4() {
  int digits[10], i;

  printf("Enter %d numbers: ", (int)(sizeof(digits) / sizeof(digits[0])));
  for (i = 0; i < (int)(sizeof(digits) / sizeof(digits[0])); i++) {
    scanf("%d", &digits[i]);
  }

  printf("In reverse order:");
  for (i = (int)(sizeof(digits) / sizeof(digits[0])) - 1; i >= 0; i--) {
    printf(" %d", digits[i]);
  }
  printf("\n");
}

void c8p5() {
  int r, y, i, j, k;
  double a[5], s;

  printf("Enter interest rate: ");
  scanf("%d", &r);
  printf("Enter number of years: ");
  scanf("%d", &y);

  printf("Years\t");
  for (i = 0; i < 5; i++) {
    printf("%9d%%", r + i);
    a[i] = 100.0;
  }
  printf("\n");

  for (i = 1; i <= y; i++) {
    printf("%5d\t", i);
    for (j = 0; j < 5; j += 1) {
      s = 0;
      for (k = 0; k < 12; k += 1) {
        s += ((r + j) / 100.0) * a[j];
      }
      a[j] += s;
      printf("%10.2f", a[j]);
    }
    printf("\n");
  }
}

void c8p6() {
  int i;
  char m[256];

  printf("Enter message: ");
  for (i = 0; i < 256; i++) {
    m[i] = getchar();
    if (m[i] == '\n') {
      break;
    }
  }

  printf("In B1FF-speak: ");
  for (i = 0; i < 256; i++) {
    m[i] = toupper(m[i]);
    if (m[i] == '\n') {
      printf("!!!!!!!!!!\n");
      break;
    }
    switch (m[i]) {
    case 'A':
      printf("4");
      break;
    case 'B':
      printf("8");
      break;
    case 'E':
      printf("3");
      break;
    case 'I':
      printf("1");
      break;
    case 'O':
      printf("0");
      break;
    case 'S':
      printf("5");
      break;
    default:
      printf("%c", m[i]);
      break;
    }
  }
}

void c8p7() {
  int a[5][5], i, j, s[2][5] = {0};

  for (i = 0; i < 5; i++) {
    printf("Enter row %d: ", i + 1);
    scanf("%d%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
  }

  printf("Row totals: ");
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j += 1) {
      s[0][i] += a[i][j];
      s[1][i] += a[j][i];
    }
    printf("%d ", s[0][i]);
  }

  printf("\nColumn totals: ");
  for (i = 0; i < 5; i++) {
    printf("%d ", s[1][i]);
  }
  printf("\n");
}

#define N 5
void c8p8() {
  int a[N][N], i, j, t[N][2], s[2][N] = {0};

  printf("\n");
  for (i = 0; i < N; i++) {
    printf("Enter quiz grade %d: ", i + 1);
    for (j = 0; j < N; j += 1) {
      scanf("%d", &a[i][j]);
    }
  }

  for (i = 0; i < N; i++) {
    t[i][0] = 99;
    t[i][1] = 0;
    for (j = 0; j < N; j += 1) {
      s[0][i] += a[i][j];
      s[1][i] += a[j][i];
      if (a[i][j] < t[i][0]) {
        t[i][0] = a[i][j];
      }
      if (a[i][j] > t[i][1]) {
        t[i][1] = a[i][j];
      }
    }
  }

  printf("Student\t\t");
  for (i = 1; i <= N; i++) {
    printf("%3d ", i);
  }
  printf("\nAverage:\t");
  for (i = 0; i < N; i++) {
    printf("%3d ", (s[1][i] / N));
  }
  printf("\nTotal:\t\t");
  for (i = 0; i < N; i++) {
    printf("%3d ", s[1][i]);
  }

  printf("\nQuiz\t\t");
  for (i = 1; i <= N; i++) {
    printf("%3d ", i);
  }
  printf("\nAverage:\t");
  for (i = 0; i < N; i++) {
    printf("%3d ", (s[0][i] / N));
  }
  printf("\nLow Score:\t");
  for (i = 0; i < N; i++) {
    printf("%3d ", (t[i][0]));
  }
  printf("\nHigh Score:\t");
  for (i = 0; i < N; i++) {
    printf("%3d ", (t[i][1]));
  }
  printf("\n");
}

void c8p9() {
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
}

void c8p10() {
  int a[] = {616, 724, 811, 900, 968, 1075, 280, 1438},
      d[] = {480, 583, 679, 767, 840, 945, 1140, 1305}, h, m, t, i, j = -1, h1,
      m1, c1, h2, m2, c2;

  c1 = c2 = 'a';

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &h, &m);
  t = (h * 60) + m;

  for (i = 0; i < (int)((sizeof(d) / sizeof(d[0])) - 1); i++) {
    if (t < d[i] + (d[i + 1] - d[i]) / 2) {
      j = i;
      break;
    }
  }
  if (j == -1) {
    j = (int)((sizeof(d) / sizeof(d[0])) - 1);
  }

  if ((h1 = (d[j] / 60)) > 12) {
    h1 -= 12;
    c1 = 'p';
  }
  if ((h2 = (a[j] / 60)) > 12) {
    h2 -= 12;
    c2 = 'p';
  }
  m1 = d[j] % 60;
  m2 = a[j] % 60;

  printf("Closest Departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
         h1, m1, c1, h2, m2, c2);
}

void c8p11() {
  char c[15];
  int i;

  printf("Enter phone number: ");
  for (i = 0; i < (int)(sizeof(c) / sizeof(c[0])); i++) {
    if ((c[i] = getchar()) == '\n') {
      break;
    }
    switch (c[i]) {
    case 'A':
    case 'B':
    case 'C':
      c[i] = '2';
      break;
    case 'D':
    case 'E':
    case 'F':
      c[i] = '3';
      break;
    case 'G':
    case 'H':
    case 'I':
      c[i] = '4';
      break;
    case 'J':
    case 'K':
    case 'L':
      c[i] = '5';
      break;
    case 'M':
    case 'N':
    case 'O':
      c[i] = '6';
      break;
    case 'P':
    case 'R':
    case 'S':
      c[i] = '7';
      break;
    case 'T':
    case 'U':
    case 'V':
      c[i] = '8';
      break;
    case 'W':
    case 'X':
    case 'Y':
      c[i] = '8';
      break;
    }
  }

  printf("In numeric form: ");
  for (i = 0; i < (int)(sizeof(c) / sizeof(c[0])); i++) {
    printf("%c", c[i]);
    if (c[i] == '\n') {
      break;
    }
  }
}

void c8p12() {
  int s = 0, i;
  char p[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10},
       a[26], c;

  for (i = 0; i < (int)(sizeof(a) / sizeof(a[0])); i++) {
    a[i] = i + 65;
  }

  printf("Enter a word: ");
  while ((c = toupper(getchar())) != '\n') {
    for (i = 0; i < (int)(sizeof(a) / sizeof(a[0])); i++) {
      if (c == a[i]) {
        s += p[i];
        break;
      }
    }
  }

  printf("Scrabble value: %d\n", s);
}

void c8p13() {
  char c1, c2, c[20];
  int i, b;

  printf("Enter a first and last name: ");
  c1 = getchar();

  while (getchar() != ' ') {
    continue;
  }

  for (i = 0; i < (int)(sizeof(c) / sizeof(c[0])); i++) {
    if ((c2 = getchar()) == '\n') {
      b = i;
      break;
    }
    c[i] = c2;
  }

  printf("You entered the name: ");
  for (i = 0; i < b; i++) {
    printf("%c", c[i]);
  }
  printf(", %c.\n", c1);
}

void c8p14() {
  char c[64] = {' '};
  int i, j, k, n[32] = {0}, a, b;

  printf("Enter a sentence: ");
  for (i = 1, j = 1; i < (int)(sizeof(c) / sizeof(c[0])); i++) {
    c[i] = getchar();
    if (c[i] == ' ') {
      n[j] = i;
      j++;
    } else if (c[i] == '.' || c[i] == '?' || c[i] == '!') {
      a = b = i;
      break;
    }
  }

  printf("Reversal of sentence:");
  for (i = j - 1; i >= 0; i--) {
    for (k = n[i]; k < b; k++) {
      printf("%c", c[k]);
    }
    b = n[i];
  }
  printf("%c\n", c[a]);
}

void c8p15() {
  int n, i = 0;
  char ch, m[80] = {0};

  printf("Enter message to be encrypted: ");
  while ((ch = getchar()) != '\n' && i < (int)(sizeof(m) / sizeof(m[0]))) {
    m[i] = ch;
    i++;
  }

  printf("Enter shift amount (1-25): ");
  scanf("%d", &n);

  for (i = i; i >= 0; i--) {
    if (m[i] >= 'A' && m[i] <= 'Z') {
      m[i] = (((m[i] - 'A') + n) % 26) + 'A';
    } else if (m[i] >= 'a' && m[i] <= 'z') {
      m[i] = (((m[i] - 'a') + n) % 26) + 'a';
    }
  }

  printf("Encrypted message: ");
  while (m[i] != 0 && i < (int)(sizeof(m) / sizeof(m[0]))) {
    printf("%c", m[i]);
    i++;
  }
  printf("\n");
}

void c8p16() {
  char ch;
  int a[26] = {0}, i = 0;

  printf("Enter first word: ");
  while ((ch = tolower(getchar())) != '\n') {
    if (isalpha(ch)) {
      a[ch - 'a']++;
    }
  }

  printf("Enter second word: ");
  while ((ch = tolower(getchar())) != '\n') {
    if (isalpha(ch)) {
      a[ch - 'a']--;
    }
  }

  while (a[i] == 0 && i < (int)(sizeof(a) / sizeof(a[0]))) {
    i++;
  }

  if (i == (int)(sizeof(a) / sizeof(a[0]))) {
    printf("The words are anagrams.\n");
    return;
  }
  printf("The words are not anagrams.\n");
}

void c8p17() {
  int n, s[99][99] = {{0}, {0}}, r = 0, c, m = 1, i, j;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99\n");
  printf("Enter size of magic square: ");
  scanf("%d", &n);

  if (n > 99 || n % 2 == 0) {
    return;
  }

  c = n / 2;
  while (m <= (n * n)) {
    if (s[r][c] != 0) {
      c = (c - 1 + n) % n;
      r = (r + 2 + n) % n;
    }
    s[r][c] = m;
    r = (r + n - 1) % n;
    c = (c + 1) % n;
    m++;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%4d", s[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  c8p1();
  c8p2();
  c8p3();
  c8p4();
  c8p5();
  c8p6();
  c8p7();
  c8p8();
  c8p9();
  c8p10();
  c8p11();
  c8p12();
  c8p13();
  c8p14();
  c8p15();
  c8p16();
  c8p17();
  return 0;
}
