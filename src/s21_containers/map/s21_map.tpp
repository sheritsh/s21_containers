//
// Created by Oznak Banshee on 7/31/23.
//

namespace s21 {

template <typename Key, typename T>
map<Key, T>::map(const std::initializer_list<value_type> &items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    insert(*i);
  }
}

template <typename Key, typename T>
map<Key, T> &map<Key, T>::operator=(map &&other) noexcept {
  if (this != &other) {
    AVLTree<Key, T>::operator=(std::move(other));
  }
  return *this;
}

template <typename Key, typename T>
map<Key, T> &map<Key, T>::operator=(const map &other) {
  if (this != &other) {
    AVLTree<Key, T>::operator=(other);
  }
  return *this;
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type &value) {
  return insert(value.first, value.second);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key &key, const T &obj) {
  std::pair<iterator, bool> return_value;
  if (AVLTree<Key, T>::root_ == nullptr) {
    AVLTree<Key, T>::root_ = new typename AVLTree<Key, T>::Node(key, obj);
    return_value.first = iterator(AVLTree<Key, T>::root_);
    return_value.second = true;
  } else {
    bool check_insert =
        AVLTree<Key, T>::RecursiveInsert(AVLTree<Key, T>::root_, key, obj);
    return_value.first = find(key);  // НАДО НАПИСАТЬ ФУНКЦИЮ FIND
    return_value.second = check_insert;
  }
  return return_value;
}

template <typename Key, typename T>
typename map<Key, T>::value_type &map<Key, T>::MapIterator::operator*() {
  if (AVLTree<Key, T>::Iterator::iter_node_ == nullptr) {
    static value_type fake_value{};
    return fake_value;
  }
  std::pair<const key_type, mapped_type> pr =
      std::make_pair(AVLTree<Key, T>::Iterator::iter_node_->key_,
                     AVLTree<Key, T>::Iterator::iter_node_->value_);
  std::pair<const key_type, mapped_type> &ref = pr;
  return ref;
}

template <typename Key, typename T>
T &map<Key, T>::MapIterator::return_value() {
  if (AVLTree<Key, T>::Iterator::iter_node_ == nullptr) {
    static T fake_value{};
    return fake_value;
  }
  return AVLTree<Key, T>::Iterator::iter_node_->value_;
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::find(const Key &key) {
  typename AVLTree<Key, T>::Node *node =
      AVLTree<Key, T>::RecursiveFind(AVLTree<Key, T>::root_, key);
  return iterator(node);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key &key, const T &obj) {
  auto it = find(key);
  if (it != this->end()) {
    erase(it);
    auto pr = insert(key, obj);
    pr.second = false;
    return pr;
  }
  return insert(key, obj);
}

template <typename Key, typename T>
template <class... Args>
std::vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::insert_many(Args &&...args) {
  std::vector<std::pair<typename map<Key, T>::iterator, bool>> vec;
  for (const auto &arg : {args...}) {
    vec.push_back(insert(arg));
  }
  return vec;
}

template <typename Key, typename T>
T &map<Key, T>::at(const Key &key) {
  auto it = find(key);
  if (it == nullptr)
    throw std::out_of_range(
        "Container does not have an element with the specified key");
  return it.return_value();
}

template <typename Key, typename T>
T &map<Key, T>::operator[](const Key &key) {
  auto it = find(key);
  if (it == nullptr) {
    auto pr = insert(std::make_pair(key, T()));
    it = pr.first;
  }
  return it.return_value();
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  return map<Key, T>::MapIterator(
      AVLTree<Key, T>::GetMin(AVLTree<Key, T>::root_));
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
  if (AVLTree<Key, T>::root_ == nullptr) return begin();

  typename AVLTree<Key, T>::Node *last_node =
      AVLTree<Key, T>::GetMax(AVLTree<Key, T>::root_);
  MapIterator test(nullptr, last_node);
  return test;
}

template <typename Key, typename T>
typename map<Key, T>::const_iterator map<Key, T>::cbegin() const {
  return map<Key, T>::ConstMapIterator(
      AVLTree<Key, T>::GetMin(AVLTree<Key, T>::root_));
}

template <typename Key, typename T>
typename map<Key, T>::const_iterator map<Key, T>::cend() const {
  if (AVLTree<Key, T>::root_ == nullptr) return cbegin();

  typename AVLTree<Key, T>::Node *last_node =
      AVLTree<Key, T>::GetMax(AVLTree<Key, T>::root_);
  ConstMapIterator test(nullptr, last_node);
  return test;
}

template <typename Key, typename T>
void map<Key, T>::merge(map &other) {
  map const_tree(other);
  iterator const_it = const_tree.begin();
  for (; const_it != const_tree.end(); ++const_it) {
    auto key = (*const_it).first;
    auto obj = (*const_it).second;
    std::pair<iterator, bool> pr = insert(key, obj);
    if (pr.second) other.erase(pr.first);
  }
}

template <typename Key, typename T>
void map<Key, T>::erase(map::iterator pos) {
  if (AVLTree<Key, T>::root_ == nullptr || pos.iter_node_ == nullptr) return;
  AVLTree<Key, T>::root_ =
      AVLTree<Key, T>::RecursiveDelete(AVLTree<Key, T>::root_, (*pos).first);
}
}  // namespace s21
