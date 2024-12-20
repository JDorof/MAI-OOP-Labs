#include "../include/pentagon.hpp"

template <Scalar T>
bool Pentagon<T>::Is_pentagon() const noexcept {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((i != j) && (this->points[i].x_ == this->points[j].x_) && (this->points[i].y_ == this->points[j].y_)) {
                return false;
            }
        }
    }
    return true;
}

template <Scalar T>
Pentagon<T>::Pentagon() : points{Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template <Scalar T>
Pentagon<T>::Pentagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5) : points{p1, p2, p3, p4, p5} {
    if (!this->Is_pentagon()) {
        throw std::logic_error("Not a Pentagon!");
    }
}

template <Scalar T>
Pentagon<T>::Pentagon(const Pentagon<T>& other) {
    for (int i = 0; i < 5; ++i) {
        points[i] = other.points[i];
    }
}

template <Scalar T>
Pentagon<T>::Pentagon(Pentagon<T>&& other) noexcept {
    for (int i = 0; i < 5; ++i) {
        points[i] = std::move(other.points[i]);
    }
}

template <Scalar T>
Point<T> Pentagon<T>::Get_center() const noexcept {
    double x = 0, y = 0;
    for (size_t i = 0; i < 5; ++i) {
        x += points[i].x_;
        y += points[i].y_;
    }
    return Point<T>(x / 5.0, y / 5.0);
}

template <Scalar T>
Pentagon<T>::operator double() const noexcept {
    return Get_square();
}

template <Scalar T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon<T>& other) {
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < 5; ++i) {
        points[i] = other.points[i];
    }
    return *this;
}

template <Scalar T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon<T>&& other) {
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < 5; ++i) {
        points[i] = std::move(other.points[i]);
    }
    return *this;
}

template <Scalar T>
bool Pentagon<T>::operator==(const Pentagon<T>& other) const {
    for (size_t i = 0; i < 5; ++i) {
        if (points[i] != other.points[i]) {
            return false;
        }
    }
    return true;
}

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Pentagon<T>& other) {
    for (size_t i = 0; i < 5; ++i) {
        os << other.points[i] << std::endl;
    }
    return os;
}

template <Scalar T>
std::istream& operator>>(std::istream& is, Pentagon<T>& other) {
    for (size_t i = 0; i < 5; ++i) {
        is >> other.points[i];
    }
    return is;
}

template <Scalar T>
double Pentagon<T>::Get_square() const noexcept {
    double S = 0;
    for (int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        S += Figure<T>::Vector_prod(points[i], points[j]) / 2;
    }
    return std::abs(S);
}

template class Pentagon<int>;
template class Pentagon<double>;
