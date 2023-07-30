namespace s21 {

template <class T>
typename List<T>::iterator List<T>::begin() {
  return List<T>::begin();
}

template <class T>
typename List<T>::const_iterator List<T>::cbegin() const {
  return List<T>::cbegin();
}

template <class T>
typename List<T>::iterator List<T>::end() {
  return List<T>::end();
}

template <class T>
typename List<T>::const_iterator List<T>::cend() const {
  return List<T>::cend();
}

template <class T>
List<T>::List() : List<T>() {}

template <class T>
List<T>::List(size_type n) : List() {
  for (size_type i = 0; i < n; ++i) push_front(value_type());
}

template <class T>
List<T>::List(std::initializer_list<value_type> const& items)
    : List<T>(items) {}

template <class T>
List<T>::List(const List& other) : List<T>(other) {}

template <class T>
List<T>::List(List&& other) : List<T>(std::move(other)) {}

template <class T>
List<T>& List<T>::operator=(const List& other) {
  if (this != &other) {
    List<T>::operator=(other);
  }
  return *this;
}

template <class T>
List<T>& List<T>::operator=(List&& other) noexcept {
  if (this != &other) {
    List<T>::operator=(other);
  }
  return *this;
}

// template <class T>
// typename List<T>::const_reference List<T>::front() const {
//   return front();
// }

// template <class T>
// typename List<T>::const_reference List<T>::back() const {
//   return back();
// }

// template <class T>
// bool List<T>::empty() const {
//   return empty();
// }

// template <class T>
// typename List<T>::size_type List<T>::size() const {
//   return size();
// }

// template <class T>
// void List<T>::clear() {
//   clear();
// }

template <class T>
void List<T>::push_front(const_reference value) {
  deque<T>::push_front(value);
}

template <class T>
void List<T>::pop_front() {
  deque<T>::pop_front();
}

template <class T>
void List<T>::push_back(const_reference value) {
  deque<T>::push_back(value);
}

template <class T>
void List<T>::pop_back() {
  deque<T>::pop_back();
}

template <class T>
typename List<T>::iterator List<T>::insert(iterator pos,
                                           const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos = List<T>::list_.head;
  } else if (pos == end()) {
    push_back(value);
    pos = List<T>::list_.tail;
  } else {
    typename List<T>::Node* elem = pos.node_;
    typename List<T>::Node* convert = new typename List<T>::Node(value);
    convert->next = elem;
    convert->prev = elem->prev;
    elem->prev->next = convert;
    elem->prev = convert;
    this->list_.size++;
    return iterator(convert);
  }
  return pos;
}

}  // namespace s21