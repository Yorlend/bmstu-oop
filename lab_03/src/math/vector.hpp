#pragma once

#include <initializer_list>
#include <ostream>

class Vector
{
public:
    Vector(double xPos = 0.0, double yPos = 0.0, double zPos = 0.0, double wDir = 0.0) noexcept;
    Vector(const std::initializer_list<double> &init);

    double getX() const;
    double getY() const;
    double getZ() const;
    double getW() const;

    void setX(double newX) noexcept;
    void setY(double newY) noexcept;
    void setZ(double newZ) noexcept;
    void setW(double newW) noexcept;

    double length() const;

    void normalize();

    double dot(const Vector &other) const;

    Vector operator-() const;

    Vector operator+(const Vector &other) const;
    Vector &operator+=(const Vector &other);

    Vector operator-(const Vector &other) const;
    Vector &operator-=(const Vector &other);

    Vector operator*(const Vector &other) const;
    Vector &operator*=(const Vector &other);

    Vector operator*(double mul) const;
    Vector &operator*=(double mul);

    Vector operator~() const;

private:
    double x;
    double y;
    double z;
    double w;
};

std::ostream &operator<<(std::ostream &stream, const Vector &vec);
Vector operator*(double mul, const Vector &other);
