#include "hash_table.h"

namespace jw {

HashTable::HashTable(const int size) {
  size_ = size;
  data_ = new HashObject[size];
  assert(data_ != nullptr);

  for (int i = 0; i < size; ++i) {
    data_[i].SetKey(HashObject::GetNullKey());
  }
}

HashTable::~HashTable() { delete[] data_; }

int HashTable::Hash(const std::string key) {
  int hash = 0;

  int key_length = static_cast<int>(key.length());
  for (int i = 0; i < key_length; ++i) {
    hash = hash * 31 + key[i];
  }

  return abs(hash % size_);
}

bool HashTable::Exists(const std::string key) {
  int index = Hash(key);
  int original_index = index;
  bool found = false;

  while (data_[index].GetKey() != HashObject::GetNullKey()) {
    if (data_[index].GetKey() == key) {
      found = true;
      break;
    }
    index = (index + 1) % size_;
    if (index == original_index) {
      break;
    }
  }

  return found;
}

void HashTable::Add(HashObject* object) {
  int index = Hash(object->GetKey());
  int original_index = index;
  int dummyIndex = -1;

  bool found = false;
  while (data_[index].GetKey() != HashObject::GetNullKey()) {
    if (data_[index].GetKey() == object->GetKey()) {
      found = true;
      break;
    } else if (data_[index].GetKey() == HashObject::GetDummyKey()) {
      dummyIndex = index;
    }
    index = (index + 1) % size_;
    if (index == original_index) {
      return;
    }
  }

  if (!found && dummyIndex != -1) {
    index = dummyIndex;
  }

  data_[index].SetKey(object->GetKey());
  data_[index].SetValue(object->GetValue());
}

void HashTable::PrintDebug() {
  for (int i = 0; i < size_; ++i) {
    std::cout << i << ": " << data_[i].GetKey() << ":" << data_[i].GetValue()
              << std::endl;
  }

  std::cout << "--------------------------\n" << std::endl;
}

void HashTable::Remove(const std::string key) {
  int index = Hash(key);
  int original_index = index;

  while (data_[index].GetKey() != HashObject::GetNullKey()) {
    if (data_[index].GetKey() == key) {
      data_[index].SetKey(HashObject::GetDummyKey());
      data_[index].SetValue("");
      break;
    }
    index = (index + 1) % size_;
    if (index == original_index) {
      break;
    }
  }
}

const std::string HashTable::Get(const std::string key) {
  int index = Hash(key);
  int original_index = index;

  while (data_[index].GetKey() != HashObject::GetNullKey()) {
    if (data_[index].GetKey() == key) {
      return data_[index].GetValue();
    }
    index = (index + 1) % size_;
    if (index == original_index) {
      break;
    }
  }

  return NULL;
}
};