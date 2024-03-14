#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ITEM;

typedef enum { RIGHT, LEFT, PARENT, ROOT } DIRECTION;

typedef struct KEY {
  ITEM item;
} KEY;

typedef struct AVL_TREE {
  struct KEY item;
  struct AVL_TREE *left;
  struct AVL_TREE *right;
  struct AVL_TREE *parent;
  int height;
} AVL_TREE;

void initilize(AVL_TREE *tree);

bool empty(AVL_TREE **tree);

int height(AVL_TREE **tree);

int compare(KEY x, KEY y);

bool equals(KEY x, KEY y);

void createNode(KEY item, AVL_TREE **tree);

bool isNode(DIRECTION dir, AVL_TREE *tree);

void shift(DIRECTION dir, AVL_TREE **tree);

AVL_TREE *addChild(KEY item, AVL_TREE *tree, DIRECTION dir);

void diposeTree(AVL_TREE *tree);

bool findNode(KEY item, AVL_TREE **p, AVL_TREE *tree);

bool findKey(KEY item, AVL_TREE *tree);

// Specific Functions for AVL TREES

bool isLeftChild(AVL_TREE *tree);

bool isRightChild(AVL_TREE *tree);

int childHeight(AVL_TREE *tree);

int balancing(AVL_TREE *tree);

int balance(AVL_TREE *tree);

AVL_TREE *insertChildBalanced(KEY item, AVL_TREE *tree);

bool removeChildBalanced(KEY item, AVL_TREE *tree);