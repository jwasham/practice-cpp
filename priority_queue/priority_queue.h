#include <iostream>
#include <limits>
#include <memory>

#ifndef PROJECT_PRIORITY_QUEUE_H
#define PROJECT_PRIORITY_QUEUE_H

namespace jw {

typedef struct PriorityQueueElement {
  int key_;
  std::string value_;
} PQElement;

class PriorityQueue {
 public:
  explicit PriorityQueue(const int size);
  ~PriorityQueue();
  PriorityQueue(const PriorityQueue &) = delete;
  PriorityQueue &operator=(const PriorityQueue &) = delete;
  // Adds the given key and value to the queue
  void Insert(const int key, const std::string value);
  // Outputs the contents of the queue
  void PrintDebug();
  // Returns the maximum key and value associated with it
  PQElement* GetMax();
  // Returns the number of items stored in the queue
  int GetSize();
  // Returns true if queue is empty
  bool IsEmpty();
  // Returns the maximum key and value associated with it, removing it from the queue
  //PQElement* ExtractMax();

 private:
  int size_ = 0;
  int capacity_;
  PQElement *elements_;
  // Propagates the element up the tree until the parent node's heap property is
  // satisfied
  void SiftUp(int index);
  // Swaps 2 queue elements with the given indices
  void Swap(const int index1, const int index2);
};

}  // namespace jw

#endif  // PROJECT_PRIORITY_QUEUE_H
