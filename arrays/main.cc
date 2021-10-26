#include <assert.h>
#include <bits/stdc++.h>>

void StandardExperiment();

int main(int argc, char *argv[]) {

  jw::JVectorTest tester;
  tester.RunTests();
  return EXIT_SUCCESS;
}

void StandardExperiment() {

  std::cout << "Now messing with std implementation." << std::endl;

  std::vector<int> myv{12, 23, 5, 3};

  std::cout << "Size: " << myv.size() << std::endl;
  std::cout << "Capacity: " << myv.capacity() << std::endl;

  std::cout << "Adding a few items" << std::endl;

  myv.push_back(4);
  myv.push_back(12);
  myv.push_back(45);

  std::cout << "Size: " << myv.size() << std::endl;
  std::cout << "Capacity: " << myv.capacity() << std::endl;
  std::cout << "Popping 1" << std::endl;

  myv.pop_back();

  std::cout << "Size: " << myv.size() << std::endl;
  std::cout << "Capacity: " << myv.capacity() << std::endl;

  std::cout << "Items:" << std::endl;
  for (int value : myv) {
    std::cout << value << std::endl;
  }

  std::cout << "Inserting at index 4" << std::endl;
  myv.insert(myv.begin() + 4, 99);

  std::cout << "Items:" << std::endl;
  for (int value : myv) {
    std::cout << value << std::endl;
  }

  for (int i = 0; i < 75; i++) {
    myv.push_back(i + 3);
  }

  std::cout << "Size: " << myv.size() << std::endl;
  std::cout << "Capacity: " << myv.capacity() << std::endl;

  std::cout << "Collapsing" << std::endl;
  myv.shrink_to_fit();
  std::cout << "Capacity: " << myv.capacity() << std::endl;

  std::cout << "Items:" << std::endl;
  for (unsigned long j = 0; j < myv.size(); ++j) {
    std::cout << j << ": " << myv.at(j) << std::endl;
  }

  std::cout << "Erasing items from indices from 4 to 11" << std::endl;
  myv.erase(myv.begin() + 4, myv.begin() + 12);

  std::cout << "Items:" << std::endl;
  for (unsigned long k = 0; k < myv.size(); k++) {
    std::cout << k << ":" << myv.at(k) << std::endl;
  }
}
