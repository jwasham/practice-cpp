#include "priority_queue.h"

namespace jw {

PriorityQueue::PriorityQueue(const int size) : capacity_(size) {
  assert(size > 0 && size < INT_MAX);

  elements_ = new PQElement[size];
}

PriorityQueue::~PriorityQueue() { delete[] elements_; }

void PriorityQueue::Insert(const int key, const std::string value) {
  assert(size_ < capacity_);

  elements_[size_].key_ = key;
  elements_[size_].value_ = value;

  ++size_;

  SiftUp(size_ - 1);
}

void PriorityQueue::SiftUp(int index) {
  while (index > 0) {
    int parent = (index - 1) / 2;

    if (elements_[parent].key_ < elements_[index].key_) {
      Swap(parent, index);
    } else {
      break;
    }

    index = parent;
  }
}

void PriorityQueue::Swap(const int index1, const int index2) {
  int temp_key = elements_[index1].key_;
  std::string temp_value = elements_[index1].value_;

  elements_[index1].key_ = elements_[index2].key_;
  elements_[index1].value_ = elements_[index2].value_;
  elements_[index2].key_ = temp_key;
  elements_[index2].value_ = temp_value;
}

void PriorityQueue::PrintDebug() {
  for (int i = 0; i < size_; ++i) {
    std::cout << i << ":" << elements_[i].key_ << ":" << elements_[i].value_
              << std::endl;
  }
}

PQElement* PriorityQueue::GetMax() {
  assert(size_ > 0);

  return &(elements_[0]);
}

int PriorityQueue::GetSize() { return size_; }

bool PriorityQueue::IsEmpty() { return size_ == 0; }

}  // namespace jw