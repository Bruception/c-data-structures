
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

linkedlist* create_linkedlist() {
  // Allocate space on the heap for linkedlist struct
  linkedlist* newlist = (linkedlist*)malloc(sizeof(linkedlist));
  newlist->size = 0;

  // Allocate space on the heap for linkedlist head
  node* head = (node*)malloc(sizeof(node));

  head->next = NULL;
  head->value = -1;

  newlist->head = head;

  return newlist;
}

void dump_linkedlist(linkedlist* list) {
  printf("LinkedList@%p :\n", list);

  printf("(x) -> ");

  node* current = list->head;

  while(current->next != NULL) {
    printf("(%d) -> ", current->next->value);
    current = current->next;
  }

  printf("x\n");
}
