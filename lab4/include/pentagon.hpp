#pragma once

#include "../include/figure.hpp"
#include <iostream>

template <Scalar T>
class Pentagon : public Figure<T> {
public:
    friend std::ostream& operator<<(std::ostream& os, const Pentagon<T>& other);
    friend std::istream& operator>>(std::istream& is, Pentagon<T>& other);

    Pentagon();
    Pentagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5);
    Pentagon(const Pentagon<T>& other);
    Pentagon(Pentagon<T>&& other) noexcept;

    Point<T> Get_center() const noexcept override;
    explicit operator double() const noexcept override;

    Pentagon<T>& operator=(const Pentagon<T>& other);
    Pentagon<T>& operator=(Pentagon<T>&& other);
    bool operator==(const Pentagon<T>& other) const;

    ~Pentagon() = default;

private:
    double Get_square() const noexcept override;
    bool Is_pentagon() const noexcept;

    Point<T> points[5];
};
