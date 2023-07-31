namespace s21 {

template <class T>
typename List<T>::iterator List<T>::begin() {
  return deque<T>::begin();
}

template <class T>
typename List<T>::const_iterator List<T>::cbegin() const {
  return deque<T>::cbegin();
}

template <class T>
typename List<T>::iterator List<T>::end() {
  return deque<T>::end();
}

template <class T>
typename List<T>::const_iterator List<T>::cend() const {
  return deque<T>::cend();
}

template <class T>
List<T>::List() : deque<T>() {}

template <class T>
List<T>::List(size_type n) : List() {
  for (size_type i = 0; i < n; ++i) push_front(value_type());
}

template <class T>
List<T>::List(std::initializer_list<value_type> const& items)
    : deque<T>(items) {}

template <class T>
List<T>::List(const List& other) : deque<T>(other) {}

template <class T>
List<T>::List(List&& other) : deque<T>(std::move(other)) {}

template <class T>
List<T>& List<T>::operator=(const List& other) {
  std::cout << "-List Copy-\n";
  if (this != &other) {
    deque<T>::operator=(other);
  }
  return *this;
}

template <class T>
List<T>& List<T>::operator=(List&& other) noexcept {
  std::cout << "-List Move-\n";
  if (this != &other) {
    deque<T>::operator=(std::move(other));
  }
  return *this;
}

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
void List<T>::sort() {
  this->list_.head = mergeSort(this->list_.head);
  this->list_.tail = this->list_.head;
  while (this->list_.tail->next != nullptr) {
    this->list_.tail = this->list_.tail->next;
  }
}

template <class T>
typename deque<T>::Node* List<T>::MergeSort(typename deque<T>::Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  typename deque<T>::Node* middle = getMiddle(head);
  typename deque<T>::Node* nextOfMiddle = middle->next;
  middle->next = nullptr;
  typename deque<T>::Node* left = mergeSort(head);
  typename deque<T>::Node* right = mergeSort(nextOfMiddle);
  return merge(left, right);
}

template <class T>
typename deque<T>::Node* List<T>::GetMiddle(typename deque<T>::Node* head) {
  typename deque<T>::Node* slow = head;
  typename deque<T>::Node* fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

template <class T>
typename deque<T>::Node* List<T>::merge(typename deque<T>::Node* left,
                                        typename deque<T>::Node* right) {
  typename deque<T>::Node* result = nullptr;
  if (left == nullptr) {
    return right;
  } else if (right == nullptr) {
    return left;
  }
  if (left->value <= right->value) {
    result = left;
    result->next = merge(left->next, right);
  } else {
    result = right;
    result->next = merge(left, right->next);
  }
  return result;
}

template <class T>
void List<T>::merge(List& other) {
  if (this != &other) {
    iterator it_this = begin();
    iterator it_other = other.begin();
    while (!other.empty()) {
      if (it_this == end() || *it_this > *it_other) {
        insert(it_this, *it_other);
        other.erase(it_other);
        ++it_other;
      } else {
        ++it_this;
      }
    }
  }
}

template <class T>
void List<T>::splice(const_iterator pos, List& other) {
  for (iterator it = other.begin(); it != other.end(); ++it) {
    insert(pos, *it);
  }
}

template <class T>
void List<T>::reverse() {
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
void List<T>::unique() {
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

template <class T>
typename List<T>::size_type List<T>::max_size() {
  return std::numeric_limits<size_type>::max() /
         sizeof(typename deque<T>::Node) / 2;
}

template <class T>
typename List<T>::iterator List<T>::insert(iterator pos,
                                           const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos = this->list_.head;
  } else if (pos == end()) {
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
void List<T>::erase(iterator pos) {
  if (pos == begin()) {
    pop_front();
  } else if (pos.node_ == this->list_.tail) {
    pop_back();
  } else {
    typename List<T>::Node* node = pos.node_;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    this->list_.size--;
  }
}

}  // namespace s21