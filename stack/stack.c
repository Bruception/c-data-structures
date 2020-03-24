
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define DEFAULT_CAPACITY 16

stack* create_stack() {
  stack* stk = (stack*)malloc(sizeof(stack));

  stk->capacity = DEFAULT_CAPACITY;

  stk->data = (int*)malloc(sizeof(int) * DEFAULT_CAPACITY);
  stk->top = -1;

  return stk;
}

int peek_stack(stack* stk) {
  // Exit if stack is empty.
  if(stk->top == -1) exit(1);

  return stk->data[stk->top];
}

void push_stack(stack* stk, int value) {
  if(stk->top == stk->capacity) return;

  ++stk->top;
  stk->data[stk->top] = value;
}