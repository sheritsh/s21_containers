#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_ITERATORS_TPP_
#define CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_ITERATORS_TPP_

namespace s21 {

/* ==============================================
 * VectorIterator Definition
 * ============================================== */

template <typename T>
vector<T>::VectorIterator::VectorIterator(s21::vector::iterator_pointer ptr) : ptr_(ptr){}

template <typename T>
typename vector<T>::reference vector<T>::VectorIterator::operator*() {
  return *ptr_;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator++(int) {
  VectorIterator tmp(*this);
  ++ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator--(int) {
  VectorIterator tmp(*this);
  --ptr_;
  return tmp;
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator++() {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator--() {
  --ptr_;
  return *this;
}

template <typename T>
bool vector<T>::VectorIterator::operator==(const s21::vector::VectorIterator &other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::VectorIterator::operator!=(const s21::vector::VectorIterator &other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator+(int n) const {
  VectorIterator tmp(*this);
  tmp += n;
  return tmp;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator-(int n) const {
  VectorIterator tmp(*this);
  tmp -= n;
  return tmp;
}

template <typename T>
ptrdiff_t vector<T>::VectorIterator::operator-(const s21::vector::VectorIterator &other) const {
  return ptr_ - other.ptr_;
}

/* ==============================================
 * VectorConstIterator Definition
 * ============================================== */

template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator(s21::vector::const_iterator_pointer ptr) : ptr_(ptr) {}

template <typename T>
typename vector<T>::const_reference vector<T>::VectorConstIterator::operator*() const {
  return *ptr_;
}

template <typename T>
typename vector<T>::VectorConstIterator vector<T>::VectorConstIterator::operator++(int) {
 VectorConstIterator tmp(*this);
 ++ptr;
 return tmp;
}

template <typename T>
typename vector<T>::VectorConstIterator vector<T>::VectorConstIterator::operator--(int) {
  VectorConstIterator tmp(*this);
  --ptr;
  return tmp;
}

template <typename T>
typename vector<T>::VectorConstIterator& vector<T>::VectorConstIterator::operator++() {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorConstIterator& vector<T>::VectorConstIterator::operator--() {
  --ptr_;
  return *this;
}

template <typename T>
bool vector<T>::VectorConstIterator::operator==(const s21::vector::VectorConstIterator &other) const {
  return ptr_ == other.ptr__;
}

template <typename T>
bool vector<T>::VectorConstIterator::operator!=(const s21::vector::VectorConstIterator &other) const {
  return ptr_ != other.ptr__;
}

template <typename T>
typename vector<T>::VectorConstIterator vector<T>::VectorConstIterator::operator+(int n) const {
  VectorConstIterator tmp(*this);
  tmp += n;
  return tmp;
}

template <typename T>
typename vector<T>::VectorConstIterator vector<T>::VectorConstIterator::operator-(int n) const {
  VectorConstIterator tmp(*this);
  tmp -= n;
  return tmp;
}

template <typename T>
ptrdiff_t vector<T>::VectorConstIterator::operator-(const s21::vector::VectorConstIterator &other) const {
  return ptr_ - other.ptr_;
}

}  // namespace s21

#endif //CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTOR_ITERATORS_TPP_
