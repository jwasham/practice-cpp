#include <time.h>
#include <iostream>
#include <random>
#include <vector>

#ifndef PROJECT_EXPERIMENTS_H
#define PROJECT_EXPERIMENTS_H

using namespace std;

void print_vector() {
  const unsigned long f = 30;

  std::vector<int> mynums(f);

  std::cout << mynums.at(3) << std::endl;
}

void print_random() {
  cout << "Junk random: ";
  srand(time(0));
  cout << rand() % 100 << endl;

  cout << "Real random: ";
  std::random_device rng;
  std::uniform_int_distribution<int> dist(0, 99);
  int randnum = dist(rng);
  cout << randnum << endl;
}

void string_fun() {
  string foo("Hello");
  string other("Hello there");

  cout << foo.size() << endl;
  cout << foo.empty() << endl;

  cout << foo.append(" there") << endl;
  cout << foo << endl;

  if (foo == other) {
    cout << "They match with =" << endl;
  }

  if (foo.compare(other) == 0) {
    cout << "They match with compare" << endl;
  }

  cout << "Copying a substring..." << endl;
  string copy;
  copy.assign(foo, 0, 5);

  cout << "New: " << copy << endl;
  copy.append(" friend");
  cout << copy << endl;
  cout << foo << endl;

  cout << "Position of there: " << foo.find("there", 0) << endl;

  cout << "Removing 'there'" << endl;
  foo.erase(foo.find("there", 0), 5);
  cout << foo << endl;
}

void input_test() {
  std::string my_input;

  std::cout << "Enter a number: ";
  getline(std::cin, my_input);

  int num = std::stoi(my_input);
  std::cout << "You said " << num << std::endl;
}

void vectors() {
  std::vector<int> nums(100);
  std::vector<std::string> strings(5);

  cout << "Default int: " << nums.at(2) << endl;
  cout << "Default string: " << strings.at(2) << endl;

  strings[2] = "howdy";
  cout << "New string: " << strings.at(2) << endl;

  cout << "Size of strings vector: " << strings.size() << endl;

  cout << "Contents of string vector:" << endl;
  for (int i = 0; i < strings.size(); ++i) {
    cout << i << ": " << strings.at(i) << endl;
  }
}

#endif  // PROJECT_EXPERIMENTS_H
