#include <stdexcept>
#include <cmath>
#include "vector.hpp"

Vector::Vector(double xPos, double yPos, double zPos, double wDir) noexcept
    : x(xPos), y(yPos), z(zPos), w(wDir) {}

Vector::Vector(const std::initializer_list<double> &init)
{
    int init_size = init.size();

    if (init_size != 3 && init_size != 4)
        throw std::runtime_error("Bad initializer list size");

    auto beg = init.begin();
    x = *beg++;
    y = *beg++;
    z = *beg++;

    if (beg != init.end())
        w = *beg;
    else
        w = 0;
}

double Vector::getX() const
{
    return x;
}

double Vector::getY() const
{
    return y;
}

double Vector::getZ() const
{
    return z;
}

double Vector::getW() const
{
    return w;
}

void Vector::setX(double newX) noexcept
{
    x = newX;
}

void Vector::setY(double newY) noexcept
{
    y = newY;
}

void Vector::setZ(double newZ) noexcept
{
    z = newZ;
}

void Vector::setW(double newW) noexcept
{
    w = newW;
}

double Vector::length() const
{
    return sqrt(x * x + y * y + z * z);
}

void Vector::normalize()
{
    *this = ~*this;
}

double Vector::dot(const Vector &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

Vector Vector::operator-() const
{
    return Vector(-x, -y, -z, w);
}

Vector Vector::operator+(const Vector &other) const
{
    return Vector(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vector &Vector::operator+=(const Vector &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;

    return *this;
}

Vector Vector::operator-(const Vector &other) const
{
    return Vector(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vector &Vector::operator-=(const Vector &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;

    return *this;
}

Vector Vector::operator*(const Vector &other) const
{
    return Vector(x * other.x, y * other.y, z * other.z, w * other.w);
}

Vector &Vector::operator*=(const Vector &other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;

    return *this;
}

Vector Vector::operator*(double mul) const
{
    return Vector(x * mul, y * mul, z * mul, w * mul);
}

Vector &Vector::operator*=(double mul)
{
    x *= mul;
    y *= mul;
    z *= mul;
    w *= mul;

    return *this;
}

Vector Vector::operator~() const
{
    double len = length();

    return Vector(x / len, y / len, z / len);
}

std::ostream &operator<<(std::ostream &stream, const Vector &vec)
{
    stream << "{ " << vec.getX() << ", " << vec.getY() << ", " << vec.getZ() << " }";
    return stream;
}

Vector operator*(double mul, const Vector &vec)
{
    return Vector(vec.getX() * mul, vec.getY() * mul, vec.getZ() * mul, vec.getW() * mul);
}
