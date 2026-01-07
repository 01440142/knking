#include <stdio.h>

int main(void)
{
  const char *ones[] = {"one", "two", "three", "four", "five", "six",
                        "seven", "eight", "nine"};
  const char *tens[] = {"twenty", "thirdy", "forty", "fifty", "sixty",
                        "seventy", "eighty", "ninety"};
  const char *special[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                           "fifteen", "sixteen", "seventeen", "eighteen",
                           "nineteen"};
  int n, m;

  printf("Enter a two-digit number: ");
  scanf("%1d%1d", &n, &m);

  if (n == 1)
    printf("%s\n", special[m]);
  else if (n == 0)
    if (m == 0)
      printf("zero\n");
    else
      printf("%s\n", ones[m-1]);
  else
    printf("%s-%s\n", tens[n-2], ones[m-1]);

  return 0;
}
