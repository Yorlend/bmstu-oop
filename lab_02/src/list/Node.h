#pragma once

#include <memory>

template <typename T>
class Node
{
private:
    T data;
    std::shared_ptr<Node<T>> next;

public:
    explicit Node(const T& value);
    explicit Node(T&& value) noexcept;

    const T& getData() const noexcept;

    void setData(T&& value) noexcept;
    void setData(const T& value);
};

#include "list/Node.hpp"
