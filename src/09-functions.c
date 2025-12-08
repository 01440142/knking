#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool equal_array(int counts1[26], int counts2[26]);
bool play_game(void);
float income_tax(float a);
int polynomial(int x);
int power(int x, int n);
int roll_dice(void);
void create_magic_square(int n, char magic_square[99][99]);
void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);
void print_magic_square(int n, char magic_square[99][99]);
void read_word(int counts[26]);
void selection_sort(int a[], int n);

void c9p1(void);
void c9p2(void);
void c9p3(void);
void c9p4(void);
void c9p5(void);
void c9p6(void);
void c9p7(void);
void c9p8(void);

/**
 * 01. double triangle_area(double base, double height) {
 *       double product = base * height;
 *       return product / 2;
 *     }
 * 02. int check(int x, int y, int n) {
 *       n--;
 *       return (x >= 0 && x <= n) && (y >= 0 && y <= n);
 *     }
 * 03. int gcd(int m, int n) {
 *       int r;
 *       while (n > 0) {
 *         r = m % n;
 *         m = n;
 *         n = r;
 *       }
 *       return m;
 *     }
 * 04. int day_of_year(int month, int day, int year) {
 *       int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 *       int total = 0, i;
 *
 *       month--;
 *       if (year % 4 == 0) {
 *         m[1]++;
 *       }
 *
 *       for (i = 0; i < month; i++) {
 *         total += m[i];
 *       }
 *       total += day;
 *
 *       return total;
 *     }
 *
 * 05. int num_digits(int n) {
 *       int d = 0;
 *       if (n == 0) {
 *         return 1;
 *       }
 *       while (n != 0) {
 *         n /= 10;
 *         d++;
 *       }
 *       return d;
 *     }
 * 06. int digit(int n, int k) {
 *       if (k == 0) {
 *         return 0;
 *       }
 *       while (k > 1) {
 *         k--;
 *         n /= 10;
 *       }
 *       return n % 10;
 *     }
 * 07. All are legal statements.
 * 08. (a) and (b) are valid prototypes.
 * 09. i = 1, j = 2
 * 10. (a) int largest(int a[], int n) {
 *           int l = a[0], i;
 *           for (i = 1; i < n; i++) {
 *             if (l < a[i]) {
 *               l = a[i];
 *             }
 *           };
 *           return l;
 *         }
 *     (b) int average(int a[], int n) {
 *           int avg = 0, i;
 *           for (i = 0; i < n; i++) {
 *             avg += a[i];
 *           }
 *           return avg /= n;
 *         }
 *     (c) int positive(int a[], int n) {
 *           int p = 0, i;
 *           for (i = 0; i < n; i++) {
 *             if (a[i] > 0) {
 *               p++;
 *             }
 *           }
 *           return p;
 *         }
 * 11. float compute_GPA(char grades[], int n) {
 *       int i;
 *       float avg = 0.0f;
 *
 *       for (i = 0; i < n; i++) {
 *         switch (toupper(grades[i])) {
 *         case 'A':
 *           avg += 4.0f;
 *           break;
 *         case 'B':
 *           avg += 3.0f;
 *           break;
 *         case 'C':
 *           avg += 2.0f;
 *           break;
 *         case 'D':
 *           avg += 1.0f;
 *           break;
 *         }
 *       }
 *
 *       return avg / n;
 *     }
 * 12. double inner_product(double a[], double b[], int n) {
 *       int i;
 *       double total = 0.0;
 *
 *       for (i = 0; i < n; i++) {
 *         total += a[i] * b[i];
 *       }
 *
 *       return total;
 *     }
 * 13. int evaluate_position(char board[8][8]) {
 *       int b = 0, w = 0, i, j;
 *
 *       for (i = 0; i < 8; i++) {
 *         for (j = 0; j < 8; j++) {
 *           switch (board[i][j]) {
 *           case 'Q':
 *             w += 9;
 *             break;
 *           case 'R':
 *             w += 5;
 *             break;
 *           case 'B':
 *           case 'N':
 *             w += 3;
 *             break;
 *           case 'P':
 *             w += 1;
 *             break;
 *           case 'q':
 *             b += 9;
 *             break;
 *           case 'r':
 *             b += 5;
 *             break;
 *           case 'b':
 *           case 'n':
 *             b += 3;
 *             break;
 *           case 'p':
 *             b += 1;
 *             break;
 *           }
 *         }
 *       }
 *
 *       return w - b;
 *     }
 * 14. bool has_zero(int a[], int n) {
 *       int i;
 *
 *       for (i = 0; i < n; i++) {
 *         if (a[i] == 0) {
 *           return true;
 *         }
 *       }
 *
 *       return false;
 *     }
 * 15. double median(double x, double y, double z) {
 *       double r;
 *
 *       if (x <= y) {
 *         if (y <= z) {
 *           r = y;
 *         } else if (x <= z) {
 *           r = z;
 *         } else {
 *           r = x;
 *         }
 *       } else {
 *         if (z <= y) {
 *           r = y;
 *         } else if (x <= z) {
 *           r = x;
 *         } else {
 *           r = z;
 *         }
 *       }
 *
 *       return r;
 *     }
 * 16. int fact(int n) {
 *       return n <= 1 ? 1 : n * fact(n - 1);
 *     }
 * 17. int fact(int n) {
 *       int r = 1;
 *       while (n >= 1) {
 *         r *= n;
 *         n--;
 *       }
 *       return r;
 *     }
 * 18. int gcd(int m, int n) {
 *       if (n == 0) {
 *         return m;
 *       }
 *       return gcd(n, m % n);
 *     }
 * 19. The function prints the binary representation of a decimal number.
 */

int main(void) {
  c9p1();
  c9p2();
  c9p3();
  c9p4();
  c9p5();
  c9p6();
  c9p7();
  c9p8();
  return 0;
}

void c9p1(void) {
  int a[64] = {0};
  int a_size = (int)(sizeof(a) / sizeof(a[0]));
  int i = 0, d;

  printf("Enter a series of integers (0 terminates input): ");
  do {
    scanf("%d", &d);
    a[i] = d;
    i++;
  } while (d != 0 && i < a_size);
  a_size = --i;

  selection_sort(a, a_size);
  printf("Sorted integers: ");
  for (i = 0; i < a_size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void selection_sort(int a[], int n) {
  int largest = 0, temp, i;

  if (n <= 1) {
    return;
  }
  for (i = 1; i < n; i++) {
    if (a[i] > a[largest]) {
      largest = i;
    }
  }

  temp = a[largest];
  a[largest] = a[n - 1];
  a[n - 1] = temp;
  selection_sort(a, n - 1);
}

void c9p2(void) {
  float amount;
  printf("Enter amount of taxable income: ");
  scanf("%f", &amount);
  printf("Tax due: $%.2f\n", income_tax(amount));
}

float income_tax(float a) {
  if (a <= 750.0f) {
    return (0.01f * a);
  }
  if (a <= 2250.0f) {
    return 7.5f + (.02f * (a - 750.0f));
  }
  if (a <= 3750.0f) {
    return 37.5f + (.03f * (a - 2250.0f));
  }
  if (a <= 5250.0f) {
    return 82.5f + (.04f * (a - 3750.0f));
  }
  if (a <= 7000.0f) {
    return 142.5f + (.05f * (a - 5250.0f));
  }
  return 230.0f + (.06f * (a - 7000.0f));
}

void c9p3(void) {
  char walk[10][10];
  generate_random_walk(walk);
  print_array(walk);
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

void c9p4(void) {
  int counts1[26] = {0};
  int counts2[26] = {0};

  read_word(counts1);
  read_word(counts2);

  if (equal_array(counts1, counts2)) {
    printf("The words are anagrams.\n");
  } else {
    printf("The words are not anagrams.\n");
  }
}

void read_word(int counts[26]) {
  char ch;
  printf("Enter word: ");
  while ((ch = tolower(getchar())) != '\n') {
    if (isalpha(ch)) {
      counts[ch - 'a']++;
    }
  }
}

bool equal_array(int counts1[26], int counts2[26]) {
  int i;
  for (i = 0; i < 26; i++) {
    if (counts1[i] != counts2[i]) {
      return false;
    }
  }
  return true;
}

void c9p5(void) {
  char magic_square[99][99] = {{0}, {0}};
  int n;

  printf("This program creates a magic square of a specified size.\n");
  printf("The size must be an odd number between 1 and 99\n");
  printf("Enter size of magic square: ");
  scanf("%d", &n);

  create_magic_square(n, magic_square);
  print_magic_square(n, magic_square);
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

void c9p6(void) {
  int x;

  printf("Enter value for x: ");
  scanf("%d", &x);

  printf("%d\n", polynomial(x));
}

int polynomial(int x) {
  int result = 0;

  result += 3 * (x * x * x * x * x);
  result += 2 * (x * x * x * x);
  result -= 5 * (x * x * x);
  result -= 1 * (x * x);
  result += 7 * (x);
  result -= 6;

  return result;
}

void c9p7(void) {
  int x, n;

  printf("Enter x: ");
  scanf("%d", &x);
  printf("Enter n: ");
  scanf("%d", &n);

  printf("x^n = %d\n", power(x, n));
}

int power(int x, int n) {
  int temp;

  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    temp = power(x, n / 2);
    return temp * temp;
  }
  return x * power(x, n - 1);
}

void c9p8(void) {
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
