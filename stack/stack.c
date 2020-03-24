
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define DEFAULT_CAPACITY 16

stack* create_stack() {
  stack* stk = (stack*)malloc(sizeof(stack));

  stk->capacity = DEFAULT_CAPACITY;
  stk->size = 0;

  stk->data = (int*)malloc(sizeof(int) * DEFAULT_CAPACITY);
  stk->top = stk->data;

  return stk;
}

int peek_stack(stack* stk) {
  // Exit if stack is empty
  if(stk->size == 0) exit(1);

  return *(stk->top);
}

