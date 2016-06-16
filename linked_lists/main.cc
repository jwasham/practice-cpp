#include <cstdlib>
#include <iostream>
#include <string>

#include "src/linked_list.h"
#include "src/linked_list.cc"

int main(int argc, char *argv[]) {

  jw::LinkedList<int> ilist{};
  ilist.PushFront(4);
  ilist.PushFront(9);

  std::cout << "Size of int list is: " << ilist.Size() << std::endl;

  jw::LinkedList<std::string> strlist{};
  strlist.PushFront("string 1");
  strlist.PushFront("another");
  strlist.PushFront("and another");
  std::cout << "Size of string list is: " << strlist.Size() << std::endl;

  std::cout << "Hello friends - look in tests directory." << std::endl;

  return EXIT_SUCCESS;
}