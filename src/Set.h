//
// Created by Oznak Banshee on 7/28/23.
//

#ifndef CONTAINERS_SET_H
#define CONTAINERS_SET_H

#include "AvlTree.h"

template<typename Key>
class Set : public AVLTree<Key, Key> {
public:
    
    using key_type = Key;
    using value_type = Key;
    using reference = value_type &;
    using const_reference = const Key &;
    using iterator = typename AVLTree<Key, Key>::Iterator;
    using const_iterator = typename AVLTree<Key, Key>::ConstIterator;
    using size_type = size_t;

    Set() : AVLTree<Key, Key>(){};
    Set(std::initializer_list<value_type> const &items);
    Set(const Set &other) : AVLTree<Key, Key>(other){};
    Set(Set &&other) noexcept : AVLTree<Key, Key>(std::move(other)){};
    Set& operator=(Set &&other) noexcept;
    Set& operator=(const Set &other);

    iterator Find(const Key& key) {AVLTree<Key, Key>::Find(key);};

    ~Set() = default;

};



#endif //CONTAINERS_SET_H
