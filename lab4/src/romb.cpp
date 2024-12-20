#include "../include/romb.hpp"
#include <cmath>
#include <stdexcept>

template<Scalar T>
bool Romb<T>::Is_romb() const noexcept {
    T x1 = points[0].x_; T y1 = points[0].y_;
    T x2 = points[1].x_; T y2 = points[1].y_;
    T x3 = points[2].x_; T y3 = points[2].y_;
    T x4 = points[3].x_; T y4 = points[3].y_;

    T a = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    T b = std::sqrt(std::pow(x2 - x3, 2) + std::pow(y2 - y3, 2));
    T c = std::sqrt(std::pow(x3 - x4, 2) + std::pow(y3 - y4, 2));
    T d = std::sqrt(std::pow(x4 - x1, 2) + std::pow(y4 - y1, 2));

    if (!(a == b && b == c && c == d)) {
        return false;
    }

    if (Vector_prod(points[1] - points[0], points[3] - points[2]) > eps) {
        return false;
    }

    if (Scalar_prod(points[2] - points[1], points[0] - points[3]) > eps) {
        return false;
    }

    return true;
}

template<Scalar T>
Romb<T>::Romb() : points{Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template<Scalar T>
Romb<T>::Romb(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4) : points{p1, p2, p3, p4} {
    if (!this->Is_romb()) {
        throw std::logic_error("Not a Romb!");
    }
}

template<Scalar T>
Romb<T>::Romb(const Romb<T>& other) {
    for (int i = 0; i < 4; ++i) {
        points[i] = other.points[i];
    }
}

template<Scalar T>
Romb<T>::Romb(Romb<T>&& other) noexcept {
    for (int i = 0; i < 4; ++i) {
        points[i] = std::move(other.points[i]);
    }
}

template<Scalar T>
Point<T> Romb<T>::Get_center() const noexcept {
    T x = 0, y = 0;
    for (size_t i = 0; i < 4; ++i) {
        x += points[i].x_;
        y += points[i].y_;
    }
    return Point<T>(x / 4.0, y / 4.0);
}

template<Scalar T>
Romb<T>& Romb<T>::operator=(const Romb<T>& other) {
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < 4; ++i) {
        points[i] = other.points[i];
    }
    return *this;
}

template<Scalar T>
Romb<T>& Romb<T>::operator=(Romb<T>&& other) {
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < 4; ++i) {
        points[i] = std::move(other.points[i]);
    }
    return *this;
}

template<Scalar T>
bool Romb<T>::operator==(const Romb<T>& other) const {
    for (size_t i = 0; i < 4; ++i) {
        if (points[i] != other.points[i]) {
            return false;
        }
    }
    return true;
}

template<Scalar T>
std::ostream& operator<<(std::ostream& os, const Romb<T>& other) {
    for (size_t i = 0; i < 4; ++i) {
        os << other.points[i] << std::endl;
    }
    return os;
}

template<Scalar T>
std::istream& operator>>(std::istream& is, Romb<T>& other) {
    for (size_t i = 0; i < 4; ++i) {
        is >> other.points[i];
    }
    return is;
}

template<Scalar T>
double Romb<T>::Get_square() const noexcept {
    T x1 = points[0].x_; T y1 = points[0].y_;
    T x2 = points[1].x_; T y2 = points[1].y_;
    T x3 = points[2].x_; T y3 = points[2].y_;
    T x4 = points[3].x_; T y4 = points[3].y_;

    T d1 = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));
    T d2 = std::sqrt(std::pow(x2 - x4, 2) + std::pow(y2 - y4, 2));
    return static_cast<double>(d1 * d2 / 2);
}

template<Scalar T>
Romb<T>::operator double() const noexcept {
    return Get_square();
}
