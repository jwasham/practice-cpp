#include <iostream>

#ifndef PROJECT_QUEUE_ARRAY_H
#define PROJECT_QUEUE_ARRAY_H

namespace jw {

template <class T>
class Queue {
  static const int kQueueCapacity = 5;
  static const int kQueuePositions = kQueueCapacity + 1;

 public:
  explicit Queue() : insert_(0), pop_(0) {}
  ~Queue() = default;
  Queue(const Queue &) = delete;
  Queue &operator=(const Queue &) = delete;
  // Adds value to queue.
  void Enqueue(T value);
  // Removes least recently added item from queue, returning its value.
  const T Dequeue();
  // Returns true if queue is empty.
  bool Empty() const;
  // Returns true if queue cannot accept another enqueue.
  bool Full() const;

 private:
  int insert_;
  int pop_;
  T data_[kQueuePositions];
};

}  // namespace jw

#endif  // PROJECT_QUEUE_ARRAY_H
