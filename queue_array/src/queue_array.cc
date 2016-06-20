#include "queue_array.h"

namespace jw {

template <class T>
void Queue<T>::Enqueue(T value) {
  if (Full()) {
    std::cerr << "Queue is full. Unable to enqueue." << std::endl;
    exit(EXIT_FAILURE);
  }

  data_[insert_] = value;
  insert_++;
}

template <class T>
const T Queue<T>::Dequeue() {
  if (Empty()) {
    std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
    exit(EXIT_FAILURE);
  }

  T value = data_[pop_];
  data_[pop_] = 0;
  pop_++;

  return value;
}

template <class T>
bool Queue<T>::Empty() const {
  return insert_ == pop_;
}

template <class T>
bool Queue<T>::Full() const {
  return pop_ == (insert_ + 1) % kQueuePositions;
}

}  // namespace jw