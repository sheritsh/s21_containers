//
// Created by Oznak Banshee on 7/31/23.
//

#ifndef CONTAINERS_MAP_H
#define CONTAINERS_MAP_H

#include "AvlTree.h"

namespace s21 {
    template<typename Key, typename T>
    class map : public AVLTree<Key, T> {
    public:
        class MapIterator;
        class ConstMapIterator;

        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const key_type, mapped_type>;
        using reference = value_type &;
        using const_reference = const value_type &;
        using iterator = MapIterator;
        using const_iterator = ConstMapIterator;
        using size_type = size_t;

        map() : AVLTree<Key, T>() {};
        map(std::initializer_list<value_type> const &items);
        map(const map &other) : AVLTree<Key, T>(other) {};
        map(map &&other) noexcept: AVLTree<Key, T>(std::move(other)) {};
        map &operator=(map &&other) noexcept;
        map &operator=(const map &other);
        ~map() = default;

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;
        void merge(map &other);

        class MapIterator : public AVLTree<Key, T>::Iterator {
        public:
            friend class map;
            MapIterator() : AVLTree<Key, T>::Iterator() {};
            MapIterator(typename AVLTree<Key, T>::Node *node, typename AVLTree<Key, T>::Node *past_node = nullptr)
                    : AVLTree<Key, T>::Iterator(node, past_node = nullptr) {};
            value_type &operator*();
        protected:
            T &return_value();
        };

        class ConstMapIterator : public MapIterator {
        public:
            friend class map;
            ConstMapIterator() : MapIterator(){};
            ConstMapIterator(typename AVLTree<Key, T>::Node *node, typename AVLTree<Key, T>::Node *past_node = nullptr) : MapIterator(node, past_node = nullptr){};
            const_reference operator*() const {return MapIterator::operator*();};
        };

        T &at(const Key &key);
        T &operator[](const Key &key);
        std::pair<iterator, bool> insert(const value_type &value);
        std::pair<iterator, bool> insert(const Key &key, const T &obj);
        std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

    private:
        iterator find(const Key &key);
    };

}

#include "Map.tpp"

#endif //CONTAINERS_MAP_H