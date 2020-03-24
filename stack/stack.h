
#ifndef STACK_H
#define STACK_H

typedef struct stack_struct {
  int size;
  int capacity;

  int* data;
  int* top;

} stack;

stack* create_stack();

int peek_stack(stack* stk);
void push_stack(stack* stk);
int pop_stack(stack* stk);
void dump_stack(stack* stk);

#endif