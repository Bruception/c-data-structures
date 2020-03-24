
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack* create_stack(int capacity) {
  if(capacity <= 0) exit(1);

  stack* stk = (stack*)malloc(sizeof(stack));

  stk->capacity = capacity;

  stk->data = (int*)malloc(sizeof(int) * capacity);
  stk->top = -1;

  return stk;
}

int peek_stack(stack* stk) {
  // Exit if stack is empty.
  if(stk->top == -1) exit(1);

  return stk->data[stk->top];
}

void ensure_capacity(stack* stk) {
  if(stk->top < stk->capacity) return;

  // Double capacity
  stk->capacity *= 2;

  int* newdata = (int*)realloc(stk->data, sizeof(int) * stk->capacity);

  // Allocation failed
  if(newdata == NULL) exit(1);

  stk->data = newdata;
}

void push_stack(stack* stk, int value) {
  ensure_capacity(stk);

  ++stk->top;
  stk->data[stk->top] = value;
}

int pop_stack(stack* stk) {
  if(stk->top == -1) exit(1);

  int value = stk->data[stk->top];
  --stk->top;

  return value;
}

void clear_stack(stack* stk) {
  if(stk->top == -1) return;

  stk->top = -1;
}

int size_stack(stack* stk) {
  return stk->top + 1;
}

void dump_stack(stack* stk) {
  printf("Stack@%p - Size: %d :\n", stk, stk->top + 1);

  if(stk->top == -1) {
    printf("[]\n");
    return;
  }

  printf("[%d", stk->data[stk->top]);

  for(int i = stk->top - 1; i >= 0; --i) {
    printf(", %d", stk->data[i]);
  }

  printf("]\n");
}
