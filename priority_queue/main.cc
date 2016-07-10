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

  queue.PrintDebug();

  exit(EXIT_SUCCESS);
}