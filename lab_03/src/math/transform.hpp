#pragma once

#include "vector.hpp"

class Transform
{
public:
    Transform() = default;
    Transform(const Vector &position, const Vector &rotation, const Vector &scale);

    const Vector &getPosition() const;
    const Vector &getRotation() const;
    const Vector &getScale() const;

    void setPosition(const Vector &newPosition);
    void setRotation(const Vector &newRotation);
    void setScale(const Vector &newScale);

    Vector apply(const Vector &vec);

private:
    Vector rotate(const Vector &vec);

    Vector position = Vector(0.0, 0.0, 0.0, 1.0);
    Vector rotation = Vector(0.0, 0.0, 0.0, 0.0);
    Vector scale = Vector(1.0, 1.0, 1.0, 0.0);
};
