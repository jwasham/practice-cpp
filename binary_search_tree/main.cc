#include <stdlib.h>
#include <iostream>
#include "bst_simple.h"
#include "bst_simple.cc"

int main(int argc, char *argv[]) {
  using namespace jw;

  BSTNode * root = nullptr;

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
  std::cout << "Max: " << max << std::endl;
  std::cout << "Height: " << height << std::endl;

  std::cout << "Tree items (breadth-first): ";
  PrintBFS(root);
  std::cout << std::endl;

  std::cout << "Tree items (in order): ";
  PrintInOrder(root);
  std::cout << std::endl;

//  std::string searchRaw;
//  int search = 0;

//  while (true) {
//    std::cout << "What number are you looking for? (q to quit) ";
//    std::getline(std::cin, searchRaw);
//
//    if (searchRaw == "q") {
//      break;
//    }
//
//    search = std::stoi(searchRaw);
//
//    std::cout << "Found " << search << ": " << Search(root, search) << std::endl;
//  }

  DeleteTree(root);

  return EXIT_SUCCESS;
}
