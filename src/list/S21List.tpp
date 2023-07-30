#include "S21List.h"

template <class T>
S21List<T>::S21List() : ghost_node_(nullptr), size_(0) {
  create_ghost_node();
}

template <class T>
S21List<T>::S21List(size_type size) : ghost_node_(nullptr), size_(0) {
  create_ghost_node();
  while (size > 0) {
    push_back();
    --size;
  }
}

template <class T>
S21List<T>::S21List(size_type size, const_reference value)
    : ghost_node_(nullptr), size_(0) {
  create_ghost_node();
  while (size > 0) {
    push_back(value);
    --size;
  }
}
template <class T>
S21List<T>::S21List(std::initializer_list<T> const &other)
    : ghost_node_(nullptr), size_(0) {
  create_ghost_node();
  auto it = other.begin();
  for (; it < other.end(); ++it) push_back(*it);
}

template <class T>
S21List<T>::S21List(const S21List<T> &other) : ghost_node_(nullptr), size_(0) {
  create_ghost_node();
  S21List<T>::iterator it = other.begin();
  for (; it != other.end(); ++it) {
    push_back(*it);
  }
}

template <class T>
S21List<T>::S21List(S21List<T> &&other)
    : ghost_node_(nullptr), size_(other.size_) {
  create_ghost_node();
  ghost_node_->pNext_ = other.ghost_node_->pNext_;
  ghost_node_->pPast_ = other.ghost_node_->pPast_;
  other.ghost_node_->pNext_ = other.ghost_node_->pPast_ = other.ghost_node_;
  ghost_node_->pNext_->pPast_ = ghost_node_->pPast_->pNext_ = ghost_node_;
  other.size_ = 0;
}

template <class T>
S21List<T>::~S21List() {
  clear();
  delete ghost_node_;
}

template <class T>
void S21List<T>::push_back(const_reference value) {
  Node *tmp = ghost_node_->pPast_;
  ghost_node_->pPast_ = new Node(value, tmp, ghost_node_);
  ghost_node_->pPast_->pPast_->pNext_ = ghost_node_->pPast_;
  ++size_;
}

template <class T>
void S21List<T>::pop_back() {
  if (ghost_node_->pPast_ != ghost_node_) {
    Node *tmp = ghost_node_->pPast_;
    tmp->pPast_->pNext_ = ghost_node_;
    ghost_node_->pPast_ = tmp->pPast_;
    delete tmp;
    --size_;
  }
}

template <class T>
void S21List<T>::output() {
  Node *tmp = ghost_node_;
  for (size_type i = 0; i <= size_; ++i) {
    std::cout << tmp->data_ << "  ";
    std::cout << tmp->pPast_ << "  ";
    std::cout << tmp->pNext_ << "  ";
    std::cout << tmp << std::endl;
    tmp = tmp->pNext_;
  }
}

template <class T>
size_t S21List<T>::size() {
  return size_;
}

template <class T>
void S21List<T>::clear() {
  while (size_ > 0) {
    pop_back();
  }
}

template <class T>
void S21List<T>::create_ghost_node() {
  ghost_node_ = new Node();
  ghost_node_->pNext_ = ghost_node_->pPast_ = ghost_node_;
}

template <class T>
S21List<T> &S21List<T>::operator=(S21List<T> &&other) {
  if (this == &other) return *this;
  clear();
  size_ = other.size_;
  ghost_node_->pNext_ = other.ghost_node_->pNext_;
  ghost_node_->pPast_ = other.ghost_node_->pPast_;
  other.ghost_node_->pNext_ = other.ghost_node_->pPast_ = other.ghost_node_;
  ghost_node_->pNext_->pPast_ = ghost_node_->pPast_->pNext_ = ghost_node_;
  other.size_ = 0;
  return *this;
}

template <class T>
S21List<T> &S21List<T>::operator=(S21List<T> &other) {
  if (this == &other) return *this;
  S21List<T> tmp(other);
  *this = std::move(tmp);
  return *this;
}

template <class T>
typename S21List<T>::iterator S21List<T>::insert(iterator pos,
                                                 const_reference value) {
  Node *tmp = new Node(value, pos.node_->pPast_, pos.node_);
  tmp->pPast_->pNext_ = tmp->pNext_->pPast_ = tmp;
  ++size_;
  auto it(tmp);
  return it;
}

template <class T>
void S21List<T>::erase(iterator pos) {
  if (pos != ghost_node_) {
    pos.node_->pPast_->pNext_ = pos.node_->pNext_;
    pos.node_->pNext_->pPast_ = pos.node_->pPast_;
    delete pos.node_;
    --size_;
  }
}

template <class T>
void S21List<T>::push_front(const_reference value) {
  auto it = begin();
  insert(it, value);
}

template <class T>
void S21List<T>::pop_front() {
  auto it = begin();
  erase(it);
}

template <class T>
void S21List<T>::swap(S21List<T> &other) {
  std::swap(ghost_node_, other.ghost_node_);
  std::swap(size_, other.size_);
}

template <class T>
void S21List<T>::merge(S21List<T> &other) {
  if (this != &other) {
    auto it1 = begin();
    auto it2 = other.begin();
    while (it2 != other.end()) {
      if (it1.node_->data_ > it2.node_->data_ || it1 == end()) {
        insert(it1, it2.node_->data_);
        ++it2;
      } else {
        ++it1;
      }
    }
    other.clear();
  }
}

template <class T>
void S21List<T>::reverse() {
  auto it = begin();
  while (it != end()) {
    std::swap(it.node_->pPast_, it.node_->pNext_);
    --it;
  }
  std::swap(ghost_node_->pNext_, ghost_node_->pPast_);
}

template <class T>
void S21List<T>::unique() {
  auto it = begin();
  ++it;
  while (it != end()) {
    if (it.node_->pPast_->data_ == it.node_->data_) {
      auto tmp_it(it.node_->pNext_);
      erase(it);
      it = tmp_it;
    } else {
      ++it;
    }
  }
}

template <class T>
void S21List<T>::splice(const_iterator pos, S21List<T> &other) {
  auto other_it = other.cbegin();
  auto this_it(pos.node_);
  while (other_it != other.end()) {
    insert(this_it, other_it.node_->data_);
    ++other_it;
  }
  other.clear();
}

template <class T>
S21List<T> S21List<T>::merge_sort(S21List<T> &other) {
  S21List<T> left;
  S21List<T> right;
  auto it = other.begin();
  for (size_type i = 0; it != other.end(); ++i, ++it) {
    if (i < (other.size() / 2)) {
      left.push_back(it.node_->data_);
    } else {
      right.push_back(it.node_->data_);
    }
  }
  if (left.size() > 1) left = merge_sort(left);
  if (right.size() > 1) right = merge_sort(right);
  left.merge(right);
  return left;
}

template <class T>
typename S21List<T>::iterator S21List<T>::begin() const {
  iterator it(ghost_node_->pNext_);
  return it;
}

template <class T>
typename S21List<T>::iterator S21List<T>::end() const {
  iterator it(ghost_node_);
  return it;
}

template <class T>
typename S21List<T>::const_iterator S21List<T>::cbegin() const {
  const_iterator it(ghost_node_->pNext_);
  return it;
}

template <class T>
typename S21List<T>::const_iterator S21List<T>::cend() const {
  const_iterator it(ghost_node_);
  return it;
}

template <class T>
class S21List<T>::Node {
 public:
  Node(T date = T(), Node *pPast = nullptr, Node *pNext = nullptr) {
    pPast_ = pPast;
    data_ = date;
    pNext_ = pNext;
  }
  Node *pNext_;
  Node *pPast_;
  T data_;
};

template <class T>
class S21List<T>::iterator {
 public:
  iterator() : node_(nullptr) {}
  iterator(Node *node) : node_(node) {}
  iterator(const iterator &other) : node_(other.node_) {}
  iterator &operator=(const iterator &other) {
    node_ = other.node_;
    return *this;
  }
  iterator &operator=(iterator &&other) {
    node_ = other.node_;
    other.node_ = nullptr;
    return *this;
  }
  iterator &operator++() {
    node_ = node_->pNext_;
    return *this;
  }
  iterator &operator++(int) {
    iterator tmp(node_);
    node_ = node_->pNext_;
    return tmp;
  }
  iterator &operator--() {
    node_ = node_->pPast_;
    return *this;
  }
  iterator &operator--(int) {
    iterator tmp(node_);
    node_ = node_->pPast_;
    return tmp;
  }
  bool operator==(const iterator &other) { return (node_ == other.node_); }
  bool operator!=(const iterator &other) { return (node_ != other.node_); }
  reference operator*() { return node_->data_; }
  Node *node_;
};

template <class T>
class S21List<T>::const_iterator {
 public:
  const_iterator() : node_(nullptr) {}
  const_iterator(Node *node) : node_(node) {}
  const_iterator(const iterator &other) : node_(other.node_) {}
  const_iterator &operator=(const iterator &other) {
    node_ = other.node_;
    return *this;
  }
  const_iterator &operator=(iterator &&other) {
    node_ = other.node_;
    other.node_ = nullptr;
    return *this;
  }
  const_iterator &operator++() {
    node_ = node_->pNext_;
    return *this;
  }
  const_iterator &operator++(int) {
    iterator tmp(node_);
    node_ = node_->pNext_;
    return tmp;
  }
  const_iterator &operator--() {
    node_ = node_->pPast_;
    return *this;
  }
  const_iterator &operator--(int) {
    iterator tmp(node_);
    node_ = node_->pPast_;
    return tmp;
  }
  bool operator==(const iterator &other) { return (node_ == other.node_); }
  bool operator!=(const iterator &other) { return (node_ != other.node_); }
  const_reference operator*() { return node_->data_; }
  Node *node_;
};
