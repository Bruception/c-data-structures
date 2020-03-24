
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

linkedlist* create_linkedlist() {
  linkedlist* newlist = (linkedlist*)malloc(sizeof(linkedlist));
  newlist->size = 0;

  node* head = (node*)malloc(sizeof(node));

  head->next = NULL;
  head->value = -1;

  newlist->head = head;

  return newlist;
}