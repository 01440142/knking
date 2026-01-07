#include <stdio.h>

#define LEN 12

int main(void)
{
  const char *months[LEN] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };
  int month, day, year;

  printf("Enter a date (mm/dd/yyy): ");
  scanf("%2d/%2d/%4d", &month, &day, &year);
  if (month > 0 && month < LEN+1)
    printf("You entered the date %s %d, %4.4d\n", months[month-1], day, year);

  return 0;
}
