
#ifndef STACK_H
#define STACK_H

typedef struct stack_struct {
  int size;
  int capacity;

  int* stk;

} stack;

stack* create_stack();

int peek_stack(stack* stk);
void push_stack(stack* stk);
int pop_stack(stack* stk);

#endif