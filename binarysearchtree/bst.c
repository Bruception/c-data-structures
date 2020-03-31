
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

bst_node* create_bst_node(int value) {
  bst_node* new_bst_node = (bst_node*)malloc(sizeof(bst_node));
  new_bst_node->left = NULL;
  new_bst_node->right = NULL;
  new_bst_node->value = value;

  return new_bst_node;
}

bst* create_bst() {
  bst* bt = (bst*)malloc(sizeof(bst));

  bt->head = NULL;
  bt->size = 0;

  return bt;
}

void add_bst(bst* bt, int value) {
  bst_node* new_bst_node = create_bst_node(value);
  ++bt->size;

  if(bt->head == NULL) {
    bt->head = new_bst_node;
    return;
  }

  bst_node* parent = NULL;
  bst_node* current = bt->head;

  while(current != NULL) {
    parent = current;

    if(value <= current->value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  bst_node** dest_ptr = (value <= parent->value) ?
  (&(parent->left)) : (&(parent->right));

  *dest_ptr = new_bst_node;
}

int search_bst(bst* bt, int value) {
  bst_node* current = bt->head;

  while(current != NULL) {
    if(value < current->value)
      current = current->left;
    else if(value > current->value)
      current = current->right;
    else
      return 0;
  }

  return -1;
}

bst_node* min_node_bst(bst_node* root) {
  bst_node* current = root;

  while(current->left != NULL) {
    current = current->left;
  }

  return current;
}

int max_bst(bst* bt) {
  if(bt->size == 0) exit(1);

  bst_node* current = bt->head;

  while(current->right != NULL) {
    current = current->right;
  }

  return current->value;
}

int min_bst(bst* bt) {
  if(bt->size == 0) exit(1);

  bst_node* min_node = min_node_bst(bt->head);

  return min_node->value;
}