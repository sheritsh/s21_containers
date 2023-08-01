#ifndef CONTAINERS_SRC_LINKEDLIST_H_
#define CONTAINERS_SRC_LINKEDLIST_H_

#include <iostream>

namespace s21 {

template <class T>
class deque {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  deque();
  ~deque();
  deque(std::initializer_list<value_type> const &items);
  deque(const deque &other);
  deque(deque &&other);

  void push_front(const_reference data);
  void pop_front();
  void push_back(const_reference data);
  void pop_back();

  const_reference front() const;
  const_reference back() const;

  bool empty() const;
  size_type size() const;

  void swap(deque &other);

  void clear();

  deque &operator=(const deque &other);
  deque &operator=(deque &&other) noexcept;

 protected:
  struct Node {
    value_type value;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(value_type val = value_type(), Node *next_node = nullptr,
         Node *prev_node = nullptr)
        : value(val), next(next_node), prev(prev_node) {}
  };

  struct LinkedList {
    size_type size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
  };

  LinkedList list_;
};
}  // namespace s21
#include "deque.tpp"

#endif  // CONTAINERS_SRC_LINKEDLIST_H_