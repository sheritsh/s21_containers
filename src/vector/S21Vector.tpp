#include "S21Vector.h"

template <class T>
void S21Vector<T>::clean() {
  delete[] data_;
  data_ = nullptr;
  size_ = capacity_ = 0;
}

template <class T>
void S21Vector<T>::clear() {
  for (size_t i = 0; i < size_; ++i) data_[i] = T();
  size_ = 0;
}

template <class T>
void S21Vector<T>::erase(iterator pos) {
  while (pos != end()) {
    *pos = *(pos + 1);
    ++pos;
  }
  --size_;
}

template <class T>
void S21Vector<T>::push_back(const T &value) {
  if (size_ >= capacity_) resize();
  data_[size_] = value;
  ++size_;
}

template <class T>
void S21Vector<T>::pop_back() {
  --size_;
  data_[size_] = T();
}

template <class T>
typename S21Vector<T>::iterator S21Vector<T>::begin() {
  iterator tmp(data_);
  return tmp;
}
template <class T>
typename S21Vector<T>::iterator S21Vector<T>::end() {
  iterator tmp(data_ + size_);
  return tmp;
}

template <class T>
typename S21Vector<T>::iterator S21Vector<T>::insert(iterator pos,
                                                     const T &value) {
  size_t i = pos.place_ - data_;
  if (size_ >= capacity_) resize();
  auto it = end();
  S21Vector<T>::iterator pos_now(data_ + i);
  while (it != pos_now) {
    *it = *(it - 1);
    --it;
  }
  *pos_now = value;
  ++size_;
  return pos_now;
}

template <class T>
void S21Vector<T>::reserve(size_t size) {
  S21Vector tmp(size);
  for (auto tmp_it = tmp.begin(), it = begin(); tmp_it != tmp.end();
       ++it, ++tmp_it) {
    *tmp_it = *it;
  }
  tmp.size_ = size_;
  swap(tmp);
}

template <class T>
T &S21Vector<T>::at(size_t i) {
  if (i < size_) return data_[i];
}

template <class T>
S21Vector<T> &S21Vector<T>::operator=(const S21Vector &other) {
  if (this == &other) return *this;
  clean();
  S21Vector<T> tmp(other);
  swap(tmp);
  return *this;
}

template <class T>
S21Vector<T> &S21Vector<T>::operator=(S21Vector &&other) noexcept {
  if (this == &other) return *this;
  clean();
  swap(other);
  return *this;
}

template <class T>
S21Vector<T>::S21Vector(S21Vector &&other)
    : data_(nullptr), size_(0), capacity_(0) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <class T>
S21Vector<T>::S21Vector(const S21Vector &other)
    : size_(other.size()), capacity_(other.size()) {
  data_ = new T[size_];
  for (size_t i = 0; i != other.size(); ++i) {
    data_[i] = other[i];
  }
}

template <class T>
S21Vector<T>::S21Vector(std::initializer_list<T> const &other)
    : size_(other.size()), capacity_(other.size()) {
  data_ = new T[size_];
  auto it = other.begin();
  for (size_t i = 0; it != other.end(); ++it, ++i) {
    data_[i] = *it;
  }
}

template <class T>
void S21Vector<T>::swap(S21Vector &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <class T>
void S21Vector<T>::resize() {
  T *data = new T[capacity_ * 2];
  for (size_t i = 0; i < size_; ++i) data[i] = data_[i];
  delete[] data_;
  data_ = data;
  capacity_ *= 2;
}

template <class T>
class S21Vector<T>::iterator {
 public:
  iterator(T *place) : place_(place) {}
  iterator operator+(size_t i) {
    iterator tmp(place_);
    tmp += i;
    return tmp;
  }
  iterator operator-(size_t i) {
    iterator tmp(place_);
    tmp -= i;
    return tmp;
  }
  iterator operator+=(size_t i) {
    place_ += i;
    return *this;
  }
  iterator operator-=(size_t i) {
    place_ -= i;
    return *this;
  }
  iterator operator++() {
    place_ += 1;
    return *this;
  }
  iterator operator--() {
    place_ -= 1;
    return *this;
  }
  iterator operator++(int) {
    iterator tmp(place_);
    place_ += 1;
    return tmp;
  }
  iterator operator--(int) {
    iterator tmp(place_);
    place_ -= 1;
    return tmp;
  }
  T &operator*() { return *place_; }
  T &operator[](size_t i) { return place_[i]; }
  bool operator!=(const iterator &other) const {
    return other.place_ != place_;
  }
  bool operator==(const iterator &other) const {
    return other.place_ == place_;
  }
  T *place_;
};