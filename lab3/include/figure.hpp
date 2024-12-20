#pragma once

#include <cstring>
#include <cmath>
#include "./point.hpp"

class Figure{
public:
    Figure() = default; 
    virtual Point Get_center() const noexcept = 0; 
    virtual explicit operator double() const noexcept = 0; 
    virtual ~Figure() = default; 
    static double eps;
    double Scalar_prod(Point p1, Point p2) const noexcept;
    double Vector_prod(Point p1, Point p2) const noexcept;
private:
    virtual double Get_square() const noexcept = 0;
};