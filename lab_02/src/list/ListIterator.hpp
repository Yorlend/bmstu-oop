#pragma once

#include "ListIterator.h"
#include "Node.h"
#include "exceptions/InvalidIteratorStateException.h"

template <typename T>
ListIterator<T>::ListIterator(const std::shared_ptr<Node<T>>& initNode) : node(initNode) {}

template <typename T>
T* ListIterator<T>::operator->()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return &node.lock()->getData();
}

template <typename T>
T& ListIterator<T>::operator*()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return node.lock()->getData();
}

template <typename T>
const T* ListIterator<T>::operator->() const
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return &node.lock()->getData();
}

template <typename T>
const T& ListIterator<T>::operator*() const
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return node.lock()->getData();
}

template <typename T>
ListIterator<T>::operator bool() const
{
    return node != nullptr;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    node = node.lock()->getNext();
    return *this;
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator<T>& other) const
{
    return node.lock() != other.node.lock();
}

template <typename T>
bool ListIterator<T>::operator==(const ListIterator<T>& other) const
{
    return node.lock() == other.node.lock();
}
