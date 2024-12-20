#include "../include/trapezium.hpp"
#include <stdexcept>
#include <cmath>

// Проверка, является ли фигура трапецией
template<Scalar T>
bool Trapezium<T>::Is_trapezium() const noexcept {
    if (std::abs(Vector_prod(points[1] - points[0], points[3] - points[2])) < eps) {
        return true;
    }
    if (std::abs(Vector_prod(points[2] - points[1], points[0] - points[3])) < eps) {
        return true;
    }
    return false;
}

// Конструкторы
template<Scalar T>
Trapezium<T>::Trapezium() : points{Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template<Scalar T>
Trapezium<T>::Trapezium(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4) : points{p1, p2, p3, p4} {
    if (!Is_trapezium()) {
        throw std::logic_error("Not a Trapezium!");
    }
}

template<Scalar T>
Trapezium<T>::Trapezium(const Trapezium<T>& other) {
    for (size_t i = 0; i < 4; ++i) {
        points[i] = other.points[i];
    }
}

template<Scalar T>
Trapezium<T>::Trapezium(Trapezium<T>&& other) noexcept {
    for (size_t i = 0; i < 4; ++i) {
        points[i] = std::move(other.points[i]);
    }
}

// Получение центра
template<Scalar T>
Point<T> Trapezium<T>::Get_center() const noexcept {
    T x = 0, y = 0;
    for (size_t i = 0; i < 4; ++i) {
        x += points[i].x_;
        y += points[i].y_;
    }
    return Point<T>(x / 4, y / 4);
}

// Операторы присваивания
template<Scalar T>
Trapezium<T>& Trapezium<T>::operator=(const Trapezium<T>& other) {
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < 4; ++i) {
        points[i] = other.points[i];
    }
    return *this;
}

template<Scalar T>
Trapezium<T>& Trapezium<T>::operator=(Trapezium<T>&& other) {
    if (this == &other) {
        return *this;
    }
    for (size_t i = 0; i < 4; ++i) {
        points[i] = std::move(other.points[i]);
    }
    return *this;
}

// Оператор сравнения
template<Scalar T>
bool Trapezium<T>::operator==(const Trapezium<T>& other) const {
    for (size_t i = 0; i < 4; ++i) {
        if (points[i] != other.points[i]) {
            return false;
        }
    }
    return true;
}

// Потоковые операторы
template<Scalar T>
std::ostream& operator<<(std::ostream& os, const Trapezium<T>& other) {
    for (size_t i = 0; i < 4; ++i) {
        os << other.points[i] << std::endl;
    }
    return os;
}

template<Scalar T>
std::istream& operator>>(std::istream& is, Trapezium<T>& other) {
    for (size_t i = 0; i < 4; ++i) {
        is >> other.points[i];
    }
    return is;
}

// Вычисление площади
template<Scalar T>
double Trapezium<T>::Get_square() const noexcept {
    T d1 = std::sqrt(std::pow(points[0].x_ - points[2].x_, 2) + std::pow(points[0].y_ - points[2].y_, 2));
    T d2 = std::sqrt(std::pow(points[1].x_ - points[3].x_, 2) + std::pow(points[1].y_ - points[3].y_, 2));
    return 0.5 * d1 * d2;
}

// Приведение к double
template<Scalar T>
Trapezium<T>::operator double() const noexcept {
    return Get_square();
}
