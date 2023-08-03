namespace s21 {

template <class T>
list<T>::ListIterator::ListIterator(){};

template <class T>
list<T>::ListIterator::ListIterator(typename deque<T>::Node* node)
    : node_(node) {}

template <class T>
list<T>::ListIterator::ListIterator(typename deque<T>::Node* node,
                                    typename deque<T>::Node* last_node)
    : node_(node), last_node_(last_node) {}

template <class T>
typename list<T>::reference list<T>::ListIterator::operator*() const {
  return node_->value;
}

template <class T>
typename list<T>::value_type* list<T>::ListIterator::operator->() const {
  return &node_->value;
}

template <class T>
typename list<T>::ListIterator& list<T>::ListIterator::operator++() {
  last_node_ = node_;
  node_ = node_->next;
  return *this;
}

template <class T>
typename list<T>::ListIterator list<T>::ListIterator::operator++(int) {
  ListIterator it = *this;
  node_ = node_->next;
  return it;
}

template <class T>
typename list<T>::ListIterator& list<T>::ListIterator::operator--() {
  if (node_ == nullptr) {
    node_ = last_node_;
  } else {
    node_ = node_->prev;
  }
  return *this;
}

template <class T>
typename list<T>::ListIterator list<T>::ListIterator::operator--(int) {
  ListIterator it = *this;
  node_ = node_->prev;
  return it;
}

template <class T>
bool list<T>::ListIterator::operator==(const ListIterator& other) const {
  return node_ == other.node_;
}

template <class T>
bool list<T>::ListIterator::operator!=(const ListIterator& other) const {
  return node_ != other.node_;
}

template <class T>
bool list<T>::ListIterator::operator<(const ListIterator& other) const {
  return node_ < other.node_;
}

template <class T>
bool list<T>::ListIterator::operator<=(const ListIterator& other) const {
  return node_ <= other.node_;
}

template <class T>
bool list<T>::ListIterator::operator>(const ListIterator& other) const {
  return node_ > other.node_;
}

template <class T>
bool list<T>::ListIterator::operator>=(const ListIterator& other) const {
  return node_ >= other.node_;
}

template <class T>
list<T>::ListConstIterator::ListConstIterator() : ListIterator() {}

template <class T>
list<T>::ListConstIterator::ListConstIterator(const ListIterator& node_)
    : ListIterator(node_) {}

template <class T>
typename list<T>::const_reference list<T>::ListConstIterator::operator*()
    const {
  return ListIterator::operator*();
}

template <class T>
typename list<T>::iterator list<T>::begin() {
  return iterator(this->list_.head);
}

template <class T>
typename list<T>::iterator list<T>::end() {
  return this->list_.head ? iterator(this->list_.tail->next, this->list_.tail)
                          : begin();
}

template <class T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(this->list_.head);
}

template <class T>
typename list<T>::const_iterator list<T>::cend() const {
  return const_iterator(this->list_.tail->next, this->list_.tail);
}

template <class T>
list<T>::list() : deque<T>() {}

template <class T>
list<T>::list(size_type n) : list() {
  if (n > 0)
    for (size_type i = 0; i < n; ++i) push_front(value_type());
}

template <class T>
list<T>::list(std::initializer_list<value_type> const& items)
    : deque<T>(items) {}

template <class T>
list<T>::list(const list& other) : deque<T>(other) {}

template <class T>
list<T>::list(list&& other) : deque<T>(std::move(other)) {}

template <class T>
list<T>& list<T>::operator=(const list& other) {
  if (this != &other) {
    deque<T>::operator=(other);
  }
  return *this;
}

template <class T>
list<T>& list<T>::operator=(list&& other) noexcept {
  if (this != &other) {
    deque<T>::operator=(std::move(other));
  }
  return *this;
}

template <class T>
void list<T>::push_front(const_reference value) {
  deque<T>::push_front(value);
}

template <class T>
void list<T>::pop_front() {
  deque<T>::pop_front();
}

template <class T>
void list<T>::push_back(const_reference value) {
  deque<T>::push_back(value);
}

template <class T>
void list<T>::pop_back() {
  deque<T>::pop_back();
}

template <class T>
void list<T>::sort() {
  this->list_.head = MergeSort(this->list_.head);
  this->list_.tail = this->list_.head;
  while (this->list_.tail->next != nullptr) {
    this->list_.tail = this->list_.tail->next;
  }
}

template <class T>
typename deque<T>::Node* list<T>::MergeSort(typename deque<T>::Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  typename deque<T>::Node* middle = GetMiddle(head);
  typename deque<T>::Node* nextOfMiddle = middle->next;
  middle->next = nullptr;
  typename deque<T>::Node* left = MergeSort(head);
  typename deque<T>::Node* right = MergeSort(nextOfMiddle);
  return Merge(left, right);
}

template <class T>
typename deque<T>::Node* list<T>::GetMiddle(typename deque<T>::Node* head) {
  typename deque<T>::Node* slow = head;
  typename deque<T>::Node* fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

template <class T>
typename deque<T>::Node* list<T>::Merge(typename deque<T>::Node* left,
                                        typename deque<T>::Node* right) {
  typename deque<T>::Node* result = nullptr;
  if (left == nullptr) {
    return right;
  } else if (right == nullptr) {
    return left;
  }
  if (left->value <= right->value) {
    result = left;
    result->next = Merge(left->next, right);
  } else {
    result = right;
    result->next = Merge(left, right->next);
  }
  return result;
}

template <class T>
void list<T>::merge(list& other) {
  if (this != &other) {
    iterator it_this = begin();
    iterator it_other = other.begin();
    while (!other.empty()) {
      if (this->empty()) {
        insert(it_this, *it_other);
        other.erase(it_other);
        ++it_other;
      } else {
        if (it_this == end() || *it_other < *it_this) {
          insert(it_this, *it_other);
          other.erase(it_other);
          ++it_other;
        } else {
          ++it_this;
        }
      }
    }
  }
}

template <class T>
void list<T>::splice(const_iterator pos, list& other) {
  if (!other.empty()) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
      insert(pos, *it);
    }
  }
}

template <class T>
void list<T>::reverse() {
  if (this->list_.size > 1) {
    typename deque<T>::Node* node = this->list_.head;
    for (size_type i = 0; i < this->list_.size; ++i) {
      std::swap(node->prev, node->next);
      node = node->prev;
    }
    std::swap(this->list_.head, this->list_.tail);
  }
}

template <class T>
void list<T>::unique() {
  if (!this->empty()) {
    for (iterator it_last = begin(); it_last != end();) {
      iterator it_next = it_last;
      ++it_next;
      if (it_next.node_ == nullptr) {
        return;
      } else if (*it_last == *it_next) {
        erase(it_next);
      } else {
        ++it_last;
      }
    }
  }
}

template <class T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<size_type>::max() /
         sizeof(typename deque<T>::Node) / 2;
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos = this->list_.head;
  } else if (pos == this->end()) {
    push_back(value);
    pos = this->list_.tail;
  } else {
    typename deque<T>::Node* current = pos.node_;
    typename deque<T>::Node* blank = new typename deque<T>::Node(value);
    blank->next = current;
    blank->prev = current->prev;
    current->prev->next = blank;
    current->prev = blank;
    this->list_.size++;
    return iterator(blank);
  }
  return pos;
}

template <class T>
void list<T>::erase(iterator pos) {
  if (pos == begin()) {
    pop_front();
  } else if (pos.node_ == this->list_.tail) {
    pop_back();
  } else {
    typename list<T>::Node* node = pos.node_;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    this->list_.size--;
  }
}

template <class T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  for (const auto& arg : {args...}) {
    insert(pos, arg);
  }
  return pos;
}

template <class T>
template <class... Args>
void list<T>::insert_many_back(Args&&... args) {
  for (const auto& arg : {args...}) {
    push_back(arg);
  }
}

template <class T>
template <class... Args>
void list<T>::insert_many_front(Args&&... args) {
  for (const auto& arg : {args...}) {
    push_front(arg);
  }
}

}  // namespace s21