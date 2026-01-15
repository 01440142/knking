#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
  top = 0;
}

int is_empty(void)
{
  return top == 0;
}

int is_full(void)
{
  return top == STACK_SIZE;
}

void stack_overflow(void)
{
  printf("Expression is too complex\n");
  exit(1);
}

void push(int i)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = i;
}

void stack_underflow(void)
{
  printf("Not enough operands in expression\n");
  exit(1);
}

int pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];
}
