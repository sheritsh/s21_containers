#ifndef CONTAINERS_SRC_S21_LINKED_LIST_QUEUE_H_
#define CONTAINERS_SRC_S21_LINKED_LIST_QUEUE_H_

#include <iostream>
#include <stdexcept>

#include "deque.h"

namespace s21 {
template <class T, class Container = deque<T>>
class Queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  Queue();
  Queue(std::initializer_list<value_type> const &items);
  Queue(const Queue &other);
  Queue(Queue &&other);
  ~Queue();

  const_reference front() const;
  const_reference back() const;
  bool empty() const;
  size_type size() const;
  void push(const_reference value);
  void pop();

  void swap(Queue &other);

  Queue &operator=(const Queue &other);
  Queue &operator=(Queue &&other) noexcept;

 private:
  Container deque;
};
}  // namespace s21
#include "queue.tpp"

#endif  // CONTAINERS_SRC_S21_LINKED_LIST_QUEUE_H_