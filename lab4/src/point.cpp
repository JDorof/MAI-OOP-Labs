#include "../include/point.hpp"

template<Scalar T>
Point<T>::Point() : x_{0}, y_{0} {}

template<Scalar T>
Point<T>::Point(T x, T y) : x_{x}, y_{y} {}

template<Scalar T>
Point<T>::Point(const Point<T> &other) : x_(other.x_), y_(other.y_) {}

template<Scalar T>
Point<T>& Point<T>::operator=(const Point<T> &other){
    if (this != &other) {
        x_ = other.x_;
        y_ = other.y_;
    }
    return *this;
}

template class Point<int>;
template class Point<double>;