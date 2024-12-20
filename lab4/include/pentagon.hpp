#pragma once

#include "../include/figure.hpp"
#include <iostream>


class Pentagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Pentagon& other);
    friend std::istream& operator>>(std::istream& is, Pentagon& other);

public:
    Pentagon();
    Pentagon(Point p1, Point p2, Point p3, Point p4, Point p5);
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;

    virtual Point Get_center() const noexcept override;

    Pentagon& operator=(const Pentagon &other);
    Pentagon& operator=(Pentagon &&other);
    bool operator==(const Pentagon &other) const;
    explicit operator double() const noexcept override;

    ~Pentagon(){};

private:
    double Get_square() const noexcept override;
    bool Is_pentagon() const noexcept;
    Point points[5];

};