#pragma once

#include <ostream>
#include "BaseList.h"
#include "Node.h"

template <typename T>
class ListIterator;

template <typename T>
class ConstListIterator;

template <typename T>
class List : public BaseList
{
public:
    using iterator = ListIterator<T>;
    using const_iterator = ConstListIterator<T>;

    List() = default;

    explicit List(const List& list);
    List(List&& list) noexcept;
    List(const std::initializer_list<T>& init);
    template <typename Iter>
    List(Iter begin, Iter end);
    List(T* array, size_t size);

    List& operator=(const List& list);
    List& operator=(List&& list) noexcept;
    List& operator=(const std::initializer_list<T>& init);

    T* toArray();

    size_t size() const noexcept override;

    bool isEmpty() const noexcept override;

    void clear() noexcept override;

    void pushFront(const T& value);
    void pushFront(const List& list);

    void pushBack(const T& value);
    void pushBack(const List& list);

    void popFront();

    void popBack();

    void insert(const const_iterator& iter, const T& value);

    void remove(const const_iterator& iter);

    T extractHead();
    List extractHead(size_t count);

    T extractTail();
    List extractTail(size_t count);

    T& getHead();
    const T& getHead() const;

    T& getTail();
    const T& getTail() const;

    List sublist(size_t index) const;
    List sublist(size_t index, size_t count) const;

    List reverse() const;

    bool contains(const T& value) const noexcept;

    List operator+(const T& value) const;
    List operator+(const List& list) const;
    
    List& operator+=(const T& value);
    List& operator+=(const List& list);
    List& operator+=(const std::initializer_list<T>& init);

    bool operator==(const List& list) const noexcept;

    bool operator!=(const List& list) const noexcept;

    inline iterator begin() noexcept;
    inline const_iterator begin() const noexcept;
    inline const_iterator cbegin() const noexcept;
    
    inline iterator end() noexcept;
    inline const_iterator end() const noexcept;
    inline const_iterator cend() const noexcept;

private:
    std::shared_ptr<Node<T>> makeNode(const T& value) const;
    std::shared_ptr<Node<T>> getPrevNode(std::shared_ptr<Node<T>> node) const;

    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};

template <typename T>
List<T> operator+(const T& value, const List<T>& list);

template <typename T>
List<T> operator+(std::initializer_list<T> init, const List<T>& list);

template <typename T>
std::ostream& operator<<(std::ostream& stream, const List<T>& list);

#include "list/List.hpp"
