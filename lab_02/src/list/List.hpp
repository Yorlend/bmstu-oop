#pragma once

#include "List.h"
#include "Iterator.h"
#include "ConstIterator.h"
#include "exceptions/OutOfBoundsException.h"
#include "exceptions/EmptyListException.h"
#include "exceptions/InvalidCountException.h"

template <typename T>
List<T>::List(const List& list)
{
    for (auto value : list)
        insertTail(value);
}

template <typename T>
List<T>::List(List&& list) noexcept
    : head(std::move(list.head)), tail(std::move(list.tail))
{
}

template <typename T>
List<T>::List(std::initializer_list<T> init)
{
    for (auto value : init)
        insertTail(value);
}

template <typename T>
template <typename Iter>
List<T>::List(Iter begin, Iter end)
{
    for (Iter it = begin; it != end; it++)
        insertTail(*it);
}

template <typename T>
List<T>& List<T>::operator=(const List& list)
{
    clear();
    for (const auto& value : list)
        insertTail(value);
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(List&& list) noexcept
{
    std::swap(head, list.head);
    std::swap(tail, list.tail);
    return *this;
}

template <typename T>
void List<T>::insertHead(const T& value)
{
    auto node = std::make_shared<Node<T>>(value);
    node->setNext(head);

    if (!head)
        tail = node;

    head = node;
}

template <typename T>
void List<T>::insertHead(const List& list)
{
    if (!list.isEmpty())
    {
        auto copy = List(list);
        copy.tail->setNext(head);
        head = copy.head;
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
void List<T>::insertTail(const List& list)
{
    if (!list.isEmpty())
    {
        auto copy = List(list);

        if (isEmpty())
        {
            head = copy.head;
            tail = copy.tail;
        }
        else
        {
            tail->setNext(copy.head);
            tail = copy.tail;
        }
    }
}

template <typename T>
void List<T>::insert(const T& value, size_t position)
{
    if (position > size())
        throw OutOfBoundsException(__FILE__, __LINE__);

    auto newNode = std::make_shared<Node<T>>(value);

    if (position == 0)
    {
        newNode->setNext(head);
        head = newNode;
        if (tail == nullptr)
            tail = head;
    }
    else if (position == size())
    {
        tail->setNext(newNode);
        tail = newNode;
    }
    else
    {
        auto node = head;
        while (--position != 0)
            node = node->getNext();
        newNode->setNext(node->getNext());
        node->setNext(newNode);
    }
}

template <typename T>
void List<T>::insert(const List& list, size_t position)
{
    for (const auto& val : list)
        insert(val, position++);
}

template <typename T>
void List<T>::removeHead()
{
    if (!head)
        throw EmptyListException(__FILE__, __LINE__);

    head = head->getNext();
    if (!head)
        tail = nullptr;
}

template <typename T>
void List<T>::removeHead(size_t count)
{
    if (count > size())
        throw InvalidCountException(__FILE__, __LINE__);
    else if (count == size())
        clear();
    else if (count != 0)
        while (count-- > 0)
            head = head->getNext();
}

template <typename T>
void List<T>::removeTail()
{
    if (!tail)
        throw EmptyListException(__FILE__, __LINE__);
    else if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        auto prev = head;
        while (prev->getNext() != tail)
            prev = prev->getNext();
        prev->setNext(nullptr);
        tail = prev;
    }
}

template <typename T>
void List<T>::removeTail(size_t count)
{
    if (count > size())
        throw InvalidCountException(__FILE__, __LINE__);
    else if (count == size())
        clear();
    else if (count != 0)
    {
        count = size() - count;
        auto prev = head;
        while (count-- != 0)
            prev = prev->getNext();
        prev->setNext(nullptr);
        tail = prev;
    }
}

template <typename T>
void List<T>::remove(size_t index)
{
    if (!head)
        throw EmptyListException(__FILE__, __LINE__);
    else if (index >= size())
        throw OutOfBoundsException(__FILE__, __LINE__);
    else if (index == 0)
        removeHead();
    else if (index == size() - 1)
        removeTail();
    else
    {
        auto node = head;
        while (--index != 0)
            node = node->getNext();
        node->setNext(node->getNext()->getNext());
    }
}

template <typename T>
void List<T>::remove(size_t index, size_t count)
{
    if (count == 0)
        return;
    else if (!head)
        throw EmptyListException(__FILE__, __LINE__);
    else if (index >= size())
        throw OutOfBoundsException(__FILE__, __LINE__);
    else if (index == 0)
        removeHead(count);
    else if (index + count == size())
        removeTail(count);
    else
    {
        auto node = head;
        while (--index > 0)
            node = node->getNext();
        while (count-- > 0)
            node->setNext(node->getNext()->getNext());
    }
}

template <typename T>
T List<T>::extractHead()
{
    if (!head)
        throw EmptyListException(__FILE__, __LINE__);

    auto oldHead = head;
    head = head->getNext();
    if (!head)
        tail = nullptr;
    return oldHead->getData();
}

template <typename T>
List<T> List<T>::extractHead(size_t count)
{
    return sublist(0, count);
}

template <typename T>
T List<T>::extractTail()
{
    return sublist(size() - 1);
}

template <typename T>
List<T> List<T>::extractTail(size_t count)
{
    return sublist(size() - count);
}

template <typename T>
T& List<T>::getHead()
{
    if (!head)
        throw EmptyListException(__FILE__, __LINE__);
    return head->getData();
}

template <typename T>
const T& List<T>::getHead() const
{
    if (!head)
        throw EmptyListException(__FILE__, __LINE__);
    return head->getData();
}

template <typename T>
T& List<T>::getTail()
{
    if (!tail)
        throw EmptyListException(__FILE__, __LINE__);
    return tail->getData();
}

template <typename T>
const T& List<T>::getTail() const
{
    if (!tail)
        throw EmptyListException(__FILE__, __LINE__);
    return tail->getData();
}

template <typename T>
List<T> List<T>::sublist(size_t index) const
{
    if (index > size())
        throw OutOfBoundsException(__FILE__, __LINE__);
    if (index == size())
        return List<T>();

    List<T> res;
    auto node = head;
    while (index-- > 0)
        node = node->getNext();
    for (; node != nullptr; node = node->getNext())
        res.insertTail(node->getData());

    return std::move(res);
}

template <typename T>
List<T> List<T>::sublist(size_t index, size_t count) const
{
    if (count == 0)
        return List<T>();
    if (index >= size())
        throw OutOfBoundsException(__FILE__, __LINE__);

    List<T> res;
    auto node = head;
    while (index-- > 0)
        node = node->getNext();
    for (; node != nullptr && count-- > 0; node = node->getNext())
        res.insertTail(node->getData());

    return std::move(res);
}

template <typename T>
List<T> List<T>::reverse() const
{
    List<T> res;

    for (auto node = head; node != nullptr; node = node->getNext())
        res.insertHead(node->getData());

    return res;
}

template <typename T>
bool List<T>::contains(const T& value) const noexcept
{
    for (auto node = head; node != nullptr; node = node->getNext())
        if (node->getData() == value)
            return true;
    return false;
}

template <typename T>
T& List<T>::operator[](size_t index)
{
    if (index >= size())
        throw OutOfBoundsException(__FILE__, __LINE__);

    auto node = head;
    while (index-- != 0)
        node = node->getNext();
    return node->getData();
}

template <typename T>
const T& List<T>::operator[](size_t index) const
{
    if (index >= size())
        throw OutOfBoundsException(__FILE__, __LINE__);

    auto node = head;
    while (index-- != 0)
        node = node->getNext();
    return node->getData();
}

template <typename T>
List<T> List<T>::operator+(const T& value) const
{
    List<T> copy = *this;
    copy.insertTail(value);
    return copy;
}

template <typename T>
List<T> List<T>::operator+(const List& list) const
{
    List<T> copy = *this;
    copy.insertTail(list);
    return copy;
}

template <typename T>
List<T>& List<T>::operator+=(const T& value)
{
    insertTail(value);
    return *this;
}

template <typename T>
List<T>& List<T>::operator+=(const List& list)
{
    insertTail(list);
    return *this;
}

template <typename T>
bool List<T>::operator==(const List& list) const noexcept
{
    if (size() != list.size())
        return false;

    for (auto node1 = head, node2 = list.head; node1 != nullptr;
            node1 = node1->getNext(), node2 = node2->getNext())
        if (node1->getData() != node2->getData())
            return false;
    return true;
}

template <typename T>
bool List<T>::operator!=(const List& list) const noexcept
{
    if (size() != list.size())
        return true;

    for (auto node1 = head, node2 = list.head; node1 != nullptr;
         node1 = node1->getNext(), node2 = node2->getNext())
        if (node1->getData() != node2->getData())
            return true;
    return false;
}

template <typename T>
size_t List<T>::size() const noexcept
{
    size_t length = 0;

    for (auto node = head; node != nullptr; node = node->getNext())
        length++;

    return length;
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
typename List<T>::const_iterator List<T>::begin() const noexcept
{
    return const_iterator(head);
}

template <typename T>
typename List<T>::iterator List<T>::end() noexcept
{
    return iterator(nullptr);
}

template <typename T>
typename List<T>::const_iterator List<T>::end() const noexcept
{
    return const_iterator(nullptr);
}

template <typename T>
List<T> operator+(const T& value, const List<T>& list)
{
    List<T> copy(list);
    copy.insertHead(value);
    return std::move(copy);
}

template <typename T>
List<T> operator+(std::initializer_list<T> init, const List<T>& list)
{
    return List<T>(init) + list;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const List<T>& list)
{
    stream << "[";

    bool first = true;
    for (const auto& value : list)
    {
        if (first)
            first = false;
        else
            stream << ", ";
        stream << value;
    }

    return stream << "]";
}
