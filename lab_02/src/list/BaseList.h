#pragma once

#include <cstddef>

class BaseList
{
public:
    virtual ~BaseList() = default;

    virtual size_t size() const noexcept = 0;
    virtual bool isEmpty() const noexcept = 0;

    virtual void clear() noexcept = 0;
};
