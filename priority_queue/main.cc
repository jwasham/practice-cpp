#include <assert.h>
#include "priority_queue.cc"

int main(int argc, char* argv[]) {
  jw::PriorityQueue queue(10);

  assert(queue.IsEmpty());
  assert(queue.GetSize() == 0);

  queue.Insert(23, "hello");
  assert(!queue.IsEmpty());
  assert(queue.GetSize() == 1);

  queue.Insert(9827, "world");
  assert(queue.GetSize() == 2);

  queue.Insert(662, "C++");
  queue.Insert(551, "nice");
  queue.Insert(1221, "things");
  assert(queue.GetSize() == 5);

  jw::PQElement* max = queue.GetMax();
  assert(max->key_ == 9827);
  assert(max->value_ == "world");

  // queue.PrintDebug();

  jw::PQElement* max_element = queue.ExtractMax();
  assert(max_element->key_ == 9827);
  assert(max_element->value_ == "world");
  assert(queue.GetSize() == 4);

  max_element = queue.ExtractMax();
  assert(max_element->key_ == 1221);
  assert(max_element->value_ == "things");
  assert(queue.GetSize() == 3);

  queue.Remove(2);
  assert(queue.GetSize() == 2);
  queue.Remove(0);
  queue.Remove(0);
  assert(queue.GetSize() == 0);

  delete max_element;

  // now we'll sort an array in-place

  int to_sort[10] = {613, 55, 8721, 472, 94, 72, 74, 8, 61, 356};
  int sorted[10] = {8, 55, 61, 72, 74, 94, 356, 472, 613, 8721};

  jw::heapify(to_sort, 10);
  jw::heap_sort(to_sort, 10);

  assert(
      std::equal(std::begin(to_sort), std::end(to_sort), std::begin(sorted)));

  exit(EXIT_SUCCESS);
}