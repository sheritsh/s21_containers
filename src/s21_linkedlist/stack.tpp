namespace s21 {
template <class T, class Container>
Stack<T, Container>::Stack() : deque() {}

template <class T, class Container>
Stack<T, Container>::Stack(std::initializer_list<value_type> const& items)
    : deque(items) {}

template <class T, class Container>
Stack<T, Container>::Stack(const Stack& other) : deque(other.deque) {}

template <class T, class Container>
Stack<T, Container>::Stack(Stack&& other) : deque(std::move(other.deque)) {}

template <class T, class Container>
Stack<T, Container>::~Stack() {}

template <class T, class Container>
void Stack<T, Container>::swap(Stack& other) {
  std::swap(deque, other.deque);
}

template <class T, class Container>
Stack<T, Container>& Stack<T, Container>::operator=(const Stack& other) {
  if (this != &other) {
    deque = other.deque;
  }
  return *this;
}

template <class T, class Container>
Stack<T, Container>& Stack<T, Container>::operator=(Stack&& other) noexcept {
  if (this != &other) {
    deque = std::move(other.deque);
  }
  return *this;
}

template <class T, class Container>
typename Stack<T, Container>::const_reference Stack<T, Container>::top() const {
  return deque.front();
}

template <class T, class Container>
void Stack<T, Container>::push(const_reference value) {
  deque.push_front(value);
}

template <class T, class Container>
void Stack<T, Container>::pop() {
  return deque.pop_front();
}

template <class T, class Container>
bool Stack<T, Container>::empty() const {
  return deque.empty();
}

template <class T, class Container>
typename Stack<T, Container>::size_type Stack<T, Container>::size() const {
  return deque.size();
}
}  // namespace s21