#include <assert.h>
#include <iostream>
#include <vector>
#include "jvector.h"
#include "jvector.cc"
#include "jvector_test.h"
#include "jvector_test.cc"

void StandardExperiment();

int main(int argc, char *argv[]) {

  jw::JVectorTest tester;
  tester.RunTests();

//  int initial_capacity = 1;
//
//  std::cout << "Enter how many items you want to store: " << std::endl;
//  std::cin >> initial_capacity;
//
//  jw::JVector test_v(initial_capacity);
//
//  assert(test_v.IsEmpty());
//
//  for (int i = 0; i < 77; ++i) {
//    test_v.Push(i + 1);
//  }

//  test_v.DebugString();

//  StandardExperiment();

  return EXIT_SUCCESS;
}

void StandardExperiment() {

  std::cout << "Now messing with std implementation." << std::endl;

  std::vector<int> myv{12, 23, 5, 3};

  std::cout << "Size: " << myv.size() << std::endl;
  std::cout << "Capacity: " << myv.capacity() << std::endl;

  std::cout << "Adding a few items" << std::endl;

  myv.push_back(4);
  myv.push_back(12);
  myv.push_back(45);

  std::cout << "Size: " << myv.size() << std::endl;
  std::cout << "Capacity: " << myv.capacity() << std::endl;
  std::cout << "Popping 1" << std::endl;

  myv.pop_back();

  std::cout << "Size: " << myv.size() << std::endl;
  std::cout << "Capacity: " << myv.capacity() << std::endl;

  std::cout << "Items:" << std::endl;
  for (int value : myv) {
    std::cout << value << std::endl;
  }

  std::cout << "Inserting at index 4" << std::endl;
  myv.insert(myv.begin() + 4, 99);

  std::cout << "Items:" << std::endl;
  for (int value : myv) {
    std::cout << value << std::endl;
  }

  //myv.reserve(120);

  for (int i = 0; i < 75; i++) {
    myv.push_back(i + 3);
  }

  std::cout << "Size: " << myv.size() << std::endl;
  std::cout << "Capacity: " << myv.capacity() << std::endl;

  std::cout << "Collapsing" << std::endl;
  myv.shrink_to_fit();
  std::cout << "Capacity: " << myv.capacity() << std::endl;

  std::cout << "Items:" << std::endl;
  for (unsigned long j = 0; j < myv.size(); ++j) {
    std::cout << j << ": " << myv.at(j) << std::endl;
  }

  std::cout << "Erasing items from indices from 4 to 11" << std::endl;
  myv.erase(myv.begin() + 4, myv.begin() + 12);

  std::cout << "Items:" << std::endl;
  for (unsigned long k = 0; k < myv.size(); ++k) {
    std::cout << k << ": " << myv.at(k) << std::endl;
  }
}
