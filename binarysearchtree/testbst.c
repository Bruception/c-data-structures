#include <stdio.h>

#include "bst.h"

int main(void) {
  printf("\n\n###### Testing bst ######\n\n");

  char yes[] = "Yes.";
  char no[] = "No.";

  int nums[] = {50, 48, 70, 30, 65, 90, 20, 32, 67, 98, 15, 25, 31, 35, 66, 69, 94, 99};

  int i = 0;

  unsigned long length = sizeof(nums) / sizeof(int);

  bst* mybst = create_bst();

  dump_bst(mybst);

  printf("\nAdding to bst ... \n");

  for(; i < length; ++i) {
    add_bst(mybst, nums[i]);
  }

  dump_bst(mybst);

  printf("\nSearching bst ... \n");

  int contains = 0;
  char* choice;

  for(int i = 0; i <= 100; i += 5) {
    contains = search_bst(mybst, i);
    choice = (contains == 0) ? (yes) : (no);

    printf("\tContains %d? - %s\n", i, choice);
  }

  printf("Max in bst? - %d\n", max_bst(mybst));
  printf("Min in bst? - %d\n", min_bst(mybst));


  printf("\nDeleting bst ... \n");

  for(int i = 0; i <= 100; i += 5) {
    contains = delete_bst(mybst, i);
    choice = (contains == 0) ? (yes) : (no);

    printf("\tDeleted %d? - %s\n", i, choice);
  }

  dump_bst(mybst);

  printf("\nClearing bst ... \n");

  clear_bst(mybst);

  dump_bst(mybst);

  return 0;
}