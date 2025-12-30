#include <stdio.h>

int main(void)
{
  float a, t;

  printf("Enter amount of taxable income: ");
  scanf("%f", &a);

  if (a <= 750.0f)
    t = (0.01f * a);
  else if (a <= 2250.0f)
    t = 7.5f + (.02f * (a - 750.0f));
  else if (a <= 3750.0f)
    t = 37.5f + (.03f * (a - 2250.0f));
  else if (a <= 5250.0f)
    t = 82.5f + (.04f * (a - 3750.0f));
  else if (a <= 7000.0f)
    t = 142.5f + (.05f * (a - 5250.0f));
  else
    t = 230.0f + (.06f * (a - 7000.0f));

  printf("Tax due: $%.2f\n", t);

  return 0;
}
