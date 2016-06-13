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
  data_ = std::unique_ptr<int[]>(new int[true_capacity]);
}

JVector::~JVector() {}

int JVector::DetermineCapacity(int capacity) const {
  int true_capacity = kMinCapacity;

  while (capacity > true_capacity / kGrowthFactor) {
    true_capacity *= kGrowthFactor;
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
    printf("%d: %d", i, data_[i]);
    std::cout << std::endl;
  }
}

void JVector::Push(int value) {
  ResizeForSize(size_ + 1);

  data_[size_] = value;
  ++size_;
}

void JVector::ResizeForSize(int candidate_size) {
  if (size_ < candidate_size) {  // grow
    if (size_ == capacity_) {
      IncreaseSize();
    }
  } else if (size_ > candidate_size) {  // shrink
    if (size_ < capacity_ / kShrinkFactor) {
      DecreaseSize();
    }
  }  // nothing needs to happen otherwise
}

void JVector::IncreaseSize() {
  int old_capacity = capacity_;
  int new_capacity = DetermineCapacity(old_capacity);

  if (old_capacity != new_capacity) {
    std::unique_ptr<int[]> new_data(new int[new_capacity]);

    for (int i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }

    data_ = std::move(new_data);
    capacity_ = new_capacity;
  }
}

void JVector::DecreaseSize() {
  int old_capacity = capacity_;
  int new_capacity = old_capacity / 2;

  if (new_capacity < kMinCapacity) {
    new_capacity = kMinCapacity;
  }

  if (new_capacity != old_capacity) {
    std::unique_ptr<int[]> new_data(new int[new_capacity]);

    for (int i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }

    data_ = std::move(new_data);
    capacity_ = new_capacity;
  }
}

int JVector::GetValueAt(int index) const {
  if (index < 0 or index >= size_) {
    std::cout << "Index out of bounds." << std::endl;
    exit(EXIT_FAILURE);
  }

  return data_[index];
}

int JVector::Pop() {
  if (size_ == 0) {
    std::cout << "Nothing to pop." << std::endl;
    exit(EXIT_FAILURE);
  }

  ResizeForSize(size_ - 1);

  int value = data_[size_ - 1];

  --size_;

  return value;
}

void JVector::Insert(int index, int value) {
  if (index < 0 or index >= size_) {
    std::cout << "Index out of bounds." << std::endl;
    exit(EXIT_FAILURE);
  }

  ResizeForSize(size_ + 1);

  // shift items to the right
  for (int i = size_; i > index; --i) {
    data_[i] = data_[i - 1];
  }

  // insert item
  data_[index] = value;

  ++size_;
}

void JVector::Prepend(int value) { Insert(0, 42); }

void JVector::Delete(int index) {
  if (index < 0 or index >= size_) {
    std::cout << "Index out of bounds." << std::endl;
    exit(EXIT_FAILURE);
  }

  ResizeForSize(size_ - 1);

  for (int i = index; i < size_ - 1; i++) {
    data_[i] = data_[i + 1];
  }

  --size_;
}

void JVector::Remove(int value) {
  for (int i = 0; i < size_; ++i) {
    if (data_[i] == value) {
      Delete(i);
      --i;  // since items will shift, recheck this index
    }
  }
}

int JVector::Find(int value) const {
  int found_index = -1;

  for (int i = 0; i < size_; ++i) {
    if (data_[i] == value) {
      found_index = i;
      break;
    }
  }

  return found_index;
}

}  // namespace jw
