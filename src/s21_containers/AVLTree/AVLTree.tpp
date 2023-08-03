//
// Created by Oznak Banshee on 7/14/23.
//

#include "AVLTree.h"

#include <sys/types.h>
#include <sys/sysctl.h>


// КОНСТРУКТОРЫ ДЛЯ ДЕРЕВА / ДЕСТРУКТОР / ОПЕРАТОРЫ

template<typename Key, typename Value>
AVLTree<Key, Value>::AVLTree() : root_(nullptr) {}


template<typename Key, typename Value>
AVLTree<Key, Value>::AVLTree(const AVLTree &other) {
    root_ = CopyTree(other.root_, nullptr);
}

template<typename Key, typename Value>
AVLTree<Key, Value>::AVLTree(AVLTree &&other) noexcept {
    root_ = other.root_;
    other.root_ = nullptr;
}

template<typename Key, typename Value>
AVLTree<Key, Value>::~AVLTree() {
    clear();
}

template<typename Key, typename Value>
AVLTree<Key, Value> &AVLTree<Key, Value>::operator=(AVLTree &&other) noexcept {
    if (this != &other) {
        root_ = other.root_;
        other.root_ = nullptr;
    }
    return *this;
}

template<typename Key, typename Value>
AVLTree<Key, Value> &AVLTree<Key, Value>::operator=(const AVLTree &other) {
    if (this != &other) {
        AVLTree temp(other);
        FreeNode(root_);
        *this = std::move(temp);
    }
    return *this;
}

// BEGIN AND END

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator AVLTree<Key, Value>::begin() {
    return AVLTree::Iterator(GetMin(root_));
}

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator AVLTree<Key, Value>::end() {
    if (root_ == nullptr) return begin();

    Node* last_node = GetMax(root_);
    Iterator test(nullptr, last_node);
    return test;
}

// SIZE

template<typename Key, typename Value>
bool AVLTree<Key, Value>::empty() {
    return root_ == nullptr;
}

template<typename Key, typename Value>
size_t AVLTree<Key, Value>::size() {
    return RecursiveSize(root_);
}

template<typename Key, typename Value>
size_t AVLTree<Key, Value>::max_size() {
    return std::numeric_limits<size_type>::max() /
           sizeof(typename AVLTree<Key, Value>::Node);
}


// INSERT and DELETE and CLEAR

template<typename Key, typename Value>
void AVLTree<Key, Value>::clear() {
    if (root_ != nullptr) FreeNode(root_);
    root_ = nullptr;
}

template<typename Key, typename Value>
std::pair<typename AVLTree<Key,Value>::Iterator, bool> AVLTree<Key, Value>::insert(const Key& key) { // Обычный инсерт обертка для основной вставки с алгоритмом, и возвращаемые значения по таску
    std::pair<Iterator, bool> return_value;
    if (root_ == nullptr) {
        root_ = new Node(key, key);
        return_value.first = Iterator(root_);
        return_value.second = true;
    } else {
        bool check_insert = RecursiveInsert(root_, key, key);
        return_value.first = Find(key); // НАДО НАПИСАТЬ ФУНКЦИЮ FIND
        return_value.second = check_insert;
    }
    return return_value;
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::erase(iterator pos) {
    if (root_ == nullptr || pos.iter_node_ == nullptr) return;
    root_ = RecursiveDelete(root_, *pos);
}


// SWAP AND MERGE

template<typename Key, typename Value>
void AVLTree<Key, Value>::swap(AVLTree &other) {
    std::swap(root_, other.root_);
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::merge(AVLTree &other) {
    AVLTree const_tree(other);
    Iterator const_it = const_tree.begin();
//    Iterator it = other.begin();
    for (; const_it != const_tree.end(); ++const_it) {
        std::pair<Iterator, bool> pr = insert(*const_it);
        if (pr.second) other.erase(pr.first);
    }
}

// FIND AND CONTAINS

template<typename Key, typename Value>
typename AVLTree<Key, Value>::iterator AVLTree<Key, Value>::Find(const Key &key) {
    Node* exact_node = RecursiveFind(root_, key);
    return Iterator(exact_node);
}

template<typename Key, typename Value>
bool AVLTree<Key, Value>::contains(const Key &key) {
    Node* contain_node = RecursiveFind(root_, key);
    return !(contain_node == nullptr);
}

// ITERATOR

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node *AVLTree<Key, Value>::Iterator::MoveForward(AVLTree::Node *node)  {
    if (node->right_ != nullptr) {
        return GetMin(node->right_);
    }
    Node* parent = node->parent_;
    while (parent != nullptr && node == parent->right_) {
        node = parent;
        parent = parent->parent_;
    }
    return parent;
}

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node *AVLTree<Key, Value>::Iterator::MoveBack(AVLTree::Node *node)  {
    if (node->left_ != nullptr) {
        return GetMax(node->left_);
    }
    Node* parent = node->parent_;
    while (parent != nullptr && node == parent->left_) {
        node = parent;
        parent = node->parent_;
    }
    return parent;
}

template<typename Key, typename Value>
AVLTree<Key, Value>::Iterator::Iterator() : iter_node_(nullptr), iter_past_node_(nullptr) {}

template<typename Key, typename Value>
AVLTree<Key, Value>::Iterator::Iterator(AVLTree::Node *node, AVLTree::Node *past_node) : iter_node_(node), iter_past_node_(past_node) {}

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator& AVLTree<Key, Value>::Iterator::operator++() {
    Node* tmp;
    if (iter_node_ != nullptr) {
        tmp = GetMax(iter_node_);
    }
    iter_node_ = MoveForward(iter_node_);
    if (iter_node_ == nullptr) {
        iter_past_node_ = tmp;
    }
    return *this;
}

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator AVLTree<Key, Value>::Iterator::operator++(int) {
    Iterator temp = *this;
    operator++();
    return temp;
}


template<typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator& AVLTree<Key, Value>::Iterator::operator--() {
    if (iter_node_ == nullptr && iter_past_node_ != nullptr) {
        *this = iter_past_node_;
        return *this;
    }
    iter_node_ = MoveBack(iter_node_);
    return *this;
}

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator AVLTree<Key, Value>::Iterator::operator--(int) {
    Iterator temp = *this;
    operator--();
    return temp;
}


template<typename Key, typename Value>
Value& AVLTree<Key, Value>::Iterator::operator*() {
    if (iter_node_ == nullptr) {
        static Value fake_value{};
        return fake_value;
    }
    return iter_node_->key_; // тут было value - изменил из-за мапы
}

template<typename Key, typename Value>
bool AVLTree<Key, Value>::Iterator::operator==(const AVLTree::Iterator &it) {
    return iter_node_ == it.iter_node_;
}

template<typename Key, typename Value>
bool AVLTree<Key, Value>::Iterator::operator!=(const AVLTree::Iterator &it) {
    return iter_node_ != it.iter_node_;
}


//SUPPORT


// КОНСРУКТОР ДЛЯ УЗЛОВ

template<typename Key, typename Value>
AVLTree<Key, Value>::Node::Node(Key key, value_type value)  : key_(key), value_(value) {}

template<typename Key, typename Value>
AVLTree<Key, Value>::Node::Node(Key key, value_type value, Node* node) : key_(key), value_(value), parent_(node) {}

// SUPPORT FOR AVL_TREE CONSTRUCTORS

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node *AVLTree<Key, Value>::CopyTree(AVLTree::Node *node, AVLTree::Node *parent) { // АЛГОРИТМ КОПИРОВАНИЯ
    if (node == nullptr) return nullptr;
    Node *new_node = new Node(node->key_, node->value_, parent);
    new_node->left_ = CopyTree(node->left_, new_node);
    new_node->right_ = CopyTree(node->right_, new_node);
    return new_node;
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::FreeNode(Node* node) { // РЕКУРСИЯ ДЛЯ УДАЛЕНИЯ
    if (node == nullptr) return;
    FreeNode(node->left_);
    FreeNode(node->right_);
    delete node;
}

// AVL BALANCE

template<typename Key, typename Value>
int AVLTree<Key, Value>::GetHeight(AVLTree::Node *node) {
    return node == nullptr ? -1 : node->height_; // У несуществуюшей ноды высота по правилам -1 иначе мы возьмем высоту у существуюшей ноды
}

template<typename Key, typename Value>
int AVLTree<Key, Value>::GetBalance(AVLTree::Node *node) {
    return node == nullptr ? 0 : GetHeight(node->right_)  - GetHeight(node->left_); // У несуществуюшей ноды баланс фактор по правилам 0 иначе мы считаем баланс по формуле
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::SetHeight(AVLTree::Node *node) {
    node->height_ = std::max(GetHeight(node->left_), GetHeight(node->right_)) + 1; // вычисление высоты для существующей ноды
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::SwapValue(AVLTree::Node *a, AVLTree::Node *b) { // Свап только значений
    std::swap(a->key_, b->key_);
    std::swap(a->value_, b->value_);
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::RightRotate(AVLTree::Node *node) {
    Node * new_left = node->left_->left_;
    Node * new_right_right = node->right_;
    Node * new_right_left = node->left_->right_;

    SwapValue(node, node->left_);
    node->right_ = node->left_;

    node->left_ = new_left;
    if (node->left_) {
        node->left_->parent_ = node;
    }

    node->right_->left_ = new_right_left;
    if (node->right_->left_) {
        node->right_->left_->parent_ = node->right_;
    }

    node->right_->right_ = new_right_right;
    if (node->right_->right_) {
        node->right_->right_->parent_ = node->right_;
    }

    SetHeight(node->right_);
    SetHeight(node);
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::LeftRotate(AVLTree::Node *node) {
    Node * new_right = node->right_->right_;
    Node * new_left_left = node->left_;
    Node * new_left_right = node->right_->left_;

    SwapValue(node, node->right_);
    node->left_ = node->right_;

    node->right_ = new_right;
    if (node->right_) {
        node->right_->parent_ = node;
    }

    node->left_->right_ = new_left_right;
    if (node->left_->right_)  {
        node->left_->right_->parent_ = node->left_;
    }

    node->left_->left_ = new_left_left;
    if (node->left_->left_)  {
        node->left_->left_->parent_  = node->left_;
    }

    SetHeight(node->left_);
    SetHeight(node);
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::Balance(Node *node) { // правила балансировки чтобы понять какой вид поворота нужен
    int balance = GetBalance(node);
    if (balance == -2) {
        if(GetBalance(node->left_) == 1) LeftRotate(node->left_);
        RightRotate(node);
    } else if (balance == 2) {
        if(GetBalance(node->right_) == -1) RightRotate(node->right_);
        LeftRotate(node);
    }
}

// MIN AND MAX IN TREE

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node *AVLTree<Key, Value>::GetMin(AVLTree::Node *node) {
    if (node == nullptr) return nullptr;
    if (node->left_ == nullptr) return node;
    return GetMin(node->left_);
}

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node *AVLTree<Key, Value>::GetMax(AVLTree::Node *node) {
    if (node == nullptr) return nullptr;
    if (node->right_ == nullptr) return node;
    return GetMax(node->right_);
}

// RECURSIVE SUPPORT FUNCTIONS

template<typename Key, typename Value>
size_t AVLTree<Key, Value>::RecursiveSize(AVLTree::Node *node) {
    if (node == nullptr) return 0;
    size_t left_size = RecursiveSize(node->left_);
    size_t right_size = RecursiveSize(node->right_);
    return 1 + left_size + right_size;
}


template<typename Key, typename Value>
bool AVLTree<Key, Value>::RecursiveInsert(AVLTree::Node *node, const Key& key, Value value) { // Рекурсивная вставка в дерево с добавленной логикой понимания произошла ли вставка на самом деле, возвращает также указатель на ноду
    bool check_insert = false;
    if (key < node->key_) {
        if (node->left_ == nullptr) {
            node->left_ = new Node(key, value, node);
            check_insert = true;
        } else {
            check_insert = RecursiveInsert(node->left_, key, value);
        }
    } else if (key > node->key_) {
        if (node->right_ == nullptr) {
            node->right_ = new Node(key, value, node);
            check_insert = true;
        } else {
            check_insert = RecursiveInsert(node->right_, key, value);
        }
    } else if (key == node->key_) {
        return check_insert; // инсерт не произошел потому что такой ключ был в дереве
    }
    SetHeight(node);
    Balance(node);
    return check_insert;
}

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::RecursiveDelete(AVLTree::Node *node, Key key) {
    if (node == nullptr) return nullptr;
    if (key < node->key_) {
        node->left_ = RecursiveDelete(node->left_, key);
    } else if (key > node->key_) {
        node->right_ = RecursiveDelete(node->right_, key);
    } else {
        if (node->left_ == nullptr || node->right_ == nullptr) {
            Node* node_right = node->right_;
            Node* node_left = node->left_;
            Node* node_parent = node->parent_;
            delete node;
            if (node_left == nullptr) {
                node = node_right;
            } else {
                node = node_left;
            }
            if (node != nullptr) node->parent_ = node_parent;
        } else {
            Node* min_in_right = GetMin(node->right_);
            node->key_ = min_in_right->key_;
            node->value_ = min_in_right->value_;
            node->right_ = RecursiveDelete(node->right_, min_in_right->key_);
        }
    }
    if (node != nullptr) {
        SetHeight(node);
        Balance(node);
    }
    return node;
}

template<typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::RecursiveFind(AVLTree::Node *node, const Key &key) {
    if (node == nullptr || node->key_ == key) return node;
    if (key > node->key_) {
        return RecursiveFind(node->right_, key);
    } else {
        return RecursiveFind(node->left_, key);
    }
}

