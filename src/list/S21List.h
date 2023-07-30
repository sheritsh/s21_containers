#ifndef S21LIST_H_
#define S21LIST_H_

#include <iostream>

template <class T>
class S21List {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  class Node;

 public:
  class iterator;
  class const_iterator;
  S21List();
  S21List(size_type size);
  S21List(size_type size, const_reference value);
  S21List(std::initializer_list<T> const &other);
  S21List(const S21List<T> &other);
  S21List(S21List<T> &&other);
  ~S21List();

  S21List &operator=(S21List<T> &&other);
  S21List<T> &operator=(S21List<T> &other);

  const_reference front() { return ghost_node_->pNext_->data_; }
  const_reference back() { return ghost_node_->pPast_->data_; }

  iterator begin() const;
  iterator end() const;
  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty() { return (ghost_node_->pNext_ == ghost_node_->pPast_); }
  size_type size();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value = T());
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(S21List<T> &other);
  void merge(S21List<T> &other);
  void splice(const_iterator pos, S21List<T> &other);
  void reverse();
  void unique();
  void sort() { *this = merge_sort(*this); }
  S21List<T> merge_sort(S21List<T> &other);
  void output();

 private:
  void create_ghost_node();

  Node *ghost_node_;
  size_type size_;
};

#endif  // S21LIST_H_