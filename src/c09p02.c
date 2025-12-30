#include <stdio.h>

float income_tax(float a);

int main(void)
{
  float amount;

  printf("Enter amount of taxable income: ");
  scanf("%f", &amount);
  printf("Tax due: $%.2f\n", income_tax(amount));

  return 0;
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

