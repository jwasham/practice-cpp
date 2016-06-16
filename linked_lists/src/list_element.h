#include <memory>

#ifndef PROJECT_LISTELEMENT_H
#define PROJECT_LISTELEMENT_H

namespace jw {

template <class T>
class ListElement {
 public:
  ListElement(const T &value) : next_(nullptr), data_(value) {}
  ~ListElement() {}
  ListElement(const ListElement &) = delete;
  ListElement &operator=(const ListElement &) = default;

  const T &GetData() const { return data_; }
  ListElement<T> *GetNext() const { return next_; }
  void SetData(const T &data) { data_ = data; }
  void SetNext(ListElement<T> *elem) { next_ = elem; }

 private:
  ListElement<T> *next_;
  T data_;
};

}  // namespace jw

#endif  // PROJECT_LISTELEMENT_H
