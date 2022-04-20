#pragma once

#include "List.h"
#include "Iterator.h"

template <typename T>
List<T>::List(std::initializer_list<T> init)
{
    for (auto value : init)
    {
        insertTail(value);
    }
}

template <typename T>
void List<T>::insertTail(const T& value)
{
    auto node = std::make_shared<Node<T>>(value);
    
    if (tail)
        tail->setNext(node);
    else
        head = node;

    tail = node;
}

template <typename T>
size_t List<T>::size() const noexcept
{
    return 0;
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
    return !head;
}

template <typename T>
void List<T>::clear() noexcept
{
    head.reset();
    tail.reset();
}

template <typename T>
typename List<T>::iterator List<T>::begin() noexcept
{
    return iterator(head);
}

template <typename T>
typename List<T>::iterator List<T>::end() noexcept
{
    return iterator(nullptr);
}
