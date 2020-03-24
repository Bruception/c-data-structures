
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node_struct {
  struct node_struct* next;
  int value;

} node;

typedef struct linkedlist_struct {
  node* head;
  int size;

} linkedlist;

linkedlist* create_linkedlist();

void add_linkedlist(linkedlist* list, int value);
int search_linkedlist(linkedlist* list, int value);
int delete_linkedlist(linkedlist* list, int value);
void dump_linkedlist(linkedlist* list);

#endif