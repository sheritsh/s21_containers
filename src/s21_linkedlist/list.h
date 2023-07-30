#ifndef CONTAINERS_SRC_S21_LINKED_LIST_LIST_H_
#define CONTAINERS_SRC_S21_LINKED_LIST_LIST_H_

#include <iostream>
#include <stdexcept>

#include "deque.h"

namespace s21 {
template <class T>
class List : public deque<T> {
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

  List();
  List(size_type n);
  List(std::initializer_list<value_type> const &items);
  List(const List &other);
  List(List &&other);
  ~List() = default;

  size_type max_size();

  void push_front(const_reference data);
  void pop_front();
  void push_back(const_reference data);
  void pop_back();

  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void splice(const_iterator pos, List &other);
  void merge(List &other);
  void reverse();
  void unique();
  void sort();

  List &operator=(const List &other);
  List &operator=(List &&other) noexcept;

 private:
};
}  // namespace s21

#include "list.tpp"

#endif  // CONTAINERS_SRC_S21_LINKED_LIST_LIST_H_