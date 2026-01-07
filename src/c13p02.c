/* Prints a one-month reminder list */

#include<stdio.h>
#include<string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
  char reminders[MAX_REMIND][MSG_LEN+13];
  char date_str[13], msg_str[MSG_LEN+1];
  int day, month, hour, minute;
  int i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter month/day, a 24-hour time and reminder: ");
    scanf("%2d/%2d", &month, &day);
    if (month == 0)
      break;
    else if (day > 31 || day < 1) {
      printf("Day must be between 1 and 31; Reminder ignored!\n");
      continue;
    }
    scanf("%2d:%2d", &hour, &minute);
    sprintf(date_str, "%2.2d/%2.2d %2.2d:%2.2d ", day, month, hour, minute);

    for (i = 0; i < num_remind; i++)
      if (strcmp(date_str, reminders[i]) <= 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], date_str);
    read_line(msg_str, MSG_LEN);
    strcat(reminders[i], msg_str);
    num_remind++;
  }

  printf("\n Date  Time  Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf("%s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
