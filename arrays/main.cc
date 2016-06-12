#include <iostream>
#include "jvector.h"
#include "jvector.cc"

int main(int argc, char *argv[]) {
  std::cout << "good to go" << std::endl;

  jw::JVector test_v(17);

  std::cout << test_v << std::endl;

  return EXIT_SUCCESS;
}
