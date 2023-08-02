#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_H
#define CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_H

#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class vector {
 public:
  class VectorIterator;
  class VectorConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator_pointer = T *;
  using const_iterator_pointer = const T *;
  using iterator = vector<T>::VectorIterator;
  using const_iterator = vector<T>::VectorConstIterator;
  using size_type = size_t;

  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v) noexcept;
  ~vector();
  vector& operator=(vector &&v) noexcept;

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  iterator_pointer data() noexcept;

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector& other);

 private:
  iterator_pointer data_;
  size_type size_;
  size_type capacity_;
};
}  // namespace s21

#include "s21_vector.tpp"
#include "s21_vector_iterators.h"

#endif //CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_H
