#ifndef PRACTICE_CPP_JARRAY_H
#define PRACTICE_CPP_JARRAY_H

namespace jw {

static const int kMinCapacity = 16;

class JVector {
 public:
  JVector(int capacity);
  JVector(const JVector &other) = default;
  JVector &operator=(const JVector &other) = default;
  ~JVector();
  int GetSize() const;
  bool IsEmpty() const;
  int GetCapacity() const;
  void DebugString() const;
  void Push(int value);

 private:
  int capacity_{kMinCapacity};
  int size_{0};
  int *data_;
  int DetermineCapacity(int capacity) const;
  void ResizeForSize(int candidate_size);
  void IncreaseSize();
};

}  // namespace jw

#endif  // PRACTICE_CPP_JARRAY_H
