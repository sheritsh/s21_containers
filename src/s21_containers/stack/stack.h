#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_STACK_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_STACK_H_

#include <iostream>

#include "../deque/deque.h"

namespace s21 {
template <class T, class Container = deque<T>>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &other);
  stack(stack &&other);
  ~stack();

  const_reference top() const;
  bool empty() const;
  size_type size() const;
  void push(const_reference value);
  void pop();

  void swap(stack &other);

  template <class... Args>
  void insert_many_front(Args &&...args);

  stack &operator=(const stack &other);
  stack &operator=(stack &&other) noexcept;

 private:
  Container deque_;
};
}  // namespace s21
#include "stack.tpp"

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_STACK_STACK_H_