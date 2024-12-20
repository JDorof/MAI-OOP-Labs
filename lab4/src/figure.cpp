#include "../include/figure.hpp"

template<Scalar T>
double Figure<T>::Scalar_prod(Point<T> p1, Point<T> p2) const noexcept {
    return p1.x_ * p2.x_ + p1.y_ * p2.y_;
}

template<Scalar T>
double Figure<T>::Vector_prod(Point<T> p1, Point<T> p2) const noexcept {
    return p1.x_ * p2.y_ - p1.y_ * p2.x_;
}

template<Scalar T>
void Figure<T>::Init_eps() {
    if constexpr (std::is_integral<T>::value) {
        eps = 0;
    } else if constexpr (std::is_floating_point<T>::value) {
        eps = std::numeric_limits<T>::epsilon();
    } else {
        static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value,
                      "T must be either an integral or floating-point type.");
    }
}

template<Scalar T>
T Figure<T>::eps = T();

template class Figure<int>;
template class Figure<double>;
