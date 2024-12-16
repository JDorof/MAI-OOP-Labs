#pragma once

#include "../include/figure.hpp"
#include <iostream>

class Trapezium : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Trapezium& other);
    friend std::istream& operator>>(std::istream& is, Trapezium& other);

public:
    Trapezium();
    Trapezium(Point p1, Point p2, Point p3, Point p4);
    Trapezium(const Trapezium& other);
    Trapezium(Trapezium&& other) noexcept;

    virtual Point Get_center() const noexcept override;

    Trapezium& operator=(const Trapezium &other);
    Trapezium& operator=(Trapezium &&other);
    bool operator==(const Trapezium &other) const;
    explicit operator double() const noexcept override;

    ~Trapezium(){};

private:
    double Get_square() const noexcept override;
    bool Is_trapezium() const noexcept;
    Point points[4];
};