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
const T& Node<T>::getData() const noexcept
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
