#include <unordered_map>
#include "hash_table.cc"
#include "hash_table.h"
#include "hash_tables_tests.cc"
#include "hash_tables_tests.h"

void stdlib_experiments();

int main(int argc, char *argv[]) {
  run_all_tests();
  //stdlib_experiments();

  return EXIT_SUCCESS;
}

void stdlib_experiments() {
  std::unordered_map<std::string, std::string> states;

  states["Texas"] = "Austin";
  states["Florida"] = "Tallahassee";
  states["Washington"] = "Olympia";

  for (auto it = states.begin(); it != states.end(); ++it)
    std::cout << "The capital of " << it->first << " is " << it->second << std::endl;

  auto iter = states.find("Oregon");
  if (iter == states.end()) {
    std::cout << "Oregon not found" << std::endl;
  }

  std::cout << "Bucket count: " << states.bucket_count() << std::endl;

  auto count = states.bucket_count();
  for (auto i = 0; i < count; ++i) {
    std::cout << "Size of bucket " << i << ": " << states.bucket_size(i) << std::endl;
  }
}