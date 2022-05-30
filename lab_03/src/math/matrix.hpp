#pragma once

#include "vector.hpp"

class Matrix
{
public:
    Matrix();

    static Matrix identity();
    static Matrix translate(double dx, double dy, double dz);
    static Matrix translate(const Vector &offset);
    static Matrix rotate(const Vector &axis, double angle);
    static Matrix rotate(const Vector &angles);
    static Matrix rotate(const Vector &offset, const Vector &angles);
    static Matrix scale(double fx, double fy, double fz);
    static Matrix scale(const Vector &factors);
    static Matrix scale(const Vector &offset, const Vector &factors);
    static Matrix perspective(double fov, double near, double far);

    static Matrix fpsModel(const Vector &eye, Vector look);
    static Matrix fpsModel(const Vector &eye, double pitch, double yaw);
    static Matrix trsModel(const Vector &position, const Vector &rotation, const Vector &scale);

    double det() const;
    Matrix operator*(const Matrix &right) const;
    Matrix operator*(double val) const;
    Vector operator*(const Vector &vec) const;

    Matrix transpose() const;
    Matrix inverse() const;

    double at(size_t row, size_t col) const;

    Vector row(size_t index) const;
    Vector col(size_t index) const;

protected:
    explicit Matrix(const double mat[16]);

private:
    double data[16];
};

Matrix operator*(double val, const Matrix &mat);
Vector operator*(const Vector &vec, const Matrix &mat);
