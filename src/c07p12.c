#include <stdio.h>

int main(void)
{
  char ch;
  float e1, e2;

  printf("Enter an expression: ");
  scanf("%f", &e1);

  while(scanf("%c", &ch) != '\n') {
    scanf("%f", &e2);
    switch (ch) {
      case '+': e1 += e2; break;
      case '-': e1 -= e2; break;
      case '*': e1 *= e2; break;
      case '/': e1 /= e2; break;
    }
  }

  printf("Value of expression: %.1f\n", s1);

  return 0;
}
