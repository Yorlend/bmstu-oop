#pragma once

#include <iterator>
#include <memory>

template <typename T>
class Node;

template <typename T>
class List;

template <typename T>
class ListIterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    ListIterator() = default;
    ListIterator(const ListIterator& iter) = default;

    T* operator->();
    T& operator*();
    operator bool();

    ListIterator& operator++();
    bool operator!=(ListIterator const& other) const;

private:
    explicit ListIterator(const std::shared_ptr<Node<T>>& initNode);

    std::weak_ptr<Node<T>> node;

    friend class List<T>;
};

#include "Iterator.hpp"