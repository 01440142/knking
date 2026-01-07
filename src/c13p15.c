#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

int evaluate_RPN_expression(const char *expression);
int pop(void);
void push(int n);

int main(void)
{
  char ch;
  char expression[STACK_SIZE], *p;

  while ((p = expression)) {
    printf("Enter an RPN expression: ");
    while ((ch = getchar()) != '\n' && p < expression + STACK_SIZE) {
      if (ch == 'q')
        exit(0);
      *p++ = ch;
    }
    *p = '\0';
    printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
  }

  return 0;
}

int evaluate_RPN_expression(const char *expression)
{
  const char *p;
  int temp;

  for (p = expression; *p != '=' && *p != '\0' && top < STACK_SIZE; p++)
    if (isdigit(*p))
      push(*p - '0');
    else
      switch (*p) {
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
      }

  return pop();
}

int pop(void)
{
  if (top == 0) {
    printf("Not enough operands in expression\n");
    exit(1);
  }
  return contents[--top];
}

void push(int n)
{
  if (top == STACK_SIZE) {
    printf("Expression is too complex\n");
    exit(1);
  }
  contents[top++] = n;
}
