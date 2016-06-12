#include "jvector.h"
#include <iostream>

namespace jw {

JVector::JVector(int capacity) : size_(0) {
  if (capacity < 1) {
    std::cout << "Cannot make vector of that size" << std::endl;
    exit(EXIT_FAILURE);
  }

  int true_capacity = DetermineCapacity(capacity);

  capacity_ = true_capacity;
  data_ = new int[true_capacity];
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
bool JVector::IsEmpty() const { return size_ == 0; }

int JVector::GetCapacity() const { return capacity_; }

void JVector::DebugString() const {
  std::cout << "size: " << size_ << std::endl
            << "capacity: " << capacity_ << std::endl
            << "items: " << std::endl;

  for (int i = 0; i < size_; ++i) {
    printf("%d: %d", i, *(data_ + i));
    std::cout << std::endl;
  }
}

void JVector::Push(int value) {
  ResizeForSize(size_ + 1);

  *(data_ + size_) = value;
  ++size_;
}

void JVector::ResizeForSize(int candidate_size) {
  if (size_ < candidate_size) {  // grow
    if (size_ == capacity_) {
      //      std::cout << "Increasing size..." << std::endl;
      IncreaseSize();
    }
  } else if (size_ > candidate_size) {  // shrink

  }  // nothing needs to happen otherwise
}

void JVector::IncreaseSize() {
  int old_capacity = capacity_;
  int new_capacity = DetermineCapacity(old_capacity);

  if (old_capacity != new_capacity) {
    //    std::cout << "reallocating for " << new_capacity << std::endl;

    int *new_data = new int[new_capacity];

    for (int i = 0; i < size_; ++i) {
      *(new_data + i) = *(data_ + i);
    }

    delete[] data_;

    data_ = new_data;
    capacity_ = new_capacity;
  }
}

}  // namespace jw
