#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include "bst_simple.cc"
#include "bst_simple.h"

int main(int argc, char* argv[]) {
  using namespace jw;

  BSTNode* root = nullptr;

  root = Insert(root, 15);
  root = Insert(root, 10);
  root = Insert(root, 12);
  root = Insert(root, 8);
  root = Insert(root, 9);
  root = Insert(root, 5);
  root = Insert(root, 7);
  root = Insert(root, 23);
  root = Insert(root, 16);
  root = Insert(root, 44);
  root = Insert(root, 2);
  root = Insert(root, 32);

  int min = GetMin(root);
  int max = GetMax(root);
  int height = GetHeight(root);

  std::cout << "Min: " << min << std::endl;
  assert(min == 2);
  std::cout << "Max: " << max << std::endl;
  assert(max == 44);
  std::cout << "Height: " << height << std::endl;
  assert(height == 5);

  std::cout << "Tree items (breadth-first): ";
  PrintBFS(root);
  std::cout << std::endl;

  std::cout << "Tree items (in order): ";
  PrintInOrder(root);
  std::cout << std::endl;

  std::cout << "Is a binary search tree: " << IsBinarySearchTree(root)
            << std::endl;
  assert(IsBinarySearchTree(root));

  BSTNode* suc1 = GetSuccessor(root, 5);
  std::cout << "Successor to 5 (2 children), should be 7: " << suc1->data
            << std::endl;
  assert(suc1->data == 7);

  BSTNode* suc1a = GetSuccessor(root, 7);
  std::cout << "Successor to 7 (0 children), should be 8: " << suc1a->data
            << std::endl;
  assert(suc1a->data == 8);

  BSTNode* suc2 = GetSuccessor(root, 12);
  std::cout << "Successor to 12 (0 children), should be 15: " << suc2->data
            << std::endl;
  assert(suc2->data == 15);

  BSTNode* suc3 = GetSuccessor(root, 15);
  std::cout << "Successor to 15 (2 children), should be 16: " << suc3->data
            << std::endl;
  assert(suc3->data == 16);

  // bad tree
  BSTNode* otherroot = GetNewNode(25);
  BSTNode* node1 = GetNewNode(12);
  BSTNode* node2 = GetNewNode(15);
  BSTNode* node3 = GetNewNode(85);
  otherroot->left = node1;
  otherroot->right = node2;
  otherroot->left->right = node3;

  std::cout << "Is a binary search tree: " << IsBinarySearchTree(otherroot)
            << std::endl;
  assert(!IsBinarySearchTree(otherroot));

  std::cout << "Removing 2 (no children)" << std::endl;
  root = DeleteValue(root, 2);
  std::cout << "Tree items (in order): ";
  PrintInOrder(root);
  std::cout << std::endl;

  std::cout << "Removing 5 (one child)" << std::endl;
  root = DeleteValue(root, 5);
  std::cout << "Tree items (in order): ";
  PrintInOrder(root);
  std::cout << std::endl;

  std::cout << "Removing 10 (2 children)" << std::endl;
  root = DeleteValue(root, 10);
  std::cout << "Tree items (in order): ";
  PrintInOrder(root);
  std::cout << std::endl;

  DeleteTree(root);
  DeleteTree(otherroot);

  return EXIT_SUCCESS;
}
