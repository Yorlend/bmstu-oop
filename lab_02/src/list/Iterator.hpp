#pragma once

#include "Iterator.h"
#include "Node.h"
#include "exceptions/InvalidIteratorStateException.h"

template <typename T>
Iterator<T>::Iterator(const std::shared_ptr<Node<T>>& initNode) : node(initNode) {}

template <typename T>
T* Iterator<T>::operator->()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return node.lock()->getData();
}

template <typename T>
T& Iterator<T>::operator*()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return node.lock()->getData();
}

template <typename T>
Iterator<T>::operator bool()
{
    return node != nullptr;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    node = node.lock()->getNext();
    return *this;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const
{
    return node.lock() != other.node.lock();
}
