#include<stdio.h>

#define N 10

void max_min(int *a, int *max, int *min);

int main(void)
{
  int a[N], *p, max, min;

  printf("Enter %d numbers: ", N);
  for (p = a; p < a + N; p++)
    scanf("%d", p);

  max_min(a, &max, &min);
  printf("Largest: %d\n", max);
  printf("Smallest: %d\n", min);

  return 0;
}

void max_min(int *a, int *max, int *min)
{
  int *p;

  *max = *min = *a;
  for (p = a + 1; p < a + N; p++) {
    if (*p > *max)
      *max = *p;
    else if (*p < *min)
      *min = *p;
  }
}
