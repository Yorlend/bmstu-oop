#pragma once

#include "ConstListIterator.h"
#include "Node.h"
#include "exceptions/InvalidIteratorStateException.h"

template <typename T>
ConstListIterator<T>::ConstListIterator(const std::shared_ptr<Node<T>>& initNode) : node(initNode) {}

template <typename T>
const T* ConstListIterator<T>::operator->() const
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return node.lock()->getData();
}

template <typename T>
const T& ConstListIterator<T>::operator*() const
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return node.lock()->getData();
}

template <typename T>
ConstListIterator<T>::operator bool()
{
    return node != nullptr;
}

template <typename T>
ConstListIterator<T>& ConstListIterator<T>::operator++()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    node = node.lock()->getNext();
    return *this;
}

template <typename T>
bool ConstListIterator<T>::operator!=(const ConstListIterator<T>& other) const
{
    return node.lock() != other.node.lock();
}

template <typename T>
bool ConstListIterator<T>::operator==(const ConstListIterator& other) const
{
    return node.lock() == other.node.lock();
}