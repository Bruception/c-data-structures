#include <stdio.h>

#include "stack.h"

int main(void) {
  printf("\n\n###### Testing stack ######\n\n");

  char yes[] = "Yes.";
  char no[] = "No.";

  stack* mystack = create_stack(20);

  dump_stack(mystack);

  printf("\nPushing to stack ... \n");

  for(int i = 0; i <= 20; i += 3) {

    printf("\tPushing %d.\n", i);
    push_stack(mystack, i);
  }

  dump_stack(mystack);

  printf("Top of stack? - %d\n", peek_stack(mystack));
  printf("Stack size? - %d\n", size_stack(mystack));

  printf("\nPopping from stack ... \n");

  int popped = 0;

  for(int i = 0; i <= 20; i += 5) {
    popped = pop_stack(mystack);

    printf("\tPopping %d\n", popped);
  }

  dump_stack(mystack);

  printf("Top of stack? - %d\n", peek_stack(mystack));
  printf("Stack size? - %d\n", size_stack(mystack));

  printf("\nClearing stack ... \n");

  clear_stack(mystack);

  dump_stack(mystack);

  return 0;
}