#include <assert.h>
#include <iostream>
#include <string>
#include "queue_linked_list.cc"
#include "queue_linked_list.h"

void run_all_tests();
void test_empty();
void test_enqueue();
void test_dequeue();

int main(int argc, char *argv[]) {
  run_all_tests();

  return EXIT_SUCCESS;
}

void run_all_tests() {
  test_empty();
  test_enqueue();
  test_dequeue();
}

void test_empty() {
  jw::Queue<int> q;

  assert(q.Empty());

  q.Enqueue(3);

  assert(!q.Empty());
}

void test_enqueue() {
  jw::Queue<double> q;

  q.Enqueue(12.3);
  q.Enqueue(4.235);
  q.Enqueue(5.4);
  q.Enqueue(7.0);
  q.Enqueue(885314.32214);

  assert(!q.Empty());
}

void test_dequeue() {
  jw::Queue<int> q;

  q.Enqueue(100);
  q.Enqueue(200);
  assert(q.Dequeue() == 100);
  q.Enqueue(300);
  assert(q.Dequeue() == 200);
  q.Enqueue(400);
  q.Enqueue(500);
  q.Enqueue(600);
  q.Enqueue(700);
  assert(q.Dequeue() == 300);
  assert(q.Dequeue() == 400);
  assert(q.Dequeue() == 500);
  assert(q.Dequeue() == 600);
  assert(q.Dequeue() == 700);

  assert(q.Empty());
}