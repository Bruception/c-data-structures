
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

node* create_node(int value, node* next) {
  // Allocate space on the heap for node
  node* newnode = (node*)malloc(sizeof(node));

  newnode->value = value;
  newnode->next = next;

  return newnode;
}

linkedlist* create_linkedlist() {
  // Allocate space on the heap for linkedlist struct
  linkedlist* newlist = (linkedlist*)malloc(sizeof(linkedlist));
  newlist->size = 0;

  node* head = create_node(-1, NULL);

  newlist->head = head;

  return newlist;
}

void add_linkedlist(linkedlist* list, int value) {
  node* oldhead = list->head->next;

  node* newhead = create_node(value, oldhead);
  list->head->next = newhead;

  ++list->size;
}

// Returns -1 when search value is not in the list, returns 0 otherwise.
int search_linkedlist(linkedlist* list, int value) {
  node* current = list->head->next;

  while(current != NULL) {
    if(current->value == value) return 0;

    current = current->next;
  }

  return -1;
}

// Returns -1 when no deletion occurs, returns 0 otherwise.
int delete_linkedlist(linkedlist* list, int value) {
  node* previous = list->head;
  node* current = list->head->next;

  while(current != NULL) {
    if(current->value == value) {

      previous->next = current->next;
      free(current);

      --list->size;

      return 0;
    }

    previous = current;
    current = current->next;
  }

  return -1;
}

void clear_linkedlist(linkedlist* list) {
  node* current = list->head->next;
  node* garbage = NULL;

  while(current != NULL) {
    garbage = current;
    current = current->next;

    free(garbage);
  }

  list->head->next = NULL;
  list->size = 0;
}

void dump_linkedlist(linkedlist* list) {
  printf("LinkedList@%p - Size: %d :\n", list, list->size);

  printf("(x) -> ");

  node* current = list->head->next;

  while(current != NULL) {
    printf("(%d) -> ", current->value);
    current = current->next;
  }

  printf("x\n");
}
