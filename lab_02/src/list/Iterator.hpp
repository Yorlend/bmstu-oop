#pragma once

#include "Iterator.h"
#include "Node.h"


template <typename T>
Iterator<T>::Iterator(const std::shared_ptr<Node<T>>& initNode) : node(initNode) {}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
    node = node.lock()->getNext();
    return *this;
}

template <typename T>
typename Iterator<T>::reference Iterator<T>::operator*() const
{
    return *node;
}

template <typename T>
bool Iterator<T>::operator!=(Iterator<T> const& other) const
{
    return node.lock() != other.node.lock();
}

template <typename T>
Iterator<T>::operator bool()
{
    return node != nullptr;
}

template <typename T>
T& Iterator<T>::operator*()
{
    return node.lock()->getData();
}

template <typename T>
T* Iterator<T>::operator->()
{
    return node.lock()->getData();
}
