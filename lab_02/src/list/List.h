#pragma once

#include "BaseList.h"
#include "Node.h"

template <typename T>
class List : public BaseList
{
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

public:
    List() = default;

    explicit List(const List& list);
    explicit List(List&& list) noexcept;
    explicit List(const T& value);
    explicit List(T&& value);
    explicit List(std::initializer_list<T> init);

    void insertHead(const T& value);
    void insertHead(const List& list);

    void insertTail(const T& value);
    void insertTail(const List& list);

    void insert(const T& value, size_t position);
    void insert(const List& list, size_t position);
};

#include "list/List.hpp"
