#ifndef CONTAINERS_SRC_S21_LINKED_LIST_LIST_H_
#define CONTAINERS_SRC_S21_LINKED_LIST_LIST_H_

#include <iostream>
#include <limits>
#include <stdexcept>

#include "deque.h"

namespace s21 {
template <class T>
class list : public deque<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  using iterator = typename deque<T>::iterator;
  using const_iterator = typename deque<T>::const_iterator;

  iterator begin();
  const_iterator cbegin() const;
  iterator end();
  const_iterator cend() const;

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
  typename deque<T>::Node *merge(typename deque<T>::Node *left,
                                 typename deque<T>::Node *right);
};
}  // namespace s21

#include "list.tpp"

#endif  // CONTAINERS_SRC_S21_LINKED_LIST_LIST_H_