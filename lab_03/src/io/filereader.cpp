#include <stdexcept>
#include "filereader.hpp"

FileReader::FileReader(const std::string &filename)
    : file(filename)
{
    if (!file)
        throw std::runtime_error("bad file name");
}

size_t FileReader::readCount()
{
    size_t value;

    file >> value >> std::ws;

    return value;
}

std::string FileReader::readString()
{
    std::string value;

    std::getline(file, value);

    return value;
}

Vector FileReader::readVector()
{
    double x, y, z, w;

    file >> x >> y >> z >> w >> std::ws;

    return Vector(x, y, z, w);
}

Edge FileReader::readEdge()
{
    size_t index1, index2;

    file >> index1 >> index2 >> std::ws;

    return Edge(index1, index2);
}

double FileReader::readDouble()
{
    double value;

    file >> value >> std::ws;

    return value;
}

bool FileReader::readBool()
{
    bool value;

    file >> value >> std::ws;

    return value;
}
