#include <stdio.h>

#define N 5

int main(void)
{
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

  return 0;
}
