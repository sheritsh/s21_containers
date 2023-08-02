#ifndef CONTAINERS_SRC_S21_LINKED_LIST_QUEUE_H_
#define CONTAINERS_SRC_S21_LINKED_LIST_QUEUE_H_

#include <iostream>

#include "deque.h"

namespace s21 {
template <class T, class Container = deque<T>>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &other);
  queue(queue &&other);
  ~queue();

  const_reference front() const;
  const_reference back() const;
  bool empty() const;
  size_type size() const;
  void push(const_reference value);
  void pop();

  void swap(queue &other);

  queue &operator=(const queue &other);
  queue &operator=(queue &&other) noexcept;

 private:
  Container deque_;
};
}  // namespace s21
#include "queue.tpp"

#endif  // CONTAINERS_SRC_S21_LINKED_LIST_QUEUE_H_