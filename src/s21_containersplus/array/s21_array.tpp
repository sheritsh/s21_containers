#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_TPP
#define CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_TPP

namespace s21 {

template <typename T, std::size_t N>
array<T, N>::array() : size_(N) {}

template <typename T, std::size_t N>
array<T, N>::array(const std::initializer_list<value_type> &items) {
  std::copy(items.begin(), items.end(), elems_);
}

template <typename T, std::size_t N>
array<T, N>::array(const array<T, N> &a) {
  std::copy(a.elems_, a.elems_ + N, elems_);
}

template <typename T, std::size_t N>
array<T, N>::array(array<T, N> &&a) noexcept {
  std::move(a.elems_, a.elems_ + N, elems_);
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return elems_;
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return elems_ + size_;
}

template <typename T, std::size_t N>
typename array<T, N>::const_iterator array<T, N>::cbegin() const {
  return elems_;
}

template <typename T, std::size_t N>
typename array<T, N>::const_iterator array<T, N>::cend() const {
  return elems_ + size_;
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  return (*this)[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type pos) const {
  return (*this)[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::front() {
  return elems_[0];
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::back() {
  return elems_[N - 1];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
  return elems_[0];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
  return elems_[N - 1];
}

template <typename T, std::size_t N>
bool array<T, N>::empty() {
  return !size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return size();
}

template <typename T, std::size_t N>
void array<T, N>::swap(array<T, N> &a) {
  std::swap_ranges(elems_, elems_ + N, a.elems_);
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill(elems_, elems_ + N, value);
}

template <typename T, std::size_t N>
typename array<T, N>::array &array<T, N>::operator=(const array<T, N> &a) {
  std::copy(a.elems_, a.elems_ + N, elems_);

  return *this;
}

template <typename T, std::size_t N>
typename array<T, N>::array &array<T, N>::operator=(array<T, N> &&a) noexcept {
  for (size_t i = 0; i < N; ++i) {
    elems_[i] = std::move(a.elems_[i]);
  }

  return *this;
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("OutOfRangeError: Index out of array range");
  }

  return elems_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::operator[](
    size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range("OutOfRangeError: Index out of array range");
  }

  return elems_[pos];
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERSPLUS_ARRAY_S21_ARRAY_TPP
