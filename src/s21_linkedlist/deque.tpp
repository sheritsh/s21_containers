namespace s21 {

template <class T>
deque<T>::deque() {
  list_.size = 0;
  list_.head = nullptr;
  list_.tail = nullptr;
}

template <class T>
deque<T>::deque(std::initializer_list<value_type> const &items) : deque() {
  for (auto i = items.begin(); i != items.end(); i++) push_back(*i);
}

template <class T>
deque<T>::deque(const deque &other) : deque() {
  Node *current = other.list_.head;
  while (current) {
    push_back(current->value);
    current = current->next;
  }
}

template <class T>
deque<T>::deque(deque &&other) {
  list_.size = other.list_.size;
  list_.head = other.list_.head;
  list_.tail = other.list_.tail;
  other.list_.size = 0;
  other.list_.head = nullptr;
  other.list_.tail = nullptr;
}

template <class T>
void deque<T>::swap(deque &other) {
  std::swap(list_.size, other.list_.size);
  std::swap(list_.head, other.list_.head);
  std::swap(list_.tail, other.list_.tail);
}

template <class T>
deque<T> &deque<T>::operator=(const deque &other) {
  if (this != &other) {
    while (!empty()) {
      pop_front();
    }
    Node *current = other.list_.head;
    while (current) {
      push_back(current->value);
      current = current->next;
    }
  }
  return *this;
}

template <class T>
deque<T> &deque<T>::operator=(deque &&other) noexcept {
  if (this != &other) {
    while (!empty()) {
      pop_front();
    }
    list_.size = other.list_.size;
    list_.head = other.list_.head;
    list_.tail = other.list_.tail;
    other.list_.size = 0;
    other.list_.head = nullptr;
    other.list_.tail = nullptr;
  }
  return *this;
}

template <class T>
deque<T>::~deque() {
  clear();
}

template <class T>
void deque<T>::clear() {
  while (!empty()) {
    pop_front();
  }
}

template <class T>
bool deque<T>::empty() const {
  return list_.head == nullptr;
}

template <class T>
typename deque<T>::size_type deque<T>::size() const {
  return list_.size;
}

template <class T>
const typename deque<T>::value_type &deque<T>::front() const {
  return list_.head->value;
}

template <class T>
const typename deque<T>::value_type &deque<T>::back() const {
  return list_.tail->value;
}

template <class T>
void deque<T>::push_front(const_reference data) {
  Node *tmp = new Node(data);
  tmp->next = list_.head;
  tmp->prev = nullptr;
  if (list_.head) {
    list_.head->prev = tmp;
  }
  list_.head = tmp;
  if (list_.tail == nullptr) {
    list_.tail = tmp;
  }
  ++list_.size;
}

template <class T>
void deque<T>::pop_front() {
  if (list_.head) {
    Node *tmp = list_.head;
    list_.head = list_.head->next;
    if (list_.head) {
      list_.head->prev = nullptr;
    } else {
      list_.tail = nullptr;
    }
    delete tmp;
    --list_.size;
  }
}

template <class T>
void deque<T>::push_back(const_reference data) {
  Node *tmp = new Node(data);
  tmp->prev = list_.tail;
  tmp->next = nullptr;
  if (list_.tail) {
    list_.tail->next = tmp;
  }
  list_.tail = tmp;
  if (list_.head == nullptr) {
    list_.head = tmp;
  }
  ++list_.size;
}

template <class T>
void deque<T>::pop_back() {
  if (list_.tail) {
    Node *tmp = list_.tail;
    list_.tail = list_.tail->prev;
    if (list_.tail) {
      list_.tail->next = nullptr;
    } else {
      list_.head = nullptr;
    }
    delete tmp;
    --list_.size;
  }
}

}  // namespace s21