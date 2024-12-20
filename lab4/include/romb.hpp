#pragma once

#include "../include/figure.hpp"
#include <iostream>

class Romb : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Romb& other);
    friend std::istream& operator>>(std::istream& is, Romb& other);

public:
    Romb();
    Romb(Point p1, Point p2, Point p3, Point p4);
    Romb(const Romb& other);
    Romb(Romb&& other) noexcept;

    virtual Point Get_center() const noexcept override;

    Romb& operator=(const Romb &other);
    Romb& operator=(Romb &&other);
    bool operator==(const Romb &other) const;
    explicit operator double() const noexcept override;

    ~Romb(){};

private:
    double Get_square() const noexcept override;
    bool Is_romb() const noexcept;
    Point points[4];
};