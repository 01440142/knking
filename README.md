# C Programming: A Modern Approach

## Chapter 2 - C Fundamentals

01. Yes. It needs a `return` statement with an integer value.
02. (a) One directive and four statements.
    (b) ```c
        Parkinson's Law:
        Work expands so as to fill the time
        available for its completion.
        ```
03.
```c
int height = 8, length = 12, width = 10;
printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);
```
04. There isn't a pattern.
```c
int a, b, c;
float x, y, z;
printf("%d, %d, %d", a, b, c);
printf("%f, %f, %f", x, y, z);
```
05. (b), (c) and (d) are legal.
06. The readability is weak.
07. (a) and (e) are keywords.
08. fourteen
09. `answer = (3 * q - p * p) / 3;`
10. The text inside the printf statements, the return statement with zero and
    the include directive.

## Chapter 3 - Formatted Input/Output

1. (a) `  86,1040` (b) `3.02530e+01` (c) `83.1620` (d) `1e-06`
2. (a) `printf("%-8.1e\n", x);`
   (b) `printf("%10.6e\n", x);`
   (c) `printf("%-8.3f\n", x);`
   (d) `printf("%6.0f\n", x);`
3. (a) and (d) are equivalent.
   (b) The second expression allows any number of spaces before the hyphens.
   (c) The second expression causes the program to search for an additional
       non-whitespace character.
4. `i = 10, x = .3, j = 5;`
5. `x = 12.3, i = 45, y = .6;`
6.
```c
scanf("%d /%d", &num1, &denom1);
scanf("%d /%d", &num2, &denom2);
```

## Chapter 4 - Expressions

01. (a) `1 2` (b) `0` (c) `1` (d) `0`
02. Yes (C99). In mathematical fractions a minus sign before the fraction is
    equivalent to a minus sign within either the nominator/denominator.
03. (a) `1` (b) `-1`, `-2` (c) `-1`, `-2` (d) `1`
04. (a) `1` (b) `-1` (c) `-1` (d) `1`
05. (a) `3` (b) `-3`, `2` (c) `-3`, `2` (d) `-3`, `2`
06. (a) `3` (b) `-3` (c) `3` (d) `-3`
07. `9 - ((x - 1) % 10)` is not equivalent to `10 - (x % 10)` If the total
    is something to the power of `10`, then the modulo `10` operation would
    result in `0`. The check digit would remain `10` instead of `0`.
08. Yes, because the total to the power of `10` problem in the previous
    question would be resolved.
09. (a) `63 8` (b) `3 2 1` (c) `2 -1 3` (d) `0 0 0`
10. (a) `12 12` (b) `3 4` (c) `2 8` (d) `6 9`
11. (a) `0 2` (b) `4 11 6` (c) `0 8 7` (d) `3 4 5 4`
12. (a) `6 16` (b) `6 -7` (c) `6 23` (d) `6 15`
13. Both `++i` and `i++` have the side effect to increment `i` by one. The
    expression `++i` is equivalent to `(i += 1)` because both fetch the
    increased value of `i` alias `(i + 1)`.
14. (a) `(((a * b) - (c * d)) + e)`
    (b) `((((a / b) % c) / d)`
    (c) `((((-a) - b) + c) - (+d))`
    (d) `(((a * (-b)) / c) - d)`
15. (a) `3`, `2` (b) `0`, `2` (c) `1`, `2` (d) `1`, `3`

## Chapter 5 - Selection Statements

01. (a) `1` (b) `1` (c) `1` (d) `0`
02. (a) `1` (b) `1` (c) `1` (d) `1`
03. (a) `1 3 4 5` (b) `0 7 8 9` (c) `1 8 8 9` (d) `1 2 1 1`
04. `(i > j) - (i < j)`
05. Yes. It prints `0 is between 1 and 10`.
06. Yes. It does nothing.
07. `17`. `17`.
08. `teenager = age > 12 && age < 20;`
09. They are equivalent.
10. `onetwo`
11.
```c
switch (area_code) {
  case 229:
    printf("Albany\n");
    break;
  case 404:
  case 470:
  case 678:
  case 770:
    printf("Atlanta\n");
    break;
  case 478:
    printf("Macon\n");
    break;
  case 706: case 762:
    printf("Columbus\n");
    break;
  case 912:
    printf("Savannah\n");
    break;
  default:
    printf("Area code not recognized\n");
    break;
}
```

## Chapter 6 - Loops

01. `1 2 4 8 16 32 64 128`
02. `9384 938 93 9`
03. `5 4 3 2`
04. (c) is not equivalent.
05. (c) is (again) not equivalent.
06.
```c
for (i = 1; i <= 128; i *= 2)
  printf("%d ", i);
```
07.
```c
for (i = 9384; i > 0; i /= 10)
  printf("%d ", i);
```
08. `10 5 3 2 1 1 1...`
09.
```c
i = 10;
while (i >= 1) {
  printf("%d ", i++);
  i /= 2;
}
```
10.
```c
for (...) {
  ...
  goto eol; /* here would be continue */
  ...
  eol:;
}
11. `20`
12.
```c
for (d = 2; d * d <= n; d++)
  if (n % d == 0)
    break;
```
13. `for (n = 0; m > 0; m /= 2, n++);`
14.
```c
if (n % 2 == 0)
  printf("n is even\n");
```

## Chapter 7 - Basic Types

01. (a) `63` (b) `119` (c) `2748`
02. (a), (b) and (e) are legal floating-point.
    (c) and (d) are illegal integers.
03. (b) is an illegal type.
04. (d) is an illegal type.
05. (b) is an illegal type.
06. (a) `char` (b) `short` (c) `short` (d) `long`
07. (a) `\010` (b) `\012` (c) `\015` (d) `\011`
08. (a) `\0x8` (b) `\0xA` (c) `\0xD` (d) `\0x9`
09. `int`
10. `unsigned int`
11. `double`
12. `i` is converted to `float` and `(i + f)` is promoted to `double`.
13. (a) `-3` `int`
    (b) `7` `long`
    (c) `6.5` `float`
    (d) `3.75` `double`
    (e) `-1` `double`
    (f) `6` `int`
14. No, `f` could exceed the integer range.
15.
```c
typedef char Int8;
typedef short Int16;
typedef int Int32;
```

## Chapter 8 - Arrays

01. The expression is no longer valid after the type is changed. Furthermore
    the correctness of `t` isn't guaranteed and needs to be checked
    elsewhere in the code.
02. `digit_count[d-'0'];`
03. `bool weekend[] = {1, 0, 0, 0, 0, 0, 1};`
04. `bool weekend[] = {[0] = 1, [6] = 1};`
05.
```c
int i, fib_numbers[40] = {0, 1};
for (i = 2; i < (sizeof(fib_numbers)/sizeof(fib_numbers[0])); i++)
  fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];
```
06.
```c
const int segments[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1} 
};
```
07.
```c
const int segments[10][7] = {
  {1, 1, 1, 1, 1, 1},
  {[1] = 1, 1},
  {1, 1, [3] = 1, 1, [6] = 1},
  {1, 1, 1, 1, [6] = 1},
  {[1] = 1, 1, [5] = 1, 1},
  {1, [2] = 1, 1, [5] = 1, 1},
  {1, [2] = 1, 1, 1, 1, 1},
  {1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, [5] = 1, 1 }
};
```
08. `float temperature_readings[30][24];`
09.
```c
for (i = 0; i < 30; i++)
  for (j = 0; j < 24; j++)
    a += temperature_readings[i][j];
m /= 30 * 24;
```
10.
```c
const int chess_board[8][8] = {
  {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
  {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
  {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
  {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
  {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
  {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
  {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
  {'R', 'N', 'B'. 'Q', 'K', 'B', 'N', 'R'}
};
```
11.
```c
char checker_board[8][8];
for (i = 0; i < 8; i++)
  for(j = 0; j < 8; j++)
    checker_board[i][j] = (i + j) % 2 ? 'R' : 'B';
```

## Chapter 9 - Functions

01.
```c
double triangle_area(double base, double height) {
  return (base * height) / 2;
}
```
02.
```c
int check(int x, int y, int n)
{
  n--;
  return (x >= 0 && x <= n) && (y >= 0 && y <= n);
}
```
03.
```c
int gcd(int m, int n)
{
  int r;
  while (n > 0) {
    r = m % n;
    m = n;
    n = r;
  }
  return m;
}
```
04.
```c
int day_of_year(int month, int day, int year)
{
  int i, total = 0, m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (year % 4 == 0)
    m[1]++;
  for (i = 0; i < --month; i++)
    total += m[i];

  return total + day;
}
```
05.
```c
int num_digits(int n)
{
  int d = 0;
  if (n == 0)
    return 1;
  while (n != 0) {
    n /= 10;
    d++;
  }
  return d;
}
```
06.
```c
int digit(int n, int k)
{
  if (k == 0)
    return 0;
  while (k > 1) {
    k--;
    n /= 10;
  }
  return n % 10;
}
```
07. All are legal statements.
08. (a) and (b) are valid prototypes.
09. i = 1, j = 2
10. (a)
```c
int largest(int a[], int n)
{
  int i, largest = a[0];
  for (i = 1; i < n; i++)
    if (largest < a[i])
      largest = a[i];
  return largest;
}
```
(b)
```c
int average(int a[], int n)
{
  int i, avg = 0;
  for (i = 0; i < n; i++)
    avg += a[i];
  return avg /= n;
}
```
(c)
```c
int positive(int a[], int n)
{
  int i, positive = 0;
  for (i = 0; i < n; i++)
    if (a[i] > 0)
      p++;
  return p;
}
```
11.
```c
float compute_GPA(char grades[], int n)
{
  int i;
  float avg = 0.0f;

  for (i = 0; i < n; i++) {
    switch (toupper(grades[i])) {
      case 'A': avg += 4.0f; break;
      case 'B': avg += 3.0f; break;
      case 'C': avg += 2.0f; break;
      case 'D': avg++;       break;
    }
  }

  return avg / n;
}
```
12.
```c
double inner_product(double a[], double b[], int n)
{
  int i;
  double total = 0.0;
  for (i = 0; i < n; i++)
    total += a[i] * b[i];
  return total;
}
```
13.
```c
int evaluate_position(char board[8][8])
{
  int i, j, total = 0;

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      switch (board[i][j]) {
        case 'Q': total += 9; break;
        case 'R': total += 5; break;
        case 'B':
        case 'N': total += 3; break;
        case 'P': total++;    break;
        case 'q': total -= 9; break;
        case 'r': total -= 5; break;
        case 'b':
        case 'n': total -= 3; break;
        case 'p': total--;    break;
      }
    }
  }

  return total;
}
```
14.
```c
bool has_zero(int a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    if (a[i] == 0)
      return true;
  return false;
}
```
15.
```c
double median(double x, double y, double z)
{
  double median;

  if (x <= y)
    if (y <= z)
      median = y;
    else if (x <= z)
      median = z;
    else
      median = x;
  else
    if (z <= y)
      median = y;
    else if (x <= z)
      median = x;
    else
      median = z;

  return median;
}
```
16.
```c
int fact(int n) {
  return n <= 1 ? 1 : n * fact(n - 1);
}
```
17.
```c
int fact(int n)
{
  int r = 1;
  while (n-- >= 1)
    r *= n;
  return r;
}
18.
```c
int gcd(int m, int n)
{
  if (n == 0)
    return m;
  return gcd(n, m % n);
}
```
19. The function prints the binary representation of a decimal number.

## Chapter 10 - Program Organization

01. (a) a, b, c (b) a, d (c) a, d, e (d) a, f
02. (a) b (inside f), c, d
    (b) a, b, c (inside g)
    (c) a (inside block), b, c (inside g), d
    (d) b, c (inside main), d
03. There could be an indefinite amount of `i` variables. There is no limit
    to the number of blocks being created within main.

## Chapter 11 - Pointers

01. (a) `*p` and (g) `*&i` are aliases for `i`.
02. (e) `p = *&q;`, (f) `p = q;` and (i) `*p = *q;` are legal assignments.
03.
```c
void avg_sum(double a[], int n, double *avg, double *sum) {
  int i;
  *sum = 0.0;
  for (i = 0; i < n; i++) {
    *sum += a[i];
  }
  *avg = *sum / n;
}
```
04.
```c
void swap(int *p, int *q) {
  int temp = *p;
  *q = *p;
  *p = temp;
}
```
05.
```c
void split_time(long total_sec, int *hr, int *min, int *sec) {
  *hr = total_sec / 3600; 
  *min = (total_sec / 60) % 60; 
  *sec = total_sec % 3600;
}
```
06.
```c
void find_two_largest(int a[], int n, int *largest, int *second_largest) {
  int i;
  *largest = *second_largest = a[0];
  for (i = 1; i < n; i++) {
    if (*largest < a[i]) {
      *second_largest = *largest;
      *largest = a[i];
    } else if (*second_largest < a[i]) {
      *second_largest = a[i];
    }
  }
}
```
07.
```c
#define N 12
void split_date(int day_of_year, int year, int *month, int *day) {
  int months[N] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i, sum = 0;

  if (year % 4 == 0) {
    months[1]++;
  }
  for (i = 0; i < N; i++) {
    sum += months[i];
    if (day_of_year <= sum) {
      break;
    }
  }
  *month = i + 1;
  *day = day_of_year - (sum - months[i]);
}
```
08.
```c
int *find_largest(int a[], int n) {
  int i, *p = &a[0];
  for (i = 1; i < n; i++) {
    if (*p < a[i]) {
      p = &a[i];
    }
  }
  return p;
}
```

## Chapter 12 - Pointers and Arrays

01. (a) `14` (b) `34` (c) `&a[4]` (d) `true` (e) `false`
02. Pointer arithmetic only allows the addition of pointers and integers. In
    contrast the subtraction of two pointers is allowed. The following
    statement would be a fix: `middle = low + (high - low) / 2;`.
03. `{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}`
04.
```c
void make_empty(void)
{
  top_ptr = &contents[0];
}

bool is_empty(void)
{
  return top_ptr == &contents[0};
}

bool is_full(void)
{
  return top_ptr == &contents[STACK_SIZE];
}
```
05. (a) `p == a[0]` is an illegal expression.
    (b) `p == &a[0]`, (c) `*p == a[0]` and (d) `p[0] == a[0]` are true.
06.
```c
int sum_array(const int a[], int n)
{
  int *p, sum;

  sum = 0
  for (p = a; p < a + n; p++)
    sum += *p;
  return sum;
}
```
07.
```c
bool search(const int a[], int n, int key)
{
  int *p;

  for (p = a; p < a + n; p++)
    if (*p == key)
      return true;
  return false;
}
```
08.
```c
void store_zeros(int a[], int n)
{
  int *p;

  for (p = a; p < a + n; p++)
    *p = 0;
}
```
09.
```c
double inner_product(const double *a, const double *b, int n)
{
  int i = 0;
  double sum = 0.0;

  while (i++ < n)
    sum += (*a++) * (*b++);
  return sum;
}
```
10.
```c
int *find_middle(int a[], int n) {
  return a + n / 2;
}
```
11.
```c
int find_largest(int a[], int n)
{
  int *p, max;

  max = *a;
  for (p = a + 1; p < a + n; p++)
    if (*p > max)
      max = *p;
  return max;
}
```
12.
```c
void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
  int *p;

  *largest = *second_largest = *a;
  for (p = a; p < a + n; p++) {
    if (*p > *largest) {
      *second_largest = *largest;
      *largest = *p;
    } else if (*p > *second_largest)
      *second_largest = *p;
  }
}
```
13.
```c
#define N 10

double *p, ident[N][N];
int count;

for (p = ident[0], count = 0; p < ident[0] + (N*N); p++, count++)
  if (count % (N+1) == 0)
    *p = 1.0;
  else
    *p = 0.0;
```
14. `search(temperatures, 168, 32);`
15. ```
```c
int *p;
for (p = temperatures[i]; p < temperatures[i] + 24; p++)
  ;
```
16.
```c
int (*p)[24];
for (p = temperatures; p < temperatures + 7; p++)
  find_largest(p[0], 24);
```
17.
```c
int sum_two_dimensional_array(const int a[][LEN], int n)
{
  const int *p;
  int sum = 0;
  for (p = a[0]; p < a + (n * LEN); p++)
    sum += *p;
  return sum;
}
```
18.
```c
int evaluate_position(char board[8][8]) {
  char *p;
  int total = 0;

  for (p = board[0]; p < board[0] + 64; p++) {
    switch (*p) {
      case 'Q': total += 9; break;
      case 'R': total += 5; break;
      case 'B':
      case 'N': total += 3; break;
      case 'P': total++;    break;
      case 'q': total -= 9; break;
      case 'r': total -= 5; break;
      case 'b':
      case 'n': total -= 3; break;
      case 'p': total--;    break;
    }
  }

  return total;
}
```
