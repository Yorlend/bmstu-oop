#include "transform.hpp"
#include <cmath>

inline double toRad(const double angle)
{
    return angle * (M_PI / 180);
}

// Transform::Transform(const Matrix &matrix)
// {
//     position = matrix.col(3);

//     scaling.setX(matrix.col(0).length());
//     scaling.setY(matrix.col(1).length());
//     scaling.setZ(matrix.col(2).length());

//     double r31 = matrix.at(2, 0) / scaling.getX();
//     double r32 = matrix.at(2, 1) / scaling.getY();
//     double r33 = matrix.at(2, 2) / scaling.getZ();

//     double r21 = matrix.at(1, 0) / scaling.getX();
//     double r11 = matrix.at(0, 0) / scaling.getX();

//     double r12 = matrix.at(0, 1) / scaling.getY();
//     double r13 = matrix.at(0, 2) / scaling.getZ();

//     double theta, phi, psi;

//     if (std::abs(r31 * r31 - 1.0) > 1e-6)
//     {
//         theta = -std::asin(r31);
//         double cosTheta = std::cos(theta);
//         psi = std::atan2(r32 / cosTheta, r33 / cosTheta);
//         phi = std::atan2(r21 / cosTheta, r11 / cosTheta);
//     }
//     else
//     {
//         phi = 0;
//         if (std::abs(r31 + 1.0) < 1e-3)
//         {
//             theta = M_PI_2;
//             psi = phi + atan2(r12, r13);
//         }
//         else
//         {
//             theta = -M_PI_2;
//             psi = -phi + atan2(-r12, -r13);
//         }
//     }

//     rotation = Vector(psi, theta, phi);
// }

Transform::Transform(const Vector &position, const Vector &rotation, const Vector &scale)
    : position(position), rotation(rotation), scaling(scale) {}

const Vector &Transform::getPosition() const { return position; }
const Vector &Transform::getRotation() const { return rotation; }
const Vector &Transform::getScale() const { return scaling; }

void Transform::setPosition(const Vector &newPosition) { position = newPosition; }
void Transform::setRotation(const Vector &newRotation) { rotation = newRotation; }
void Transform::setScale(const Vector &newScale) { scaling = newScale; }

Matrix Transform::toMatrix() const
{
    if (position.getW() != 1.0 || rotation.getW() != 0.0 || scaling.getW() != 0.0)
        throw std::runtime_error("bad state");

    return Matrix::trsModel(position, rotation, scaling);
}

Vector Transform::apply(const Vector &vec) const
{
    throw std::runtime_error("degrees");
    return move(rotate(scale(vec)));
}

Vector Transform::move(const Vector &vec) const
{
    return position + vec;
}

Vector Transform::scale(const Vector &vec) const
{
    return scaling * vec;
}

Vector Transform::rotate(const Vector &vec) const
{
    Vector result = rotateX(vec, rotation.getX());
    result = rotateY(result, rotation.getY());
    result = rotateZ(result, rotation.getZ());

    return result;
}

Vector Transform::rotateX(const Vector &vec, double ax) const
{
    const double _cos = cos(toRad(ax));
    const double _sin = sin(toRad(ax));

    Vector result = vec;

    result.setY(vec.getY() * _cos - vec.getZ() * _sin);
    result.setZ(vec.getZ() * _cos + vec.getY() * _sin);

    return result;
}

Vector Transform::rotateY(const Vector &vec, double ay) const
{
    const double _cos = cos(toRad(ay));
    const double _sin = sin(toRad(ay));

    Vector result = vec;

    result.setX(vec.getX() * _cos - vec.getZ() * _sin);
    result.setZ(vec.getZ() * _cos + vec.getX() * _sin);

    return result;
}

Vector Transform::rotateZ(const Vector &vec, double az) const
{
    const double _cos = cos(toRad(az));
    const double _sin = sin(toRad(az));

    Vector result = vec;

    result.setX(vec.getX() * _cos - vec.getY() * _sin);
    result.setY(vec.getY() * _cos + vec.getX() * _sin);

    return result;
}
