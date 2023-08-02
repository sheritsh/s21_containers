namespace s21 {
template <class T, class Container>
stack<T, Container>::stack() : deque_() {}

template <class T, class Container>
stack<T, Container>::stack(std::initializer_list<value_type> const& items) {
    for (auto i = items.begin(); i != items.end(); i++) push(*i);
}

template <class T, class Container>
stack<T, Container>::stack(const stack& other) : deque_(other.deque_) {}

template <class T, class Container>
stack<T, Container>::stack(stack&& other) : deque_(std::move(other.deque_)) {}

template <class T, class Container>
stack<T, Container>::~stack() {}

template <class T, class Container>
void stack<T, Container>::swap(stack& other) {
  std::swap(deque_, other.deque_);
}

template <class T, class Container>
stack<T, Container>& stack<T, Container>::operator=(const stack& other) {
  if (this != &other) {
    deque_ = other.deque_;
  }
  return *this;
}

template <class T, class Container>
stack<T, Container>& stack<T, Container>::operator=(stack&& other) noexcept {
  if (this != &other) {
    deque_ = std::move(other.deque_);
  }
  return *this;
}

template <class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() const {
  return deque_.front();
}

template <class T, class Container>
void stack<T, Container>::push(const_reference value) {
  deque_.push_front(value);
}

template <class T, class Container>
void stack<T, Container>::pop() {
  return deque_.pop_front();
}

template <class T, class Container>
bool stack<T, Container>::empty() const {
  return deque_.empty();
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
  return deque_.size();
}
}  // namespace s21