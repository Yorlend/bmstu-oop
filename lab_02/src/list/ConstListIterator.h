#pragma once

#include <iterator>
#include <memory>

template <typename T>
class Node;

template <typename T>
class List;

template <typename T>
class ListIterator;

template <typename T>
class ConstListIterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    ConstListIterator() = default;
    ConstListIterator(const ConstListIterator& iter) = default;
    ConstListIterator(const ListIterator<T>& iter);

    const T* operator->() const;
    const T& operator*() const;

    operator bool() const;

    ConstListIterator& operator++();
    bool operator!=(const ConstListIterator& other) const;
    bool operator==(const ConstListIterator& other) const;

private:
    explicit ConstListIterator(const std::shared_ptr<Node<T>>& initNode);

    std::shared_ptr<Node<T>> getNode() const;

    std::weak_ptr<Node<T>> node;

    friend class List<T>;
};

#include "ConstListIterator.hpp"
