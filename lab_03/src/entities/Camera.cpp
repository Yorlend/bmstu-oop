#include "Camera.hpp"

Camera::Camera(Vector pos, Vector upDir, Vector eyeDir)
    : position(pos), up(upDir), eye(eyeDir) {}

const Vector& Camera::getPosition() const
{
    return position;
}

const Vector& Camera::getUpDir() const
{
    return up;
}

const Vector& Camera::getEyeDir() const
{
    return eye;
}

void Camera::setPosition(const Vector& newPos)
{
    position = newPos;
}

void Camera::setUpDir(const Vector& newDir)
{
    up = newDir;
}

void Camera::setEyeDir(const Vector& newDir)
{
    eye = newDir;
}
