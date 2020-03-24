
#ifndef STACK_H
#define STACK_H

typedef struct stack_struct {
  int* data;
  int top;

  int capacity;

} stack;

stack* create_stack();

int peek_stack(stack* stk);
void push_stack(stack* stk, int value);
int pop_stack(stack* stk);
void clear_stack(stack* stk);
int size_stack(stack* stk);
void dump_stack(stack* stk);

#endif