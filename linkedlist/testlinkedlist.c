#include <stdio.h>

#include "linkedlist.h"

int main(void) {
  printf("\n\n###### Testing linkedlist ######\n\n");

  char yes[] = "Yes.";
  char no[] = "No.";

  linkedlist* mylist = create_linkedlist();

  dump_linkedlist(mylist);

  printf("\nAdding to linkedlist ... \n");

  for(int i = 0; i <= 20; i += 3) {

    printf("\tAdding %d.\n", i);
    add_linkedlist(mylist, i);
  }

  dump_linkedlist(mylist);

  printf("\nSearching linkedlist ... \n");

  int contains = 0;
  char* choice;

  for(int i = 0; i <= 20; i += 5) {
    contains = search_linkedlist(mylist, i);
    choice = (contains == 0) ? (yes) : (no);

    printf("\tContains %d? - %s\n", i, choice);
  }

  printf("\nDeleting from linkedlist ... \n");

  int deleted = 0;

  for(int i = 0; i <= 20; i += 5) {
    deleted = delete_linkedlist(mylist, i);
    choice = (deleted == 0) ? (yes) : (no);

    printf("\tDeleted %d? - %s\n", i, choice);
  }

  dump_linkedlist(mylist);

  printf("\nClearing linkedlist ... \n");

  clear_linkedlist(mylist);

  dump_linkedlist(mylist);

  return 0;
}