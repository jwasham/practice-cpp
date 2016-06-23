#include <assert.h>
#include <stdlib.h>  // abs
#include <iostream>
#include <string>
#include "hash_object.h"

#ifndef PROJECT_HASH_TABLE_H
#define PROJECT_HASH_TABLE_H

namespace jw {
class HashTable {
 public:
  explicit HashTable(const int size);
  ~HashTable();
  HashTable(const HashTable &) = delete;
  HashTable &operator=(const HashTable &) = delete;

  // Add the given key and object to hash table. If key exists, update the
  // value.
  void Add(HashObject *object);
  // Returns true if the given key exists in the table
  bool Exists(const std::string key);
  // Returns the value associated with the given key, or NULL if it doesn't
  // exist
  const std::string Get(const std::string key);
  // Removes the value associated with key from the table.
  void Remove(const std::string key);
  // Outputs the content of the hash table for debugging purposes.
  void PrintDebug();

 private:
  int size_;
  HashObject *data_;

  int Hash(const std::string key);
};
}

#endif  // PROJECT_HASH_TABLE_H
