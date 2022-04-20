#pragma once

#include <memory>

template <typename T>
class Node
{
public:
    explicit Node(const T& value);
    explicit Node(T&& value) noexcept;


    T& getData() noexcept;

    void setData(T&& value) noexcept;
    void setData(const T& value);

    void setNext(std::shared_ptr<Node<T>> newNext);

    std::shared_ptr<Node> getNext() const;

    bool operator==(const Node& node) const;
    bool operator!=(const Node& node) const;

private:
    T data;
    std::shared_ptr<Node> next;
};

#include "list/Node.hpp"
