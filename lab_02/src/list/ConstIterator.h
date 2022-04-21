#pragma once

#include <iterator>
#include <memory>

template <typename T>
class Node;

template <typename T>
class List;

template <typename T>
class ConstIterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    ConstIterator() = default;
    ConstIterator(const ConstIterator& iter) = default;

    const T* operator->();
    const T& operator*();
    operator bool();

    ConstIterator& operator++();
    bool operator!=(const ConstIterator& other) const;

private:
    explicit ConstIterator(const std::shared_ptr<Node<T>>& initNode);

    std::weak_ptr<Node<T>> node;

    friend class List<T>;
};

#include "ConstIterator.hpp"
