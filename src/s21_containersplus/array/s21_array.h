#ifndef CPP2_S21_CONTAINERS_1_S21_ARRAY_H
#define CPP2_S21_CONTAINERS_1_S21_ARRAY_H

#include <iostream>
#include <limits>

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a) noexcept;
  ~array() = default;

  iterator begin();
  iterator end();
  const_iterator cbegin(void) const;
  const_iterator cend(void) const;

  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference front();
  reference back();
  const_reference front() const;
  const_reference back() const;

  bool empty();
  size_type size();
  size_type max_size();

  void swap(array &a);
  void fill(const_reference value);

  array &operator=(const array &a);
  array &operator=(array &&a) noexcept;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

 private:
  value_type elems_[N] = {};
  size_type size_ = N;
};

}  // namespace s21

#include "s21_array.tpp"

#endif  // CPP2_S21_CONTAINERS_1_S21_ARRAY_H
