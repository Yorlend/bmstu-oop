#pragma once

#include <exception>

class BaseListException : public std::exception
{
public:
    BaseListException(const char* reason, const char* filename, unsigned long line);
    virtual ~BaseListException();

    virtual const char* what() const noexcept override;

private:
    char* message;
};
