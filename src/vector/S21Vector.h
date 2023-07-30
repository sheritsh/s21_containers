#ifndef S21VECTOR_H_
#define S21VECTOR_H_

#include <iostream>

template <class T>
class S21Vector {
 public:
  class iterator;
  S21Vector() : data_(nullptr), size_(0), capacity_(0) {}
  S21Vector(size_t n) : size_(n), capacity_(n) { data_ = new T[size_]; }
  S21Vector(std::initializer_list<T> const &other);
  S21Vector(const S21Vector &other);
  S21Vector(S21Vector &&other);
  ~S21Vector() { clean(); };

  S21Vector<T> &operator=(S21Vector &&other) noexcept;
  S21Vector<T> &operator=(const S21Vector &other);

  T &at(size_t i);
  T &operator[](size_t i) { return data_[i]; }
  const T &operator[](size_t i) const { return data_[i]; }
  const T &front() { return data_[0]; }
  const T &back() { return data_[size_ - 1]; }
  T *data() { return data_; }

  iterator begin();
  iterator end();

  bool empty() { return size_ == 0; }
  size_t size() const { return size_; }
  void reserve(size_t size);
  size_t capacity() const { return capacity_; }
  void shrink_to_fit() { reserve(size_); }

  void clear();
  iterator insert(iterator pos, const T &value);
  void erase(iterator pos);
  void push_back(const T &value);
  void pop_back();
  void swap(S21Vector &other);

 private:
  void resize();
  void clean();

  T *data_;
  size_t size_;
  size_t capacity_;
};

#endif  // S21VECTOR_H_