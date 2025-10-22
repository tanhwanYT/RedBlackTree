#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *t = calloc(1,sizeof(rbtree));
  if(!t) return NULL;

  t->nil = calloc(1,sizeof(node_t));
  if(!t->nil){
    free(t);
    return NULL;
  } 

  t->root->color=RBTREE_BLACK;
  
  t->root->left=t->nil;
  t->root->right=t->nil;  
  t->root->parent=t->nil;  
  
  t->root = t->nil;
  return t;
}

void free_node(rbtree *tr, node_t *n) {
  if (n == tr->nil) return;

  free_node(tr, n->left);
  free_node(tr, n->right);
  free(n);
}

void delete_rbtree(rbtree *t) {
  if(!t) return NULL;

  if(t->root != t->nil)
  {
    free_node(t, t->root);
  }
  free(t->nil);
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  node_t *newnode = (node_t *)calloc(1,sizeof(node_t));
  node_t *curnode = t->root;

  newnode->key = key;
  newnode->left=t->nil;
  newnode->right=t->nil;
  newnode->color=RBTREE_RED;

  node_t *y = t->nil;
  node_t *x = t->root;
  while (x != t->nil) {
    y = x;
    if (newnode->key < x->key) x = x->left;
    else x = x->right;
  }

  newnode->parent = y;

  if (y == t->nil) t->root = newnode;
  else if (newnode->key < y->key) y->left = newnode;
  else y->right = newnode;

  // 여기에 트리를 순회하며 rb트리의 특징을 위반하는지 검사하는 코드가 필요
  insert_fixup(t, newnode);

  return newnode;
}

static void left_rotate(rbtree *t, node_t *x){
  node_t *y = x->right;

  x->right = y->left;
  if(y->left != t->nil) y->left->parent = x;
  y->parent = x->parent;

  if(x->parent == t->nil) t->root = y;
  else if(x==x->parent->left) x->parent->left = y;
  else x->parent->right = y;

  y->left = x;
  x->parent = y;
}

static void right_rotate(rbtree *t, node_t *y){
  node_t *x = y->left;

  y->left = x->right;
  if(x->right != t->nil) x->right->parent = y;
  x->parent = y->parent;

  if(y->parent == t->nil) t->root = x;
  else if(y==y->parent->right) y->parent->right = x;
  else y->parent->left = x;
  
  x->right = y;
  y->parent = x;
}

static void insert_fixup(rbtree *t, node_t *z) {
    while (z->parent->color == RBTREE_RED) {
      if (z->parent == z->parent->parent->left) 
      {
        node_t *y = z->parent->parent->right; /* uncle */
        if (y->color == RBTREE_RED) { //case 1
          z->parent->color = RBTREE_BLACK;
          y->color = RBTREE_BLACK;
          z->parent->parent->color = RBTREE_RED;
          z = z->parent->parent;
        } 
        else {
          if (z == z->parent->right) { // case2
            z = z->parent;
            left_rotate(t, z);
          }
          z->parent->color = RBTREE_BLACK; // case3
          z->parent->parent->color = RBTREE_RED;
          right_rotate(t, z->parent->parent);
        }
      } 
      else // z->parent == z->parent->parent->"right" 반대
      { 
        node_t *y = z->parent->parent->left; /* uncle */
        if (y->color == RBTREE_RED) {
          z->parent->color = RBTREE_BLACK;
          y->color = RBTREE_BLACK;
          z->parent->parent->color = RBTREE_RED;
          z = z->parent->parent;
        } 
        else {
          if (z == z->parent->left) {
            z = z->parent;
            right_rotate(t, z);
          }
          z->parent->color = RBTREE_BLACK;
          z->parent->parent->color = RBTREE_RED;
          left_rotate(t, z->parent->parent);
        }
      }
    }
    t->root->color = RBTREE_BLACK;
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
