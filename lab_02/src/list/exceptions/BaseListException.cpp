#include <ctime>
#include <cstdio>
#include "BaseListException.h"

BaseListException::BaseListException(const char* reason, const char* filename, unsigned long line)
{
    const char* format = "[%d-%d-%d %d:%d:%d] %s:%lu: %s";

    time_t rawtime;
    time(&rawtime);
    struct tm* timeinfo = localtime(&rawtime);

    size_t msglen = snprintf(nullptr, 0, format,
             timeinfo->tm_mday,
             timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
             timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
             filename, line, reason);

    message = new char[msglen];
    snprintf(message, msglen + 1, format,
             timeinfo->tm_mday,
             timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
             timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
             filename, line, reason);
}

BaseListException::~BaseListException()
{
    delete message;
}

const char* BaseListException::what() const noexcept
{
    return message;
}
