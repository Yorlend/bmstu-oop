#pragma once

#include "BaseList.h"
#include "Node.h"

template <typename T>
class Iterator;

template <typename T>
class List : public BaseList
{
public:
    using iterator = Iterator<T>;
    // using const_iterator = const_list_iterator<T>;

    List() = default;

    explicit List(const List& list);
    explicit List(List&& list) noexcept;
    explicit List(std::initializer_list<T> init);

    void insertHead(const T& value);
    void insertHead(const List& list);

    void insertTail(const T& value);
    void insertTail(const List& list);

    void insert(const T& value, size_t position);
    void insert(const List& list, size_t position);

    size_t size() const noexcept override;
    bool isEmpty() const noexcept override;

    void clear() noexcept override;

    inline iterator begin() noexcept;
    // inline const_iterator begin() noexcept;
    // inline const_iterator cbegin() noexcept;
    
    inline iterator end() noexcept;
    // inline const_iterator end() noexcept;
    // inline const_iterator cend() noexcept;


private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};

#include "list/List.hpp"
