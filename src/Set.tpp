//
// Created by Oznak Banshee on 7/28/23.
//


#include "Set.h"
namespace s21 {
    template<typename Key>
    set<Key>::set(const std::initializer_list<value_type> &items) {
        for (auto i = items.begin(); i != items.end(); ++i) {
            AVLTree<Key, Key>::insert(*i);
        }
    }

    template<typename Key>
    set<Key> &set<Key>::operator=(set &&other) noexcept {
        if (this != &other) {
            AVLTree<Key, Key>::operator=(std::move(other));
        }
        return *this;
    }

    template<typename Key>
    set<Key> &set<Key>::operator=(const set &other) {
        if (this != &other) {
            AVLTree<Key, Key>::operator=(other);
        }
        return *this;
    }
}