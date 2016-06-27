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
  root = Insert(root, 5);
  root = Insert(root, 32);

  std::string searchRaw;
  int search = 0;

  while (true) {
    std::cout << "What number are you looking for? (q to quit) ";
    std::getline(std::cin, searchRaw);

    if (searchRaw == "q") {
      break;
    }

    search = std::stoi(searchRaw);

    std::cout << "Found " << search << ": " << Search(root, search) << std::endl;
  }

  return EXIT_SUCCESS;
}
