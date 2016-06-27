#include "bst_simple.h"

namespace jw {

BSTNode* GetNewNode(int value) {
  BSTNode* node = new BSTNode;
  node->data = value;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

BSTNode* Insert(BSTNode* node, int value) {
  if (node == nullptr) {
    node = GetNewNode(value);
    return node;
  }

  if (value < node->data) {
    node->left = Insert(node->left, value);
  } else if (value > node->data) {
    node->right = Insert(node->right, value);
  }

  return node;
}

bool Search(BSTNode* node, int value) {
  if (node == nullptr) {
    return false;
  }

  if (value < node->data) {
    return Search(node->left, value);
  } else if (value > node->data) {
    return Search(node->right, value);
  } else {
    return true;
  }
}

int GetMin(BSTNode* node) {
  if (node == nullptr) {
    return -1;
  }

  if (node->left == nullptr) {
    return node->data;
  }

  return GetMin(node->left);
}

int GetMax(BSTNode* node) {
  if (node == nullptr) {
    return -1;
  }

  if (node->right == nullptr) {
    return node->data;
  }

  return GetMax(node->right);
}

void DeleteTree(BSTNode* node) {

  if (node == nullptr) {
    return;
  }

  DeleteTree(node->left);
  DeleteTree(node->right);

  delete node;
}

}  // namespace jw