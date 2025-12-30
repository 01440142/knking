#include <stdio.h>

int main(void) {
  int a;
  float p, v, c, r;

  printf("Enter amount of shares: ");
  scanf("%d", &a);
  printf("Enter values per share: ");
  scanf("%f", &p);
  v = a * p;

  if (v < 2500.0f)
    c = 30.0f + (.017f * v);
  else if (v < 6250.0f)
    c = 56.0f + (.0066f * v);
  else if (v < 20000.0f)
    c = 76.0f + (.0034f * v);
  else if (v < 50000.0f)
    c = 100.0f + (.0022f * v);
  else if (v < 500000.0f)
    c = 155.0f + (.0011f * v);
  else
    c = 255.0f + (.0009f * v);

  if (c < 39.0f)
    c = 39.0f;
  printf("Commission: $%.2f\n", c);

  if (a < 2000)
    r = 33.0f + (.03f * a);
  else
    r = 33.0f + (.02f * a);
  printf("Commission (rival): $%.2f\n", r);

  return 0;
}
