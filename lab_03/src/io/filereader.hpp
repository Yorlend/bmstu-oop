#pragma once

#include <fstream>
#include <string>
#include "ireader.hpp"

class FileReader : public IReader
{
public:
    FileReader(const std::string &filename);

    virtual size_t readCount() override;
    virtual std::string readString() override;
    virtual Vector readVector() override;
    virtual Edge readEdge() override;
    virtual double readDouble() override;
    virtual bool readBool() override;

private:
    std::ifstream file;
};
