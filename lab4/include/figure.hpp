#pragma once

#include <cstring>
#include <cmath>
#include <limits>
#include "./point.hpp"

template<Scalar T>
class Figure {
public:
    Figure() = default;
    virtual Point<T> Get_center() const noexcept = 0;
    virtual explicit operator double() const noexcept = 0;
    virtual ~Figure() = default;

    static T eps;

    double Scalar_prod(Point<T> p1, Point<T> p2) const noexcept;
    double Vector_prod(Point<T> p1, Point<T> p2) const noexcept;

private:
    virtual double Get_square() const noexcept = 0;
    static void Init_eps();
};
