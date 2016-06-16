#include "list_element.h"
#include <stdlib.h>
#include <iostream>

#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H

namespace jw {

template <class T>
class LinkedList {
 public:
  explicit LinkedList() : head_(nullptr) {}
  ~LinkedList();
  LinkedList(const LinkedList &) = delete;
  LinkedList &operator=(const LinkedList &) = delete;
  // Returns the number of data elements in list.
  int Size() const;
  // Adds an item to the front of the list
  void PushFront(T value);
  // Returns true if list is empty
  bool Empty() const;
  // Returns the value of the nth item, indexed starting at 0
  const T &ValueAt(int index) const;
  // Prints the data stored in the list
  void PrintDebug() const;
  // Remove front item, returning its value
  const T PopFront();
  // Pushes the item on the end of the list
  void PushBack(T value);
  // Removes end item and returns its value
  const T PopBack();
  // Returns value of front item.
  const T Front();
  // Returns the value of the end item.
  const T Back();
  // Insert value at index, so current item at that index is
  // pointed to by new item at index. Indexes start at 0.
  void Insert(int index, T value);
  // Erase node at the given index. Indexes start at 0.
  void Erase(int index);

 private:
  ListElement<T> *head_;
};

}  // namespace jw

#endif  // PROJECT_LINKEDLIST_H
