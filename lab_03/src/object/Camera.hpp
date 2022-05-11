#pragma once

#include "Vector.hpp"

class Camera
{
    Camera(Vector pos, Vector upDir, Vector eyeDir);

    const Vector& getPosition() const;
    const Vector& getUpDir() const;
    const Vector& getEyeDir() const;

    void setPosition(const Vector& newPos);
    void setUpDir(const Vector& newDir);
    void setEyeDir(const Vector& newDir);

private:
    Vector position;
    Vector up;
    Vector eye;
};
