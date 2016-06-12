#include "jvector.h"
#include <iostream>

namespace jw {

JVector::JVector(int capacity) : size_(0) {
  std::cout << "In ctor..." << std::endl;

  if (capacity < 1) {
    std::cout << "Cannot make vector of that size" << std::endl;
    exit(EXIT_FAILURE);
  }

  int true_capacity = DetermineCapacity(capacity);

  capacity_ = true_capacity;
  data_ = new int[true_capacity];
}

std::ostream &operator<<(std::ostream &strm, const JVector &v) {
  return strm << "size: " << v.GetSize() << "\n"
              << "capacity: " << v.GetCapacity() << "\n";
}

JVector::~JVector() { delete[] data_; }

int JVector::DetermineCapacity(int capacity) const {
  int true_capacity = kMinCapacity;

  while (capacity > true_capacity / 2) {
    true_capacity *= 2;
  }

  return true_capacity;
}

int JVector::GetSize() const { return size_; }

int JVector::GetCapacity() const { return capacity_; }

}  // namespace jw
