#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
  bool keep_reading;
  char ch, temp;

  for (;;) {
    make_empty();
    keep_reading = true;
    printf("Enter an RPN expression: ");
    while ((ch = getchar()) && keep_reading) {
      if (isdigit(ch))
        push(ch - '0');
      else
        switch (ch) {
          case '+':
            push(pop() + pop());
            break;
          case '-':
            temp = pop();
            push(pop() - temp);
            break;
          case '/':
            temp = pop();
            push(pop() / temp);
            break;
          case '*':
            push(pop() * pop());
            break;
          case '=':
            printf("Value of expression: %d\n", pop());
            keep_reading = false;
            break;
          case 'q':
            exit(0);
            break;
        }
    }
  }

  return 0;
}
