namespace s21 {
template <class T, class Container>
Queue<T, Container>::Queue() : deque() {}

template <class T, class Container>
Queue<T, Container>::Queue(std::initializer_list<value_type> const& items)
    : deque(items) {}

template <class T, class Container>
Queue<T, Container>::Queue(const Queue& other) : deque(other.deque) {}

template <class T, class Container>
Queue<T, Container>::Queue(Queue&& other) : deque(std::move(other.deque)) {}

template <class T, class Container>
Queue<T, Container>::~Queue() {}

template <class T, class Container>
void Queue<T, Container>::swap(Queue& other) {
  std::swap(deque, other.deque);
}

template <class T, class Container>
Queue<T, Container>& Queue<T, Container>::operator=(const Queue& other) {
  if (this != &other) {
    deque = other.deque;
  }
  return *this;
}

template <class T, class Container>
Queue<T, Container>& Queue<T, Container>::operator=(Queue&& other) noexcept {
  if (this != &other) {
    deque = std::move(other.deque);
  }
  return *this;
}

template <class T, class Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::front()
    const {
  return deque.front();
}

template <class T, class Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::back()
    const {
  return deque.back();
}

template <class T, class Container>
void Queue<T, Container>::push(const_reference value) {
  deque.push_back(value);
}

template <class T, class Container>
void Queue<T, Container>::pop() {
  deque.pop_front();
}

template <class T, class Container>
bool Queue<T, Container>::empty() const {
  return deque.empty();
}

template <class T, class Container>
typename Queue<T, Container>::size_type Queue<T, Container>::size() const {
  return deque.size();
}
}  // namespace s21