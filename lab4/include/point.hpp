#pragma once
#include <cmath>
#include <type_traits>
#include <iostream>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template<Scalar T>
class Point
{
public:
    Point();
    Point(const Point<T>& other);
    Point<T>& operator=(const Point<T>& other);
    Point(T x, T y);

    // Дружественные шаблонные функции
    friend Point<T> operator+(const Point<T>& t, const Point<T>& other) {
        return Point<T>(t.x_ + other.x_, t.y_ + other.y_);
    }

    friend Point<T> operator-(const Point<T>& t, const Point<T>& other) {
        return Point<T>(t.x_ - other.x_, t.y_ - other.y_);
    }

    friend bool operator==(const Point<T>& t, const Point<T>& other) {
        return (t.x_ == other.x_) && (t.y_ == other.y_);
    }

    friend bool operator!=(const Point<T>& t, const Point<T>& other) {
        return !(t == other);
    }

    friend std::istream& operator>>(std::istream& is, Point<T>& p) {
        is >> p.x_ >> p.y_;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
        os << "x: " << p.x_ << ", y: " << p.y_;
        return os;
    }

    T x_{};
    T y_{};
};