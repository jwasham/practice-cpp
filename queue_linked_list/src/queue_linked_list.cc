#include "queue_linked_list.h"

namespace jw {

template <class T>
Queue<T>::~Queue() {
  ListElement<T> *current = head_;
  ListElement<T> *temp = head_;

  while (current) {
    temp = current;
    current = current->GetNext();
    delete temp;
  }
}

template <class T>
void Queue<T>::Enqueue(T value) {
  auto p = new ListElement<T>(value);
  p->SetData(value);
  p->SetNext(nullptr);

  if (Empty()) {
    head_ = tail_ = p;
  } else {
    tail_->SetNext(p);
    tail_ = p;
  }
}

template <class T>
const T Queue<T>::Dequeue() {
  if (Empty()) {
    std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
    exit(EXIT_FAILURE);
  }

  T value = head_->GetData();

  ListElement<T> *temp = head_;

  if (head_ == tail_) {
    tail_ = head_->GetNext();
  }

  head_ = head_->GetNext();
  delete temp;

  return value;
}

template <class T>
bool Queue<T>::Empty() const {
  return head_ == nullptr;
}

template <class T>
void Queue<T>::PrintDebug() const {
  ListElement<T> *current = head_;

  std::cout << "Queue elements: ";

  while (current) {
    std::cout << current->GetData() << " < ";
    current = current->GetNext();
  }

  std::cout << std::endl;
}

}  // namespace jw