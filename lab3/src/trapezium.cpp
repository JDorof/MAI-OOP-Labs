#include "../include/trapezium.hpp"

bool Trapezium::is_trapezium() const noexcept {

    if (vector_prod(points[1] - points[0], points[3] - points[2]) < eps){
        return true;
    }

    if (scalar_prod(points[2] - points[1], points[0] - points[3]) < eps){
        return true;
    }

    return false;
}

Trapezium::Trapezium() : points{Point(), Point(), Point(), Point()} {}

Trapezium::Trapezium(Point p1, Point p2, Point p3, Point p4) : points{p1, p2, p3, p4}  {
    if (!this->is_trapezium()){
        throw std::logic_error("Not a Trapezium!");
    }
}

Trapezium::Trapezium(const Trapezium& other) : points{Point(), Point(), Point(), Point()}{
    for (int i = 0; i < 4; ++i){
        points[i] = other.points[i];
    }
}

Trapezium::Trapezium(Trapezium&& other) noexcept {
    for (int i = 0; i < 4; ++i){
        points[i] = other.points[i];
        other.points[i] = Point();
    }
}

Point Trapezium::get_center() const noexcept {
    double x = 0, y = 0;
    for(size_t i = 0; i < 4; ++i){
        x += points[i].x_;
        y += points[i].y_;
    }
    return Point(x / 4.0, y / 4.0);
}

Trapezium& Trapezium::operator=(const Trapezium &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        points[i] = other.points[i];
    }

    return *this;
}

Trapezium& Trapezium::operator=(Trapezium &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        points[i] = std::move(other.points[i]);
        //points[i] = other.points[i];
        //other.points[i] = nullptr;
        
    }

    return *this;
}

bool Trapezium::operator==(const Trapezium& other) const {
    for(size_t i = 0; i < 4; ++i){
        if(points[i] != other.points[i]){
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Trapezium& other){
    // os << "Trapezium's coordinates: ";
    for(size_t i = 0; i < 4; ++i){
        os << other.points[i] << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Trapezium& other) {
    for (size_t i = 0; i < 4; ++i) {
        is >> other.points[i];
    }
    return is;
}

double Trapezium::get_square() const noexcept {
    double S = vector_prod(points[3] - points[1], points[2] - points[0]) / 2;
    return S;
}

Trapezium::operator double() const noexcept {
    return get_square();
}