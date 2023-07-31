//
// Created by Oznak Banshee on 7/31/23.
//

#ifndef CONTAINERS_MAP_H
#define CONTAINERS_MAP_H

#include "AvlTree.h"

template<typename Key, typename T>
class Map : public AVLTree<Key, T> {
public:
    class MapIterator;

    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const key_type, mapped_type>;
    using reference = value_type &;
    using const_reference = const value_type &;
    using iterator = MapIterator;
    using const_iterator = typename AVLTree<Key, T>::ConstIterator;
    using size_type = size_t;

    Map() : AVLTree<Key, T>(){};
//    Set(std::initializer_list<value_type> const &items);
    Map(const Map &other) : AVLTree<Key, T>(other){};
    Map(Map &&other) noexcept : AVLTree<Key, T>(std::move(other)){};
    Map& operator=(Map &&other) noexcept;
    Map& operator=(const Map &other);
    ~Map() = default;

    class MapIterator : AVLTree<Key, T>::Iterator {
    public:
        MapIterator() : AVLTree<Key, T>::Iterator() {};
        MapIterator(typename AVLTree<Key, T>::Node* node, typename AVLTree<Key, T>::Node* past_node = nullptr) : AVLTree<Key, T>::Iterator(node, past_node = nullptr) {};
        value_type& operator*();
    };

    std::pair<iterator, bool> Insert(const value_type& value);
    std::pair<iterator, bool> Insert(const Key& key, const T& obj);


    iterator Find(const Key& key);
};



#endif //CONTAINERS_MAP_H
