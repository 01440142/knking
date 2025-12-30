#include <stdio.h>

void selection_sort(int a[], int n);

int main (void)
{
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

  return 0;
}

void selection_sort(int a[], int n)
{
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
