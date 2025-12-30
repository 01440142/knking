#include <stdio.h>

int main(void)
{
  char ch;
  int n1, d1, n2, d2, n3, d3;

  printf("Enter two fractions separated by an operator: ");
  scanf("%d/%d", &n1, &d1);
  ch = getchar();
  scanf("%d/%d", &n2, &d2);

  switch (ch) {
    case '+':
      n3 = (n1 * d2) + (n2 * d1);
      d3 = (d1 * d2);
      break;
    case '-':
      n3 = (n1 * d2) - (n2 * d1);
      d3 = (d1 * d2);
      break;
    case '*':
      n3 = (n1 * d2);
      d3 = (d1 * d2);
      break;
    case '/':
      n3 = (n1 * d2);
      d3 = (n2 * d1);
      break;
    default:
      return 1;
  }

  printf("The sum is %d/%d \n", n3, d3);
  return 0;
}
