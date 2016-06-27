#ifndef PROJECT_BINARY_SEARCH_TREE_H
#define PROJECT_BINARY_SEARCH_TREE_H

namespace jw {

struct BSTNode {
  int data;
  BSTNode* left;
  BSTNode* right;
};

BSTNode* GetNewNode(int value);
bool Search(BSTNode* node, int value);

}  // namespace jw

#endif  // PROJECT_BINARY_SEARCH_TREE_H
