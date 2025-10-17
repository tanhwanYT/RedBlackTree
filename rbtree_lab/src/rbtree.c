#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  p->root->color=RBTREE_BLACK;
  p->root->left=p->nil;
  p->root->right=p->nil;  
  return p->root;
}

void delete_rbtree(rbtree *t) {
  if(t != t->nil)
  {
    delete_rbtree(&(t->root->left));
    delete_rbtree(&(t->root->right));
    free(t);
    t=t->nil;
  }
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  node_t *newnode = (node_t *)calloc(1,sizeof(node_t));
  newnode->key = key;
  newnode->left=t->nil;
  newnode->right=t->nil;
  newnode->color=RBTREE_RED;  
  return newnode;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
