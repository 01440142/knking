#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

char pop(void);
void push(char c);

int main(void)
{
  bool next;
  char ch, temp;

  while (1) {
    next = true;
    top = 0;
    printf("Enter an RPN expression: ");
    while (next) {
      scanf(" %c", &ch);
      if (isdigit(ch)) {
        push(ch - '0');
        continue;
      }
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
        next = false;
        break;
      default:
        exit(0);
        break;
      }
    }
  }

  return 0;
}

char pop(void) {
  if (top == 0) {
    printf("Not enough operands in expression\n");
    printf("Can't pop empty stack! Stack Underflow!\n");
    exit(1);
  }
  top--;
  return contents[top];
}

void push(char c) {
  if (top == STACK_SIZE) {
    printf("Expression is too complex\n");
    printf("Can't push full stack! Stack Overflow!\n");
    exit(1);
  }
  contents[top] = c;
  top++;
}
