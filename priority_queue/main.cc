#include <assert.h>
#include "priority_queue.cc"

int main(int argc, char* argv[]) {
  jw::PriorityQueue queue(10);

  assert(queue.IsEmpty());

  queue.Insert(23, "hello");
  assert(!queue.IsEmpty());
  queue.Insert(9827, "world");
  queue.Insert(662, "C++");
  queue.Insert(551, "nice");
  queue.Insert(1221, "things");

  jw::PQElement* max = queue.GetMax();
  assert(max->key_ == 9827);
  assert(max->value_ == "world");

  queue.PrintDebug();

  exit(EXIT_SUCCESS);
}