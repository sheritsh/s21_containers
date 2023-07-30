#ifndef CONTAINERS_SRC_S21_LINKED_LIST_STACK_H_
#define CONTAINERS_SRC_S21_LINKED_LIST_STACK_H_

#include <iostream>
#include <stdexcept>

#include "deque.h"

namespace s21 {
template <class T, class Container = deque<T>>
class Stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  Stack();
  Stack(std::initializer_list<value_type> const &items);
  Stack(const Stack &other);
  Stack(Stack &&other);
  ~Stack();

  const_reference top() const;
  bool empty() const;
  size_type size() const;
  void push(const_reference value);
  void pop();

  void swap(Stack &other);

  Stack &operator=(const Stack &other);
  Stack &operator=(Stack &&other) noexcept;

 private:
  Container deque;
};
}  // namespace s21
#include "stack.tpp"

#endif  // CONTAINERS_SRC_S21_LINKED_LIST_STACK_H_