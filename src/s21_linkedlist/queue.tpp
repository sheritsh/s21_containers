namespace s21 {
template <class T, class Container>
queue<T, Container>::queue() : deque() {}

template <class T, class Container>
queue<T, Container>::queue(std::initializer_list<value_type> const& items)
    : deque(items) {}

template <class T, class Container>
queue<T, Container>::queue(const queue& other) : deque(other.deque) {}

template <class T, class Container>
queue<T, Container>::queue(queue&& other) : deque(std::move(other.deque)) {}

template <class T, class Container>
queue<T, Container>::~queue() {}

template <class T, class Container>
void queue<T, Container>::swap(queue& other) {
  std::swap(deque, other.deque);
}

template <class T, class Container>
queue<T, Container>& queue<T, Container>::operator=(const queue& other) {
  if (this != &other) {
    deque = other.deque;
  }
  return *this;
}

template <class T, class Container>
queue<T, Container>& queue<T, Container>::operator=(queue&& other) noexcept {
  if (this != &other) {
    deque = std::move(other.deque);
  }
  return *this;
}

template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::front()
    const {
  return deque.front();
}

template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::back()
    const {
  return deque.back();
}

template <class T, class Container>
void queue<T, Container>::push(const_reference value) {
  deque.push_back(value);
}

template <class T, class Container>
void queue<T, Container>::pop() {
  deque.pop_front();
}

template <class T, class Container>
bool queue<T, Container>::empty() const {
  return deque.empty();
}

template <class T, class Container>
typename queue<T, Container>::size_type queue<T, Container>::size() const {
  return deque.size();
}
}  // namespace s21