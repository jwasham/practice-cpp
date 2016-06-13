#include <assert.h>
#include <iostream>
#include "jvector.h"
#include "jvector.cc"
#include "jvector_test.h"
#include "jvector_test.cc"

int main(int argc, char *argv[]) {

  jw::JVectorTest tester;
  tester.RunTests();

  int initial_capacity = 1;

  std::cout << "Enter how many items you want to store: " << std::endl;
  std::cin >> initial_capacity;

  jw::JVector test_v(initial_capacity);

  assert(test_v.IsEmpty());

  for (int i = 0; i < 77; ++i) {
    test_v.Push(i + 1);
  }

//  test_v.DebugString();

  return EXIT_SUCCESS;
}
