#include <string>
#include "gtest/gtest.h"
#include "linked_list.cc"
#include "linked_list.h"
#include "list_element.h"

namespace {

class SizeTest : public ::testing::Test {};

TEST_F(SizeTest, SizeEmpty) {
  jw::LinkedList<int> list{};
  int size = list.Size();

  EXPECT_EQ(size, 0);
}

TEST_F(SizeTest, Size1to2) {
  jw::LinkedList<int> list{};
  list.PushFront(4);

  EXPECT_EQ(list.Size(), 1);

  list.PushFront(9);
  EXPECT_EQ(list.Size(), 2);
}

TEST_F(SizeTest, Size3) {
  jw::LinkedList<int> list{};
  list.PushFront(4);
  list.PushFront(9);
  list.PushFront(13);
  EXPECT_EQ(list.Size(), 3);
}

class EmptyTest : public ::testing::Test {};

TEST_F(EmptyTest, Empty) {
  jw::LinkedList<std::string> list{};

  EXPECT_TRUE(list.Empty());
  list.PushFront("word");

  EXPECT_FALSE(list.Empty());
}

class ValueAtTest : public ::testing::Test {};

TEST_F(ValueAtTest, Value012) {
  jw::LinkedList<int> list{};

  list.PushFront(99);
  EXPECT_EQ(list.ValueAt(0), 99);

  list.PushFront(3);
  list.PushFront(122);
  EXPECT_EQ(list.ValueAt(0), 122);
  EXPECT_EQ(list.ValueAt(1), 3);
  EXPECT_EQ(list.ValueAt(2), 99);
}

class PopFrontTest : public ::testing::Test {};

TEST_F(PopFrontTest, Pop1) {
  jw::LinkedList<int> list{};

  list.PushFront(66);
  int val = list.PopFront();

  EXPECT_EQ(val, 66);
}

TEST_F(PopFrontTest, Pop2) {
  jw::LinkedList<int> list{};

  list.PushFront(12);
  list.PushFront(11);

  EXPECT_EQ(list.PopFront(), 11);
  EXPECT_EQ(list.PopFront(), 12);
}

class PushBackTest : public ::testing::Test {};

TEST_F(PushBackTest, PushEmpty) {
  jw::LinkedList<int> list{};

  list.PushBack(4);
  EXPECT_EQ(list.Size(), 1);
}

TEST_F(PushBackTest, PushNonEmpty) {
  jw::LinkedList<int> list{};

  list.PushBack(123);
  list.PushBack(456);

  EXPECT_EQ(list.Size(), 2);
  EXPECT_EQ(list.ValueAt(0), 123);
  EXPECT_EQ(list.ValueAt(1), 456);
}

class PopBackTest : public ::testing::Test {};

TEST_F(PopBackTest, Pop1) {
  jw::LinkedList<int> list{};

  list.PushBack(4);
  int val = list.PopBack();

  EXPECT_EQ(list.Size(), 0);
  EXPECT_EQ(val, 4);
}

TEST_F(PopBackTest, Pop2) {
  jw::LinkedList<int> list{};

  list.PushBack(33);
  list.PushBack(36);
  EXPECT_EQ(list.PopBack(), 36);
  EXPECT_EQ(list.PopBack(), 33);
  EXPECT_EQ(list.Size(), 0);
}

class FrontTest : public ::testing::Test {};

TEST_F(FrontTest, Front1) {
  jw::LinkedList<int> list{};

  list.PushFront(123);
  EXPECT_EQ(list.Front(), 123);
}

TEST_F(FrontTest, Front2) {
  jw::LinkedList<int> list{};

  list.PushFront(123);
  list.PushFront(456);
  EXPECT_EQ(list.Front(), 456);
}

class BackTest : public ::testing::Test {};

TEST_F(BackTest, Back1) {
  jw::LinkedList<int> list{};

  list.PushBack(3);
  EXPECT_EQ(list.Back(), 3);
}

TEST_F(BackTest, Back2) {
  jw::LinkedList<int> list{};

  list.PushBack(123);
  list.PushBack(456);
  EXPECT_EQ(list.Back(), 456);
}

class InsertTest : public ::testing::Test {};

TEST_F(InsertTest, InsertFrontEmpty) {
  jw::LinkedList<int> list{};

  list.Insert(0, 3);

  EXPECT_EQ(list.Front(), 3);
}

TEST_F(InsertTest, InsertFrontNonEmpty) {
  jw::LinkedList<int> list{};

  list.PushFront(123);
  list.Insert(0, 3);

  EXPECT_EQ(list.Front(), 3);
  EXPECT_EQ(list.Back(), 123);
}

TEST_F(InsertTest, InsertBack) {
  jw::LinkedList<int> list{};

  list.PushBack(123);
  list.Insert(1, 3);

  EXPECT_EQ(list.Back(), 3);
}

TEST_F(InsertTest, InsertMid) {
  jw::LinkedList<int> list{};

  list.PushBack(123);
  list.PushBack(456);
  list.PushBack(999);
  list.Insert(2, 777);

  EXPECT_EQ(list.ValueAt(1), 456);
  EXPECT_EQ(list.ValueAt(2), 777);
  EXPECT_EQ(list.Back(), 999);
}

class EraseTest : public ::testing::Test {};

TEST_F(EraseTest, EraseOnly) {
  jw::LinkedList<int> list{};

  list.PushBack(44);
  list.Erase(0);

  EXPECT_EQ(list.Size(), 0);
}

TEST_F(EraseTest, EraseFirst) {
  jw::LinkedList<int> list{};

  list.PushBack(44);
  list.PushBack(55);
  list.Erase(0);

  EXPECT_EQ(list.Size(), 1);
  EXPECT_EQ(list.Front(), 55);
}

TEST_F(EraseTest, EraseLast) {
  jw::LinkedList<int> list{};

  list.PushBack(44);
  list.PushBack(55);
  list.Erase(1);

  EXPECT_EQ(list.Size(), 1);
  EXPECT_EQ(list.Front(), 44);
}

TEST_F(EraseTest, EraseMid) {
  jw::LinkedList<int> list{};

  list.PushBack(44);
  list.PushBack(55);
  list.PushBack(66);
  list.Erase(1);

  EXPECT_EQ(list.Size(), 2);
  EXPECT_EQ(list.Front(), 44);
  EXPECT_EQ(list.Back(), 66);
}


} // namespace [anonymous]
