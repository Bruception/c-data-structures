
#ifndef BST_H
#define BST_H

typedef struct bst_node {
  struct bst_node* left;
  struct bst_node* right;

  int value;

} bst_node;


typedef struct bst {
  struct bst_node* head;
  int size;

} bst;


bst* create_bst();

void add_bst(bst* bt, int value);
int search_bst(bst* bt, int value);
int delete_bst(bst* bt, int value);
int max_bst(bst* bt);
int min_bst(bst* bt);
void clear_bst(bst* bt);
void dump_bst(bst* bt);

#endif