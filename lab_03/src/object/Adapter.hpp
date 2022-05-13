#pragma once

#include "BaseObject.hpp"


template <typename Object>
class Adapter : public BaseObject
{
public:
    Adapter(Object&& obj) noexcept : object(std::move(obj)) {}

    const Object* operator->() const { return &object; }
    Object* operator->() { return &object; }

    const Object& operator*() const { return object; }
    Object& operator*() { return object; }

private:
    Object object;
};
