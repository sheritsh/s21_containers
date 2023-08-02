#include <gtest/gtest.h>

#include <list>
#include <queue>
#include <stack>

#include "list.h"
#include "queue.h"
#include "stack.h"

// STACK
TEST(List, Constructor_Default) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, Constructor_Initializer_list) {
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, Constructor_Parameterized) {
  s21::list<double> s21_list(5);
  std::list<double> std_list(5);
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}
TEST(List, Constructor_Copy) {
  s21::list<char> s21_list_1 = {'a', 'b', 'c', 'd'};
  std::list<char> std_list_1 = {'a', 'b', 'c', 'd'};
  s21::list<char> s21_list_2 = s21_list_1;
  std::list<char> std_list_2 = std_list_1;

  EXPECT_EQ(s21_list_1.size(), s21_list_2.size());
  EXPECT_EQ(std_list_1.size(), std_list_2.size());
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}
TEST(List, Constructor_Move) {
  s21::list<char> s21_list_1 = {'a', 'b', 'c', 'd'};
  std::list<char> std_list_1 = {'a', 'b', 'c', 'd'};
  s21::list<char> s21_list_2 = std::move(s21_list_1);
  std::list<char> std_list_2 = std::move(std_list_1);

  EXPECT_EQ(s21_list_2.size(), std_list_2.size());
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
  auto it1 = s21_list_2.begin();
  auto it2 = std_list_2.begin();
  while (it1 != s21_list_2.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}

TEST(List, Modifier_Insert) {
  s21::list<int> s21_list_1 = {'a', 'c', 'd'};
  s21::list<int> s21_list_2 = {'a', 'b', 'c', 'd'};

  auto it = s21_list_1.begin();
  ++it;
  s21_list_1.insert(it, 'b');
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list_1.size(), s21_list_2.size());
}

TEST(List, Modifier_Erase) {
  s21::list<int> s21_list_1 = {'a', 'c', 'd'};
  s21::list<int> s21_list_2 = {'a', 'b', 'c', 'd'};

  auto it = s21_list_2.begin();
  ++it;
  s21_list_2.erase(it);
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list_1.size(), s21_list_2.size());
}

TEST(List, Modifier_Push) {
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};
  s21_list.push_back(5);
  s21_list.push_front(0);
  std_list.push_back(5);
  std_list.push_front(0);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
  auto it1 = s21_list.begin();
  auto it2 = std_list.begin();
  while (it1 != s21_list.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}

TEST(List, Modifier_Pop) {
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};
  s21_list.pop_back();
  s21_list.pop_front();
  std_list.pop_back();
  std_list.pop_front();
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
  auto it1 = s21_list.begin();
  auto it2 = std_list.begin();
  while (it1 != s21_list.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}

TEST(List, Modifier_Swap) {
  s21::list<char> s21_list_1 = {'a', 'b', 'o', 'b', 'a'};
  s21::list<char> s21_list_2 = {'s', 'h', 'l', 'e', 'p', 'p', 'a'};
  s21::list<char> s21_list_3 = {'a', 'b', 'o', 'b', 'a'};
  s21::list<char> s21_list_4 = {'s', 'h', 'l', 'e', 'p', 'p', 'a'};
  s21_list_1.swap(s21_list_2);
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  auto it3 = s21_list_3.begin();
  auto it4 = s21_list_4.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it4);
    ++it1, ++it4;
  }
  while (it2 != s21_list_2.end()) {
    EXPECT_EQ(*it2, *it3);
    ++it2, ++it3;
  }
  EXPECT_EQ(s21_list_1.size(), s21_list_4.size());
  EXPECT_EQ(s21_list_2.size(), s21_list_3.size());
}

TEST(List, Modifier_Merge) {
  s21::list<int> s21_list_1 = {1, 3, 7};
  s21::list<int> s21_list_2 = {-1, 0, 5, 8};
  std::list<int> std_list_1 = {1, 3, 7};
  std::list<int> std_list_2 = {-1, 0, 5, 8};
  s21_list_1.merge(s21_list_2);
  std_list_1.merge(std_list_2);
  auto it1 = s21_list_1.begin();
  auto it2 = std_list_1.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
}

TEST(List, Modifier_Reverse) {
  s21::list<int> s21_list_1 = {1, 2, 3, 4};
  s21::list<int> s21_list_2 = {4, 3, 2, 1};
  s21_list_1.reverse();
  auto it1 = s21_list_1.begin();
  auto it2 = s21_list_2.begin();
  while (it1 != s21_list_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list_1.size(), s21_list_2.size());
}

TEST(List, Modifier_Unique) {
  s21::list<int> s21_list{1, -1, -23, 4, 1, 5, 6, 4, -1, -1};
  std::list<int> std_list{1, -1, -23, 4, 1, 5, 6, 4, -1, -1};
  s21_list.unique();
  std_list.unique();
  auto it1 = s21_list.begin();
  auto it2 = std_list.begin();
  while (it1 != s21_list.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(List, Modifier_Sort) {
  s21::list<int> s21_list{1, -1, -23, 4, 1, 5, 6, 4, -1, -1};
  std::list<int> std_list{1, -1, -23, 4, 1, 5, 6, 4, -1, -1};
  s21_list.sort();
  std_list.sort();
  auto it1 = s21_list.begin();
  auto it2 = std_list.begin();
  while (it1 != s21_list.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}

TEST(stack, Constructor_Default) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(stack, Constructor_Initializer_stack) {
  s21::stack<int> s21_stack = {1, 2, 3, 4};
  EXPECT_EQ(s21_stack.top(), 4);
  EXPECT_EQ(s21_stack.size(), size_t(4));
  EXPECT_EQ(s21_stack.empty(), false);
}

TEST(stack, Constructor_Copy) {
  s21::stack<char> s21_stack_1 = {'a', 'b', 'c', 'd'};
  s21::stack<char> s21_stack_2 = s21_stack_1;

  EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());

  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_stack_1.top(), s21_stack_2.top());
    EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());
    s21_stack_1.pop(), s21_stack_2.pop();
  }
}

TEST(stack, Constructor_Move) {
  s21::stack<char> s21_stack_1 = {'a', 'b', 'c', 'd'};
  s21::stack<char> s21_stack_2 = std::move(s21_stack_1);
  s21::stack<char> s21_stack_3 = {'a', 'b', 'c', 'd'};

  EXPECT_EQ(s21_stack_2.size(), s21_stack_3.size());
  EXPECT_EQ(s21_stack_1.size(), size_t(0));
  EXPECT_EQ(s21_stack_1.empty(), true);
  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_stack_3.top(), s21_stack_2.top());
    EXPECT_EQ(s21_stack_3.size(), s21_stack_2.size());
    s21_stack_3.pop(), s21_stack_2.pop();
  }
}

TEST(stack, Modifier_Push) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(stack, Modifier_Pop) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);
  s21_stack.pop();
  s21_stack.pop();
  std_stack.pop();
  std_stack.pop();
  s21_stack.push(15);
  s21_stack.push(10);
  std_stack.push(15);
  std_stack.push(10);
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(stack, Modifier_Swap) {
  s21::stack<std::string> s21_stack_1 = {"aboba", "shleppa", "amogus",
                                         "abobus"};
  s21::stack<std::string> s21_stack_2 = {"shtirlits", "vovochka", "poruchik"};
  s21::stack<std::string> s21_stack_3 = {"aboba", "shleppa", "amogus",
                                         "abobus"};
  s21::stack<std::string> s21_stack_4 = {"shtirlits", "vovochka", "poruchik"};

  s21_stack_1.swap(s21_stack_2);

  EXPECT_EQ(s21_stack_1.size(), s21_stack_4.size());
  EXPECT_EQ(s21_stack_2.size(), s21_stack_3.size());
  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_stack_3.top(), s21_stack_2.top());
    EXPECT_EQ(s21_stack_3.size(), s21_stack_2.size());
    s21_stack_3.pop(), s21_stack_2.pop();
  }
  for (auto i = 0; i < 3; i++) {
    EXPECT_EQ(s21_stack_1.top(), s21_stack_4.top());
    EXPECT_EQ(s21_stack_1.size(), s21_stack_4.size());
    s21_stack_1.pop(), s21_stack_4.pop();
  }
}

TEST(queue, Constructor_Default) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(queue, Constructor_Initializer_queue) {
  s21::queue<int> s21_queue = {1, 2, 3, 4};
  EXPECT_EQ(s21_queue.front(), 1);
  EXPECT_EQ(s21_queue.back(), 4);
  EXPECT_EQ(s21_queue.size(), size_t(4));
  EXPECT_EQ(s21_queue.empty(), false);
}

TEST(queue, Constructor_Copy) {
  s21::queue<char> s21_queue_1 = {'a', 'b', 'c', 'd'};
  s21::queue<char> s21_queue_2 = s21_queue_1;

  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());

  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop(), s21_queue_2.pop();
  }
}

TEST(queue, Constructor_Move) {
  s21::queue<char> s21_queue_1 = {'a', 'b', 'c', 'd'};
  s21::queue<char> s21_queue_2 = std::move(s21_queue_1);
  s21::queue<char> s21_queue_3 = {'a', 'b', 'c', 'd'};

  EXPECT_EQ(s21_queue_2.size(), s21_queue_3.size());
  EXPECT_EQ(s21_queue_1.size(), size_t(0));
  EXPECT_EQ(s21_queue_1.empty(), true);
  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_queue_3.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_3.size(), s21_queue_2.size());
    s21_queue_3.pop(), s21_queue_2.pop();
  }
}

TEST(queue, Modifier_Push) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(5);
  s21_queue.push(0);
  std_queue.push(5);
  std_queue.push(0);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(queue, Modifier_Pop) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(5);
  s21_queue.push(0);
  std_queue.push(5);
  std_queue.push(0);
  s21_queue.pop();
  s21_queue.pop();
  std_queue.pop();
  std_queue.pop();
  s21_queue.push(15);
  s21_queue.push(10);
  std_queue.push(15);
  std_queue.push(10);
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(queue, Modifier_Swap) {
  s21::queue<std::string> s21_queue_1 = {"aboba", "shleppa", "amogus",
                                         "abobus"};
  s21::queue<std::string> s21_queue_2 = {"shtirlits", "vovochka", "poruchik"};
  s21::queue<std::string> s21_queue_3 = {"aboba", "shleppa", "amogus",
                                         "abobus"};
  s21::queue<std::string> s21_queue_4 = {"shtirlits", "vovochka", "poruchik"};

  s21_queue_1.swap(s21_queue_2);

  EXPECT_EQ(s21_queue_1.size(), s21_queue_4.size());
  EXPECT_EQ(s21_queue_2.size(), s21_queue_3.size());
  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_queue_3.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_3.size(), s21_queue_2.size());
    s21_queue_3.pop(), s21_queue_2.pop();
  }
  for (auto i = 0; i < 3; i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_4.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_4.size());
    s21_queue_1.pop(), s21_queue_4.pop();
  }
}

/* ------------------------ LIST -------------------------- */

template <typename value_type>
bool compare_lists(s21::list<value_type> my_list,
                   std::list<value_type> std_list) {
  bool result = true;
  if (my_list.size() == std_list.size()) {
    auto my_it = my_list.begin();
    auto std_it = std_list.begin();
    for (size_t i = 0; i != my_list.size(); ++i) {
      if (*my_it != *std_it) {
        result = false;
        break;
      }
      my_it++;
      std_it++;
    }
  } else {
    result = false;
  }
  return result;
}

TEST(ListTest, CompareLists) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  EXPECT_TRUE(compare_lists(my_list, std_list));
  std_list.push_back(6);
  EXPECT_FALSE(compare_lists(my_list, std_list));
  std_list.pop_back();
  my_list.push_front(0);
  std_list.push_front(0);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, DefaultConstructor) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.size(), 0);
  EXPECT_TRUE(my_list.empty());

  EXPECT_TRUE(compare_lists(my_list, std_list));
};

TEST(ListTest, SizeConstructor) {
  s21::list<int> my_list(1000000);
  std::list<int> std_list(1000000);
  EXPECT_EQ(my_list.size(), 1000000);
  EXPECT_TRUE(compare_lists(my_list, std_list));
};

TEST(ListTest, InitializerListConstructor) {
  s21::list<int> my_list{1, 2, 3, 7, 9};
  std::list<int> std_list{1, 2, 3, 7, 9};
  EXPECT_TRUE(compare_lists(my_list, std_list));
};

TEST(ListTest, InitializerListConstructor_2) {
  std::initializer_list<int> b;
  s21::list<int> my_list{b};
  std::list<int> std_list{b};
  EXPECT_TRUE(compare_lists(my_list, std_list));
};

TEST(ListTest, CopyConstructor) {
  s21::list<int> my_list{1, 2, 3};
  s21::list<int> my_list_copy(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
};

TEST(ListTest, CopyConstructorEmpty) {
  s21::list<int> my_list;
  s21::list<int> my_list_copy(my_list);
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
};

TEST(ListTest, MoveConstructor) {
  s21::list<int> my_list{1, 2, 3};
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move(std::move(my_list));
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move(std::move(std_list));
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveConstructorEmpty) {
  s21::list<int> my_list;
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move(std::move(my_list));
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move(std::move(std_list));
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveAssignmentOperator) {
  s21::list<int> my_list{1, 2, 3};
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move = std::move(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move = std::move(std_list);
  EXPECT_TRUE(compare_lists(my_list_move, std_list_move));
}

TEST(ListTest, MoveAssignmentOperatorEmpty) {
  s21::list<int> my_list;
  s21::list<int> my_list_copy(my_list);
  s21::list<int> my_list_move = std::move(my_list);
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move = std::move(std_list);
  EXPECT_TRUE(compare_lists(my_list_move, std_list_move));
}

TEST(ListTest, Front) {
  s21::list<int> my_list{99, 2, 3, 4, 5};
  std::list<int> std_list{99, 2, 3, 4, 5};
  EXPECT_EQ(my_list.front(), std_list.front());
}

TEST(ListTest, Back) {
  s21::list<int> my_list{1, 2, 3, 4, 99};
  std::list<int> std_list{1, 2, 3, 4, 99};
  EXPECT_EQ(my_list.back(), std_list.back());
}

TEST(ListTest, Empty) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.empty(), std_list.empty());
  my_list.push_back(10);
  std_list.push_back(10);
  EXPECT_EQ(my_list.empty(), std_list.empty());
}

TEST(ListTest, Size) {
  s21::list<int> my_list{1, 2, 3, 4, 5, 6, 7, 8};
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, SizeEmpty) {
  s21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, Clear) {
  s21::list<int> my_list{1, 2, 3, 4};
  my_list.clear();
  std::list<int> std_list{1, 2, 5, 4, 3};
  std_list.clear();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, ClearEmpty) {
  s21::list<int> my_list;
  my_list.clear();
  std::list<int> std_list;
  std_list.clear();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PushBack) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.push_back(6);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_back(6);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PopBack) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.pop_back();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_back();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PushFront) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.push_front(0);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_front(0);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PopFront) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.pop_front();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_front();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Swap) {
  s21::list<int> my_list1{1, 2, 3, 4, 5};
  s21::list<int> my_list2{6, 7, 8, 9, 10, 11};
  my_list1.swap(my_list2);

  std::list<int> std_list1{1, 2, 3, 4, 5};
  std::list<int> std_list2{6, 7, 8, 9, 10, 11};
  std_list1.swap(std_list2);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
  EXPECT_TRUE(compare_lists(my_list2, std_list2));
}

TEST(ListTest, Swap_2) {
  s21::list<int> my_list1{1, 5, 8, 100};
  s21::list<int> my_list2;
  my_list1.swap(my_list2);

  std::list<int> std_list1{1, 5, 8, 100};
  std::list<int> std_list2;
  std_list1.swap(std_list2);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
  EXPECT_TRUE(compare_lists(my_list2, std_list2));
}
//
TEST(ListTest, begin_1) {
  s21::list<int> my_list1{500, 15000, 30000};

  std::list<int> std_list2{500, 15000, 30000};
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

TEST(ListTest, begin_2) {
  s21::list<int> my_list1(4);

  std::list<int> std_list2(4);
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

//
TEST(ListTest, end_1) {
  s21::list<int> my_list1{500, 15000, 30000};

  std::list<int> std_list2{500, 15000, 30000};
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

//
TEST(ListTest, Merge_1) {
  s21::list<int> my_list1{1, 9999, 20000};
  s21::list<int> my_list2{500, 15000, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_2) {
  s21::list<int> my_list1{1, 9999, 20000};
  s21::list<int> my_list2{15000, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{15000, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_3) {
  s21::list<int> my_list1{1, 20000, 666};
  s21::list<int> my_list2{15000, 154, 124, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 20000, 666};
  std::list<int> std_list2{15000, 154, 124, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_4) {
  s21::list<int> my_list1;
  s21::list<int> my_list2{15000, 154, 124, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{15000, 154, 124, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_5) {
  s21::list<int> my_list1{1, 20000, 666};
  s21::list<int> my_list2;
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 20000, 666};
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_6) {
  s21::list<int> my_list1;
  s21::list<int> my_list2;
  my_list1.merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Reverse_1) {
  s21::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Reverse_2) {
  s21::list<int> my_list(4);
  std::list<int> std_list(4);
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Reverse_3) {
  s21::list<int> my_list;
  std::list<int> std_list;
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_1) {
  s21::list<int> my_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  std::list<int> std_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_2) {
  s21::list<int> my_list(3);
  std::list<int> std_list(3);
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_3) {
  s21::list<int> my_list;
  std::list<int> std_list;
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Splice_1) {
  s21::list<int> my_list1{1, 9999, 20000};
  s21::list<int> my_list2{500, 15000, 30000};
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}
//
TEST(ListTest, Splice_2) {
  s21::list<int> my_list1;
  s21::list<int> my_list2{500, 15000, 30000};
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_3) {
  s21::list<int> my_list1{1, 9999, 20000};
  s21::list<int> my_list2;
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_4) {
  s21::list<int> my_list1;
  s21::list<int> my_list2;
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}
//
TEST(ListTest, Insert_1) {
  s21::list<int> my_list1{1, 9999, 20000};
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}
//
TEST(ListTest, Insert_2) {
  s21::list<int> my_list1{1, 9999, 20000};
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}
//
TEST(ListTest, Insert_3) {
  s21::list<int> my_list1;
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}
//
TEST(ListTest, Insert_4) {
  s21::list<int> my_list1;
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}
//
TEST(ListTest, Insert_5) {
  s21::list<int> my_list1(4);
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}
//
TEST(ListTest, Insert_6) {
  s21::list<int> my_list1(4);
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}
TEST(ListTest, Erase_1) {
  s21::list<int> my_list1{1, 9999, 20000};
  my_list1.erase(my_list1.begin());

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.erase(std_list1.begin());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_3) {
  s21::list<int> my_list1{1, 9999, 20000};
  my_list1.erase(--my_list1.end());

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_5) {
  s21::list<int> my_list1(5);
  my_list1.erase(--my_list1.end());

  std::list<int> std_list1(5);
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

/* ---------------------------- QUEUE ----------------------------- */

class S21queueTest : public testing::Test {
 protected:
  class Example {
   public:
    Example() : x_(0), y_(0){};
    Example(int x, int y) : x_(x), y_(y){};
    int getX() { return x_; }
    int getY() { return y_; }
    bool operator==(const Example& other) const {
      return x_ == other.x_ && y_ == other.y_;
    }

   private:
    int x_, y_;
  };

  s21::queue<Example> s21_queue_emplace;
  s21::queue<int> s21_queue_empty;
  s21::queue<char> s21_queue_init_list{'c', 'b', 'a'};
  s21::queue<int> s21_queue_for_copy{1, 1, 2, 3, 5, 8, 13};

  std::queue<int> std_queue_empty;
  std::queue<Example> std_queue_emplace;
};

TEST_F(S21queueTest, DefaultConstructor) {
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
  EXPECT_EQ(s21_queue_empty.empty(), std_queue_empty.empty());
}

TEST_F(S21queueTest, InitializerListConstructor) {
  std::initializer_list<int> init_list_for_copy = {1, 1, 2, 3, 5, 8, 13};
  s21::queue<int> s21_queue{init_list_for_copy};
  std::queue<int> std_queue{init_list_for_copy};
  EXPECT_EQ(s21_queue.size(), std_queue.size());

  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21queueTest, CopyConstructor) {
  std::initializer_list<int> init_list_for_copy = {1, 1, 2, 3, 5, 8, 13};
  s21::queue<int> s21_queue_for_copy{init_list_for_copy};
  std::queue<int> std_queue_for_copy{init_list_for_copy};

  s21::queue<int> s21_queue(s21_queue_for_copy);
  std::queue<int> std_queue(std_queue_for_copy);

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21queueTest, AssignmentOperatorCopy) {
  std::initializer_list<int> init_list_for_copy = {1, 1, 2, 3, 5, 8, 13};
  s21::queue<int> s21_queue_for_copy{init_list_for_copy};
  std::queue<int> std_queue_for_copy{init_list_for_copy};

  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue = s21_queue_for_copy;
  std_queue = std_queue_for_copy;

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21queueTest, MoveConstructor) {
  std::initializer_list<int> init_list_for_move = {1, 1, 2, 3, 5, 8, 13};
  s21::queue<int> s21_queue_for_move{init_list_for_move};
  std::queue<int> std_queue_for_move{init_list_for_move};

  s21::queue<int> s21_queue(std::move(s21_queue_for_move));
  std::queue<int> std_queue(std::move(std_queue_for_move));

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21queueTest, AssignmentOperatorMove) {
  std::initializer_list<int> init_list_for_move = {1, 1, 2, 3, 5, 8, 13};
  s21::queue<int> s21_queue_for_move{init_list_for_move};
  std::queue<int> std_queue_for_move{init_list_for_move};

  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  std_queue = std::move(std_queue_for_move);
  s21_queue = std::move(s21_queue_for_move);

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST_F(S21queueTest, Push) {
  s21_queue_empty.push(1);
  std_queue_empty.push(1);
  EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
  s21_queue_empty.push(1123213);
  std_queue_empty.push(1123213);

  EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
}

TEST_F(S21queueTest, Pop) {
  s21_queue_empty.push(1);
  std_queue_empty.push(1);
  s21_queue_empty.push(1123213);
  std_queue_empty.push(1123213);

  s21_queue_empty.pop();
  std_queue_empty.pop();
  EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());

  s21_queue_empty.pop();
  std_queue_empty.pop();
  EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
}

TEST_F(S21queueTest, Swap) {
  std::initializer_list<int> init_list = {1, 1, 3, 6};
  std::initializer_list<int> init_list_for_swap = {1, 3, 5, 5, 6, 7};
  s21::queue<int> s21_queue{init_list};
  s21::queue<int> s21_queue_for_swap{init_list_for_swap};

  std::queue<int> std_queue{init_list};
  std::queue<int> std_queue_for_swap{init_list_for_swap};

  s21_queue.swap(s21_queue_for_swap);
  std_queue.swap(std_queue_for_swap);

  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue_for_swap.size(), std_queue_for_swap.size());

  while (!s21_queue.empty() && !std_queue.empty()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }

  while (!s21_queue_for_swap.empty() && !std_queue_for_swap.empty()) {
    EXPECT_EQ(s21_queue_for_swap.front(), std_queue_for_swap.front());
    EXPECT_EQ(s21_queue_for_swap.back(), std_queue_for_swap.back());
    s21_queue_for_swap.pop();
    std_queue_for_swap.pop();
  }
}

// TEST_F(S21queueTest, EmplaceBack) {
//   s21_queue_emplace.push(Example(1, 2));
//   std_queue_emplace.push(Example(1, 2));
//   EXPECT_EQ(s21_queue_emplace.size(), std_queue_emplace.size());
//   EXPECT_EQ(s21_queue_emplace.front(), std_queue_emplace.front());
//   EXPECT_EQ(s21_queue_emplace.back(), std_queue_emplace.back());
//   s21_queue_emplace.insert_many_back(4, 5);
//   std_queue_emplace.emplace(4, 5);
//   EXPECT_EQ(s21_queue_emplace.size(), std_queue_emplace.size());
//   EXPECT_EQ(s21_queue_emplace.front(), std_queue_emplace.front());
//   EXPECT_EQ(s21_queue_emplace.back(), std_queue_emplace.back());
// }

/* ------------------------ STACK ------------------------------ */

class S21stackTest : public testing::Test {
 protected:
  class Example {
   public:
    Example() : x_(0), y_(0){};
    Example(int x, int y) : x_(x), y_(y){};
    int getX() { return x_; }
    int getY() { return y_; }
    bool operator==(const Example& other) const {
      return x_ == other.x_ && y_ == other.y_;
    }

   private:
    int x_, y_;
  };

  s21::stack<Example> s21_stack_emplace;
  s21::stack<int> s21_empty;
  s21::stack<char> s21_init_list{'c', 'b', 'a'};
  s21::stack<int> s21_stack_for_copy{1, 1, 2, 3, 5, 8, 13};

  std::stack<int> std_empty;
  std::stack<Example> std_stack_emplace;
};

TEST_F(S21stackTest, DefaultConstructor) {
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  EXPECT_EQ(s21_empty.empty(), std_empty.empty());
}

TEST_F(S21stackTest, InitializerListConstructor) {
  std::initializer_list<int> init_list = {1, 2, 3};
  s21::stack<int> s21_stack{init_list};
  std::stack<int> std_stack{init_list};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST_F(S21stackTest, CopyConstructor) {
  std::initializer_list<int> init_list_for_copy = {1, 1, 2, 3, 5, 8, 13};
  s21::stack<int> s21_stack_for_copy{init_list_for_copy};
  std::stack<int> std_stack_for_copy{init_list_for_copy};

  s21::stack<int> s21_stack(s21_stack_for_copy);
  std::stack<int> std_stack(std_stack_for_copy);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

TEST_F(S21stackTest, AssignmentOperatorCopy) {
  std::initializer_list<double> init_list_for_copy = {1231.4, 1.342, 3.23, 4.4};
  s21::stack<double> s21_stack_for_move{init_list_for_copy};
  std::stack<double> std_stack_for_move{init_list_for_copy};

  s21::stack<double> s21_stack;
  s21_stack = s21_stack_for_move;
  std::stack<double> std_stack;
  std_stack = std_stack_for_move;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }

  EXPECT_EQ(s21_stack_for_move.size(), std_stack_for_move.size());
}

TEST_F(S21stackTest, MoveConstructor) {
  std::initializer_list<double> init_list_for_move = {1231.4, 1.342, 3.23, 4.4};
  s21::stack<double> s21_stack_for_move{init_list_for_move};
  std::stack<double> std_stack_for_move{init_list_for_move};

  s21::stack<double> s21_stack(std::move(s21_stack_for_move));
  std::stack<double> std_stack(std::move(std_stack_for_move));
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }

  EXPECT_EQ(s21_stack_for_move.size(), std_stack_for_move.size());
}

TEST_F(S21stackTest, AssignmentOperatorMove) {
  std::initializer_list<double> init_list_for_copy = {1231.4, 1.342, 3.23, 4.4};
  s21::stack<double> s21_stack_for_move{init_list_for_copy};
  std::stack<double> std_stack_for_move{init_list_for_copy};

  s21::stack<double> s21_stack;
  s21_stack = std::move(s21_stack_for_move);
  std::stack<double> std_stack;
  std_stack = std::move(std_stack_for_move);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }

  EXPECT_EQ(s21_stack_for_move.size(), std_stack_for_move.size());
}

TEST_F(S21stackTest, Push) {
  s21_empty.push(123);
  std_empty.push(123);
  EXPECT_EQ(s21_empty.top(), std_empty.top());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  s21_empty.push(45322345);
  std_empty.push(45322345);
  EXPECT_EQ(s21_empty.top(), std_empty.top());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
}

TEST_F(S21stackTest, Pop) {
  s21_empty.push(123);
  std_empty.push(123);
  s21_empty.push(45322345);
  std_empty.push(45322345);
  EXPECT_EQ(s21_empty.top(), std_empty.top());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  s21_empty.pop();
  std_empty.pop();
  EXPECT_EQ(s21_empty.top(), std_empty.top());
  EXPECT_EQ(s21_empty.size(), std_empty.size());
  s21_empty.pop();
  std_empty.pop();
  EXPECT_EQ(s21_empty.size(), std_empty.size());
}

TEST_F(S21stackTest, Swap) {
  std::initializer_list<int> init_list = {1, 1, 3, 6};
  std::initializer_list<int> init_list_for_swap = {1, 3, 5, 5, 6, 7};
  s21::stack<int> s21_stack{init_list};
  s21::stack<int> s21_stack_for_swap{init_list_for_swap};

  std::stack<int> std_stack{init_list};
  std::stack<int> std_stack_for_swap{init_list_for_swap};

  s21_stack.swap(s21_stack_for_swap);
  std_stack.swap(std_stack_for_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack_for_swap.size(), std_stack_for_swap.size());
  while (!s21_stack.empty() && !std_stack.empty()) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }

  while (!s21_stack_for_swap.empty() && !std_stack_for_swap.empty()) {
    EXPECT_EQ(s21_stack_for_swap.top(), std_stack_for_swap.top());
    s21_stack_for_swap.pop();
    std_stack_for_swap.pop();
  }
}

// TEST_F(S21stackTest, EmplaceFront) {
//   s21_stack_emplace.push(Example(1, 2));
//   std_stack_emplace.push(Example(1, 2));
//   EXPECT_EQ(s21_stack_emplace.size(), std_stack_emplace.size());
//   EXPECT_EQ(s21_stack_emplace.top(), std_stack_emplace.top());
//   s21_stack_emplace.insert_many_front(4, 5);
//   std_stack_emplace.emplace(4, 5);
//   EXPECT_EQ(s21_stack_emplace.size(), std_stack_emplace.size());
//   EXPECT_EQ(s21_stack_emplace.top(), std_stack_emplace.top());
// }

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}