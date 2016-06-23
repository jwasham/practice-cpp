#include "hash_table.h"

namespace jw {

  HashTable::HashTable(const int size) {
    size_ = size;
    auto data_ = new HashObject [size](); // () initializes all to null ptr
  }

  HashTable::~HashTable() {
    delete [] data_;
  }

  int HashTable::Hash(const std::string key) {
    int hash = 0;

    int key_length = static_cast<int>(key.length());
    for (int i = 0; i < key_length; ++i) {
      hash = hash * 31 + key[i];
    }

    return abs(hash % size_);
  }

  void HashTable::Add(HashObject* object) {
    int index = Hash(object->GetKey());
    int dummyIndex = -1;

    std::cout << index << std::endl;

    bool found = false;
    while (data_[index] != nullptr) {
      if (data_[index]->GetKey() == object->GetKey()) {
        found = true;
        break;
      } else if (data_[index]->GetKey() == HashObject::GetDummyKey()) {
        dummyIndex = index;
      }
      index = (index + 1) % size_;
    }

    if (! found && dummyIndex != -1) {
      index =  dummyIndex;
    }

    if (data_[index] == nullptr) {
      data_[index] = new HashObject;
    } else {
      delete data_[index];
    }

    data_[index]->SetKey(object->GetKey());
    data_[index]->SetValue(object->GetValue());
  }

};