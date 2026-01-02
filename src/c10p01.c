#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

char pop(void);
void push(char c);

int main(void)
{
  char ch;

  printf("Enter parentheses and/or braces: ");
  do {
    scanf("%c", &ch);
    switch (ch) {
    case '(':
    case '{':
      push(ch);
      break;
    case ')':
      if (pop() != '(') {
        printf("Parentheses aren't nested properly\n");
        return 1;
      }
      break;
    case '}':
      if (pop() != '{') {
        printf("Braces aren't nested properly\n");
        return 1;
      }
      break;
    }
  } while (ch != '\n');

  if (top != 0) {
    printf("Parentheses/braces aren't nested properly\n");
    return 1;
  }
  printf("Parentheses/braces are nested properly\n");

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
