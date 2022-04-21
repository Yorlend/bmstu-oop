#pragma once

#include <iterator>
#include <memory>

template <typename T>
class Node;

template <typename T>
class List;

template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T> 
{
public:
    Iterator() = default;
    Iterator(const Iterator& iter) = default;

    T* operator->();
    T& operator*();
    operator bool();

    Iterator& operator++();
    bool operator!=(Iterator const& other) const;

private:
    explicit Iterator(const std::shared_ptr<Node<T>>& initNode);

    std::weak_ptr<Node<T>> node;

    friend class List<T>;
};

#include "Iterator.hpp"
