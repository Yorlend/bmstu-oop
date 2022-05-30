#pragma once

#include "vector.hpp"
#include "matrix.hpp"

class Transform
{
public:
    Transform() = default;
    // Transform(const Matrix& matrix);
    Transform(const Vector &position, const Vector &rotation, const Vector &scale);

    const Vector &getPosition() const;
    const Vector &getRotation() const;
    const Vector &getScale() const;

    void setPosition(const Vector &newPosition);
    void setRotation(const Vector &newRotation);
    void setScale(const Vector &newScale);

    Matrix toMatrix() const;

    Vector apply(const Vector &vec) const;

private:
    Vector rotate(const Vector &vec) const;
    Vector scale(const Vector &vec) const;
    Vector move(const Vector &vec) const;

    Vector rotateX(const Vector &vec, double ax) const;
    Vector rotateY(const Vector &vec, double ay) const;
    Vector rotateZ(const Vector &vec, double az) const;

    Vector position = Vector(0.0, 0.0, 0.0, 1.0);
    Vector rotation = Vector(0.0, 0.0, 0.0, 0.0);
    Vector scaling = Vector(1.0, 1.0, 1.0, 0.0);
};
