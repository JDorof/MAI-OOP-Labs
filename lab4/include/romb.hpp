#pragma once

#include "../include/figure.hpp"
#include <iostream>

template<Scalar T>
class Romb : public Figure<T> {
public:
    Romb();
    Romb(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4);
    Romb(const Romb<T>& other);
    Romb(Romb<T>&& other) noexcept;

    virtual Point<T> Get_center() const noexcept override;

    Romb<T>& operator=(const Romb<T> &other);
    Romb<T>& operator=(Romb<T> &&other);
    bool operator==(const Romb<T> &other) const;
    explicit operator double() const noexcept override;

    ~Romb() {};

    friend std::ostream& operator<< <T>(std::ostream& os, const Romb<T>& romb);
    friend std::istream& operator>> <T>(std::istream& is, Romb<T>& romb);

private:
    double Get_square() const noexcept override;
    bool Is_romb() const noexcept;
    Point<T> points[4];
};