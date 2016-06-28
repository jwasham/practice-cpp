#include <queue>

#ifndef PROJECT_BINARY_SEARCH_TREE_H
#define PROJECT_BINARY_SEARCH_TREE_H

namespace jw {

struct BSTNode {
  int data;
  BSTNode* left;
  BSTNode* right;
};

// Returns a new node for our BST
BSTNode* GetNewNode(int value);
// Returns true if given value is in our tree
bool Search(BSTNode* node, int value);
// Frees memory allocated for the tree.
void DeleteTree(BSTNode* node);
// Returns the minimum value stored in the tree,
// or -1 if tree is empty
int GetMin(BSTNode* node);
// Returns the maximum value stored in the tree,
// or -1 if tree is empty
int GetMax(BSTNode* node);
// Returns height of the tree, 0 if empty
int GetHeight(BSTNode* node);
// Print out the items in the tree in level order
void PrintBFS(BSTNode* node);
// Print out the items in the tree in order (inorder)
void PrintInOrder(BSTNode* node);

}  // namespace jw

#endif  // PROJECT_BINARY_SEARCH_TREE_H
