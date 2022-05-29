#include "transform.hpp"
#include <cmath>

Transform::Transform(const Vector &position, const Vector &rotation, const Vector &scale)
        : position(position), rotation(rotation), scale(scale) {}

const Vector& Transform::getPosition() const { return position; }
const Vector& Transform::getRotation() const { return rotation; }
const Vector& Transform::getScale() const { return scale; }

void Transform::setPosition(const Vector &newPosition) { position = newPosition; }
void Transform::setRotation(const Vector &newRotation) { rotation = newRotation; }
void Transform::setScale(const Vector &newScale) { scale = newScale; }

Vector Transform::apply(const Vector &vec)
{
    return position + rotate(scale * vec);
}

Vector Transform::rotate(const Vector &vec)
{
    double a = rotation.getX();
    double b = rotation.getY();
    double c = rotation.getZ();

    double sa = std::sin(a);
    double ca = std::cos(a);
    double sb = std::sin(b);
    double cb = std::cos(b);
    double sc = std::sin(c);
    double cc = std::cos(c);

    double x = vec.getX();
    double y = vec.getY();
    double z = vec.getZ();

    double xx = x;
    double yy = ca * y + sa * z;
    double zz = -sa * y 
}
