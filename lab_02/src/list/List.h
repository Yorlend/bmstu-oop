#pragma once

#include <ostream>
#include "BaseList.h"
#include "Node.h"

template <typename T>
class Iterator;

template <typename T>
class ConstIterator;

template <typename T>
class List : public BaseList
{
public:
    using iterator = Iterator<T>;
    using const_iterator = ConstIterator<T>;

    List() = default;

    explicit List(const List& list);
    List(List&& list) noexcept;
    List(std::initializer_list<T> init);
    template <typename Iter>
    List(Iter begin, Iter end);

    List& operator=(const List& list);
    List& operator=(List&& list) noexcept;

    void insertHead(const T& value);
    void insertHead(const List& list);

    void insertTail(const T& value);
    void insertTail(const List& list);

    void insert(const T& value, size_t position);
    void insert(const List& list, size_t position);

    void removeHead();
    void removeHead(size_t count);

    void removeTail();
    void removeTail(size_t count);

    void remove(size_t index);
    void remove(size_t index, size_t count);

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

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    List operator+(const T& value) const;
    List operator+(const List& list) const;

    List& operator+=(const T& value);
    List& operator+=(const List& list);

    bool operator==(const List& list) const noexcept;
    bool operator!=(const List& list) const noexcept;

    size_t size() const noexcept override;
    bool isEmpty() const noexcept override;

    void clear() noexcept override;

    inline iterator begin() noexcept;
    inline const_iterator begin() const noexcept;
    
    inline iterator end() noexcept;
    inline const_iterator end() const noexcept;

private:
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
