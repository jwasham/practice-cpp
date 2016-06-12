#include <assert.h>
#include <iostream>
#include "jvector.h"
#include "jvector.cc"

int main(int argc, char *argv[]) {

  int initial_capacity = 1;

  std::cout << "Enter how many items you want to store: " << std::endl;
  std::cin >> initial_capacity;

  jw::JVector test_v(initial_capacity);

  assert(test_v.IsEmpty());

  for (int i = 0; i < 77; ++i) {
    test_v.Push(i + 1);
  }

  test_v.DebugString();

  return EXIT_SUCCESS;
}

/**

  * - size() - number of items
  * - capacity() - number of items it can hold
  * - is_empty()
  - at(index) - returns item at given index, blows up if index out of bounds
  * - push(item)
  - insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
  - prepend(item) - can use insert above at index 0
  - pop() - remove from end, return value
  - delete(index) - delete item at index, shifting all trailing elements left
  - remove(item) - looks for value and removes index holding it (even if in multiple places)
  - find(item) - looks for value and returns first index with that value, -1 if not found
  - resize(new_capacity) // private function

*/