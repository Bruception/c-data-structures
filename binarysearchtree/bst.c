
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

int min_helper(bst_node* root) {
  bst_node* current = root;

  while(current->left != NULL) {
    current = current->left;
  }

  return current->value;
}

bst_node* delete_helper(bst* bt, bst_node* current, int value) {
  if(current == NULL) return current;

  if(value < current->value) {
    current->left = delete_helper(bt, current->left, value);
  } else if(value > current->value) {
    current->right = delete_helper(bt, current->right, value);
  } else {
    if(current->left != NULL && current->right != NULL) {
      int min_right = min_helper(current->right);

      current->value = min_right;
      current->right = delete_helper(bt, current->right, min_right);
    } else {
      bst_node* new_child = (current->left == NULL) ?
      (current->right) : (current->left);

      free(current);
      --bt->size;

      return new_child;
    }
  }

  return current;
}

int delete_bst(bst* bt, int value) {
  if(bt->size == 0) return -1;

  int oldSize = bt->size;
  bt->head = delete_helper(bt, bt->head, value);

  return (oldSize > bt->size) ? (0) : (-1);
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

  return min_helper(bt->head);
}

void clear_helper(bst_node* root) {
  if(root->left != NULL) {
    clear_helper(root->left);
  }
  if(root->right != NULL) {
    clear_helper(root->right);
  }

  free(root);
}

void clear_bst(bst* bt) {
  if(bt->size == 0) return;

  clear_helper(bt->head);
  bt->head = NULL;

  bt->size = 0;
}

void inorder_bst(bst_node* node) {
  if(node == NULL) return;

  inorder_bst(node->left);
  printf("%d ", node->value);
  inorder_bst(node->right);
}

// Dump using in-order
void dump_bst(bst* bt) {
  printf("BinarySearchTree@%p - Size: %d :\n", bt, bt->size);

  inorder_bst(bt->head);

  printf("\n");
}