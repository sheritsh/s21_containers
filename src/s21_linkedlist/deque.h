#ifndef CONTAINERS_SRC_LINKEDLIST_H_
#define CONTAINERS_SRC_LINKEDLIST_H_

#include <iostream>

namespace s21 {

template <class T>
class list;

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
    Node(value_type val = value_type(), Node *next_node = nullptr, Node *prev_node = nullptr)
        : value(val), next(next_node), prev(prev_node) {}
  };

  struct _LinkedList {
    size_type size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
  };

  _LinkedList list_;

 public:
  class DequeIterator {
    friend deque;
    friend class list<T>;

   public:
    DequeIterator() = default;
    DequeIterator(Node *node_) : node_(node_) {}

    reference operator*() const { return node_->value; }

    value_type *operator->() const { return &node_->value; }

    DequeIterator &operator++() {
      node_ = node_->next;
      return *this;
    }

    DequeIterator operator++(int) {
      DequeIterator tmp = *this;
      node_ = node_->next;
      return tmp;
    }

    DequeIterator &operator--() {
      node_ = node_->prev;
      return *this;
    }

    DequeIterator operator--(int) {
      DequeIterator tmp = *this;
      node_ = node_->prev;
      return tmp;
    }

    bool operator==(const DequeIterator &other) { return node_ == other.node_; }

    bool operator!=(const DequeIterator &other) { return node_ != other.node_; }

    bool operator<(const DequeIterator &other) const {
      return node_ < other.node_;
    }

    bool operator>=(const DequeIterator &other) const {
      return node_ >= other.node_;
    }

   protected:
    Node *node_;
  };

  class DequeConstIterator : public DequeIterator {
   public:
    DequeConstIterator() : DequeIterator() {}
    DequeConstIterator(const DequeIterator &node_) : DequeIterator(node_) {}
    const_reference operator*() const { return DequeIterator::operator*(); }
  };

  using iterator = DequeIterator;
  using const_iterator = DequeConstIterator;

  const_iterator cbegin() const { return const_iterator(list_.head); }
  const_iterator cend() const { return const_iterator(list_.tail->next); }

  iterator begin() { return iterator(list_.head); }
  iterator end() { return iterator(list_.tail->next); }
};
}  // namespace s21
#include "deque.tpp"

#endif  // CONTAINERS_SRC_LINKEDLIST_H_