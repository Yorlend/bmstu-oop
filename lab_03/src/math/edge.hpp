#pragma once

class Edge
{
public:
    Edge(size_t index1, size_t index2)
        : index1(index1), index2(index2) {}

    size_t getStart() const { return index1; }
    size_t getEnd() const { return index2; }

private:
    size_t index1;
    size_t index2;
};
