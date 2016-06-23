#include "hash_tables_tests.h"

void run_all_tests() {
  test_add_exists();
}

void test_add_exists() {
  jw::HashTable states(100);

  auto tx = new jw::HashObject();
  tx->SetKey("Texas");
  tx->SetValue("Austin");

  states.Add(tx);
}