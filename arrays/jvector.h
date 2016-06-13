#ifndef PRACTICE_CPP_JARRAY_H
#define PRACTICE_CPP_JARRAY_H

namespace jw {

static const int kMinCapacity = 16;
static const int kGrowthFactor = 2;
static const int kShrinkFactor = 4;

class JVector {
 public:
  JVector(int capacity);
  JVector(const JVector &other) = default;
  // JVector &operator=(const JVector &other) = default;
  ~JVector();
  // Returns the number of items stored in the vector.
  int GetSize() const;
  bool IsEmpty() const;
  // Returns the capacity of the vector.
  int GetCapacity() const;
  // Prints out public information about the vector.
  void DebugString() const;
  // Appends the given value to the end of the vector.
  void Push(int value);
  // Returns the value stored at the given index
  int GetValueAt(int index) const;
  // Returns the last item in the vector, and removes it.
  int Pop();
  // Inserts the given value at the given index, shifting
  // current and trailing items to the right.
  void Insert(int index, int value);
  // Prepends the given value to the vector, shifting trailing
  // items to the right.
  void Prepend(int value);
  // Deletes item at index, shifting all trailing elements left.
  void Delete(int index);
  // Removes all instances of value from the vector.
  void Remove(int value);
  // Looks for value and returns first index with that value, -1 if not found.
  int Find(int value) const;

 private:
  // The actual capacity that can be accommodated before a resize is required
  int capacity_{kMinCapacity};
  // The number of items currently stored
  int size_{0};
  // The storage array where ints are stored
  std::unique_ptr<int[]> data_;
  // Determines the array size (in terms of power of growth factor)
  // required to accommodate the given capacity
  int DetermineCapacity(int capacity) const;
  // Checks to see if resizing is required for the given capacity
  // and grows or shrinks the vector as needed.
  void ResizeForSize(int candidate_size);
  // Increases the capacity of the vector.
  void IncreaseSize();
  // Decreases the capacity of the vector.
  void DecreaseSize();
};

}  // namespace jw

#endif  // PRACTICE_CPP_JARRAY_H
