#ifndef CONTAINERS_SRC_S21_LINKED_LIST_LIST_H_
#define CONTAINERS_SRC_S21_LINKED_LIST_LIST_H_

#include <iostream>
#include <limits>

#include "deque.h"

namespace s21 {
template <class T>
class list : public deque<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  class ListIterator {
    friend class list<T>;

   public:
    ListIterator();
    ListIterator(typename deque<T>::Node *node);
    ListIterator(typename deque<T>::Node *node,
                 typename deque<T>::Node *last_node);

    reference operator*() const;
    value_type *operator->() const;
    ListIterator &operator++();
    ListIterator operator++(int);
    ListIterator &operator--();
    ListIterator operator--(int);
    bool operator==(const ListIterator &other) const;
    bool operator!=(const ListIterator &other) const;
    bool operator<(const ListIterator &other) const;
    bool operator<=(const ListIterator &other) const;
    bool operator>(const ListIterator &other) const;
    bool operator>=(const ListIterator &other) const;

   protected:
    typename deque<T>::Node *node_;
    typename deque<T>::Node *last_node_;
  };

  class ListConstIterator : public ListIterator {
   public:
    ListConstIterator();
    ListConstIterator(const ListIterator &node_);
    const_reference operator*() const;
  };

  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  const_iterator cbegin() const;
  const_iterator cend() const;
  iterator begin();
  iterator end();

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &other);
  list(list &&other);
  ~list() = default;

  size_type max_size();

  void push_front(const_reference data);
  void pop_front();
  void push_back(const_reference data);
  void pop_back();

  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void splice(const_iterator pos, list &other);
  void merge(list &other);
  void reverse();
  void unique();
  void sort();

  list &operator=(const list &other);
  list &operator=(list &&other) noexcept;

 private:
  typename deque<T>::Node *MergeSort(typename deque<T>::Node *head);
  typename deque<T>::Node *GetMiddle(typename deque<T>::Node *head);
  typename deque<T>::Node *Merge(typename deque<T>::Node *left,
                                 typename deque<T>::Node *right);
};
}  // namespace s21

#include "list.tpp"

#endif  // CONTAINERS_SRC_S21_LINKED_LIST_LIST_H_