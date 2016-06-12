#ifndef PRACTICE_CPP_JARRAY_H
#define PRACTICE_CPP_JARRAY_H

namespace jw {

const int kMinCapacity = 16;

class JVector {
 public:
  JVector(int capacity);
  JVector(const JVector &other) = default;
  JVector &operator=(const JVector &other) = default;
  friend std::ostream &operator<<(std::ostream &, const JVector &);
  ~JVector();
  int GetSize() const;
  int GetCapacity() const;

 private:
  int capacity_{kMinCapacity};
  int size_{0};
  int *data_;
  int DetermineCapacity(int capacity) const;
};

}  // namespace jw

#endif  // PRACTICE_CPP_JARRAY_H
