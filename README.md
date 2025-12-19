# C Programming: A Modern Approach

## 11 Pointers

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
