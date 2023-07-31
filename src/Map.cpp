//
// Created by Oznak Banshee on 7/31/23.
//

#include "Map.h"

int main() {

    Map<int, int> mp;
    mp.Insert(1,2);
    Map<int, int>::MapIterator it;
    it = mp.Find(1);

}


template<typename Key, typename T>
Map<Key, T> &Map<Key, T>::operator=(Map &&other) noexcept {
    if (this != &other) {
        AVLTree<Key, T>::operator=(std::move(other));
    }
    return *this;
}

template<typename Key, typename T>
Map<Key, T> &Map<Key, T>::operator=(const Map &other) {
    if (this != &other) {
        AVLTree<Key, T>::operator=(other);
    }
    return *this;
}

template<typename Key, typename T>
std::pair<typename Map<Key, T>::iterator, bool> Map<Key, T>::Insert(const value_type &value) {
    return Insert(value.first, value.second);
}


template<typename Key, typename T>
std::pair<typename Map<Key, T>::iterator, bool> Map<Key, T>::Insert(const Key &key, const T& obj) {
    std::pair<iterator, bool> return_value;
    if (AVLTree<Key, T>::root_ == nullptr) {
        AVLTree<Key, T>::root_ = new typename AVLTree<Key, T>::Node(key, obj);
        return_value.first = iterator(AVLTree<Key, T>::root_);
        return_value.second = true;
    } else {
        bool check_insert = AVLTree<Key, T>::RecursiveInsert(AVLTree<Key, T>::root_, key, obj);
        return_value.first = Find(key); // НАДО НАПИСАТЬ ФУНКЦИЮ FIND
        return_value.second = check_insert;
    }
    return return_value;
}

template<typename Key, typename T>
typename Map<Key, T>::value_type &Map<Key, T>::MapIterator::operator*() {
    if (AVLTree<Key, T>::Iterator::iter_node_ == nullptr) {
        return 0;
    }
    std::pair<const Key, T> pr = 0;
    pr.first = AVLTree<Key, T>::Iterator::iter_node_.key_;
    pr.second = AVLTree<Key, T>::Iterator::iter_node_.value_;
    return pr;
}


template<typename Key, typename T>
typename Map<Key, T>::iterator Map<Key, T>::Find(const Key &key) {
    typename AVLTree<Key, T>::Node* node = AVLTree<Key, T>::RecursiveFind(AVLTree<Key, T>::root_, key);
    return iterator(node);
}