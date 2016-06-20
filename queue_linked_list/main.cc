#include <cstdlib>
#include <iostream>

#include "src/queue_linked_list.cc"
#include "src/queue_linked_list.h"

// for stdlib experiments:
#include <queue>
#include <stack>

void stdlib_stack_experiment();
void stdlib_queue_experiment();

int main(int argc, char *argv[]) {
  std::cout << "====== Stack ========" << std::endl;
  stdlib_stack_experiment();

  std::cout << "====== Queue ========" << std::endl;
  stdlib_queue_experiment();

  return EXIT_SUCCESS;
}

void stdlib_stack_experiment() {
  auto my_stack = std::stack<int>();

  std::cout << "Pushed 34" << std::endl;
  my_stack.push(34);
  int top = my_stack.top();
  my_stack.pop();
  std::cout << "Popped: " << top << std::endl;

  my_stack.push(123);
  my_stack.push(634);
  my_stack.push(2372);
  my_stack.push(134);
  my_stack.push(7);

  std::cout << "Size: " << my_stack.size() << std::endl;

  while (!my_stack.empty()) {
    std::cout << "Popping: " << my_stack.top() << std::endl;
    my_stack.pop();
  }
}

void stdlib_queue_experiment() {
  auto my_q = std::queue<std::string>();

  std::cout << "Pushing " << std::endl;
  my_q.push("first!");
  my_q.push("second");
  my_q.push("third");

  std::cout << "Size: " << my_q.size() << std::endl;

  while (!my_q.empty()) {
    std::cout << "Popping: " << my_q.front() << std::endl;
    my_q.pop();
  }
}