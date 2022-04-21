#pragma once

#include "ConstIterator.h"
#include "Node.h"
#include "exceptions/InvalidIteratorStateException.h"

template <typename T>
ConstIterator<T>::ConstIterator(const std::shared_ptr<Node<T>>& initNode) : node(initNode) {}

template <typename T>
const T* ConstIterator<T>::operator->()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return node.lock()->getData();
}

template <typename T>
const T& ConstIterator<T>::operator*()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    return node.lock()->getData();
}

template <typename T>
ConstIterator<T>::operator bool()
{
    return node != nullptr;
}

template <typename T>
ConstIterator<T>& ConstIterator<T>::operator++()
{
    if (node.expired())
        throw InvalidIteratorStateException(__FILE__, __LINE__);
    node = node.lock()->getNext();
    return *this;
}

template <typename T>
bool ConstIterator<T>::operator!=(const ConstIterator<T>& other) const
{
    return node.lock() != other.node.lock();
}
