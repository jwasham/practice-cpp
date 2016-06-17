#include <cstdlib>
#include <iostream>

#include "src/linked_list.h"
#include "src/linked_list.cc"

// for stdlib experiments:
#include <forward_list>
#include <list>

void stdlib_forward_list_experiment();
void stdlib_doubly_linked_list_experiment();

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

  stdlib_forward_list_experiment();
  stdlib_doubly_linked_list_experiment();

  return EXIT_SUCCESS;
}

void stdlib_forward_list_experiment() {

  std::cout << "----------------------------" << std::endl;
  std::cout << "Now messing with standard library's forward list (singly-linked list)" << std::endl;

  std::forward_list<int> fl {100, 200, 300};

  std::cout << "Items:" << std::endl;
  for (int &item : fl) {
    std::cout << item << std::endl;
  }

  std::cout << "First item: " << fl.front() << std::endl;

  std::cout << "Getting items using iterator: ";
  for (auto it = fl.begin(); it != fl.end(); ++it) {
    std::cout << *it << " -> ";
  }
  std::cout << std::endl;

  std::cout << "Adding to front: " << std::endl;
  fl.push_front(5);
  for (auto it = fl.begin(); it != fl.end(); ++it) {
    std::cout << *it << " -> ";
  }
  std::cout << std::endl;

  std::cout << "Popping front 2x: " << std::endl;
  fl.pop_front();
  fl.pop_front();
  for (auto it = fl.begin(); it != fl.end(); ++it) {
    std::cout << *it << " -> ";
  }
  std::cout << std::endl;
}

void stdlib_doubly_linked_list_experiment() {

  std::cout << "----------------------------" << std::endl;
  std::cout << "Now messing with standard library's list (doubly-linked list)" << std::endl;

  std::list<int> dl {100, 200, 300};

  std::cout << "Items:" << std::endl;
  for (int &item : dl) {
    std::cout << item << std::endl;
  }

  std::cout << "First item: " << dl.front() << std::endl;

  std::cout << "Getting items using iterator: ";
  for (auto it = dl.begin(); it != dl.end(); ++it) {
    std::cout << *it << " -> ";
  }
  std::cout << std::endl;

  std::cout << "Adding to front and back: " << std::endl;
  dl.push_front(5);
  dl.push_back(400);
  for (auto it = dl.begin(); it != dl.end(); ++it) {
    std::cout << *it << " -> ";
  }
  std::cout << std::endl;

  std::cout << "Adding to back again: " << std::endl;
  dl.push_back(500);
  for (auto it = dl.begin(); it != dl.end(); ++it) {
    std::cout << *it << " -> ";
  }
  std::cout << std::endl;

  std::cout << "Popping front 2x: " << std::endl;
  dl.pop_front();
  dl.pop_front();
  for (auto it = dl.begin(); it != dl.end(); ++it) {
    std::cout << *it << " -> ";
  }
  std::cout << std::endl;

  std::cout << "Popping back 2x: " << std::endl;
  dl.pop_back();
  dl.pop_back();
  for (auto it = dl.begin(); it != dl.end(); ++it) {
    std::cout << *it << " -> ";
  }
  std::cout << std::endl;

  std::cout << "----------------------------" << std::endl;
  std::cout << "Now messing with standard library's list (doubly-linked list)" << std::endl;
}