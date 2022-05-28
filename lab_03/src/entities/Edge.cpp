#include "Edge.hpp"

Edge::Edge(size_t startVert, size_t endVert) noexcept
    : start(startVert), end(endVert) {}

size_t Edge::getStart() const
{
    return start;
}

size_t Edge::getEnd() const
{
    return end;
}
