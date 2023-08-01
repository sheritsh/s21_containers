namespace s21 {
template <class T, class Container>
stack<T, Container>::stack() : deque() {}

template <class T, class Container>
stack<T, Container>::stack(std::initializer_list<value_type> const& items) {
    for (auto i = items.begin(); i != items.end(); i++) push(*i);
}

template <class T, class Container>
stack<T, Container>::stack(const stack& other) : deque(other.deque) {}

template <class T, class Container>
stack<T, Container>::stack(stack&& other) : deque(std::move(other.deque)) {}

template <class T, class Container>
stack<T, Container>::~stack() {}

template <class T, class Container>
void stack<T, Container>::swap(stack& other) {
  std::swap(deque, other.deque);
}

template <class T, class Container>
stack<T, Container>& stack<T, Container>::operator=(const stack& other) {
  if (this != &other) {
    deque = other.deque;
  }
  return *this;
}

template <class T, class Container>
stack<T, Container>& stack<T, Container>::operator=(stack&& other) noexcept {
  if (this != &other) {
    deque = std::move(other.deque);
  }
  return *this;
}

template <class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() const {
  return deque.front();
}

template <class T, class Container>
void stack<T, Container>::push(const_reference value) {
  deque.push_front(value);
}

template <class T, class Container>
void stack<T, Container>::pop() {
  return deque.pop_front();
}

template <class T, class Container>
bool stack<T, Container>::empty() const {
  return deque.empty();
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
  return deque.size();
}
}  // namespace s21