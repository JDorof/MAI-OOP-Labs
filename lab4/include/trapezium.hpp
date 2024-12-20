#pragma once

#include "../include/figure.hpp"
#include <iostream>

template<Scalar T>
class Trapezium : public Figure<T> {
public:

    friend std::ostream& operator<<(std::ostream& os, const Trapezium<T>& other);
    friend std::istream& operator>>(std::istream& is, Trapezium<T>& other);
    
    Trapezium();
    Trapezium(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4);
    Trapezium(const Trapezium& other);
    Trapezium(Trapezium&& other) noexcept;

    virtual Point<T> Get_center() const noexcept override;

    Trapezium<T>& operator=(const Trapezium<T> &other);
    Trapezium<T>& operator=(Trapezium<T> &&other);
    bool operator==(const Trapezium<T> &other) const;
    explicit operator double() const noexcept override;

    ~Trapezium(){};

private:
    double Get_square() const noexcept override;
    bool Is_trapezium() const noexcept;
    Point<T> points[4];
};