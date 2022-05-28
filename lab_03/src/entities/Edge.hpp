#pragma once

#include <cstddef>

class Edge
{
public:
    Edge(size_t startVert, size_t endVert) noexcept;

    size_t getStart() const;
    size_t getEnd() const;

private:
    size_t start;
    size_t end;
};
