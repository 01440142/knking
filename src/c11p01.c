#include <stdio.h>

#define FIVE 5
#define ONE 1
#define TEN 10
#define TWENTY 20

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
  int dollars, twenties, tens, fives, ones;

  printf("Enter a dollar amount: ");
  scanf("%d", &dollars);
  pay_amount(dollars, &twenties, &tens, &fives, &ones);

  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf(" $5 bills: %d\n", fives);
  printf(" $1 bills: %d\n", ones);

  return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
  *twenties = dollars / TWENTY;
  dollars -= *twenties * TWENTY;
  *tens = dollars / TEN;
  dollars -= *tens * TEN;
  *fives = dollars / FIVE;
  dollars -= *fives * FIVE;
  *ones = dollars;
}
