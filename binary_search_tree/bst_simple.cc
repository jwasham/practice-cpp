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

int GetHeight(BSTNode* node) {
  if (node == nullptr) {
    return 0;
  }

  return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
}

void DeleteTree(BSTNode* node) {
  if (node == nullptr) {
    return;
  }

  DeleteTree(node->left);
  DeleteTree(node->right);

  delete node;
}

void PrintBFS(BSTNode* node) {
  std::queue<BSTNode*> node_queue;

  BSTNode* current;

  node_queue.push(node);

  while (!node_queue.empty()) {
    current = node_queue.front();
    node_queue.pop();

    if (current != nullptr) {
      std::cout << current->data << " ";

      if (current->left) node_queue.push(current->left);
      if (current->right) node_queue.push(current->right);
    }
  }
}

void PrintInOrder(BSTNode* node) {
  if (node == nullptr) {
    return;
  }

  PrintInOrder(node->left);
  std::cout << node->data << " ";
  PrintInOrder(node->right);
}

}  // namespace jw