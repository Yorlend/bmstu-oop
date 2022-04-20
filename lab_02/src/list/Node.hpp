#pragma once

#include "Node.h"

template<typename T>
Node<T>::Node(const T& value) : data(value)
{
}

template<typename T>
Node<T>::Node(T&& value) noexcept : data(value)
{
}

template<typename T>
T& Node<T>::getData() noexcept
{
    return data;
}

template<typename T>
void Node<T>::setData(const T& value)
{
    data = value;
}

template<typename T>
void Node<T>::setData(T&& value) noexcept
{
    data = value;
}

template <typename T>
void Node<T>::setNext(std::shared_ptr<Node<T>> newNext)
{
    next = newNext;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::getNext() const
{
    return next;
}

template<typename T>
bool Node<T>::operator==(const Node& node) const
{
    return data == node.data;
}

template<typename T>
bool Node<T>::operator!=(const Node& node) const
{
    return data != node.data;
}
