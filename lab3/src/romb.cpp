#include "../include/romb.hpp"
#include <cmath>

bool Romb::is_romb() const noexcept {
    double x1 = points[0].x_; double y1 = points[0].y_;
    double x2 = points[1].x_; double y2 = points[1].y_;
    double x3 = points[2].x_; double y3 = points[2].y_;
    double x4 = points[3].x_; double y4 = points[3].y_;
    
    double a = sqrt(pow(std::abs(x1 - x2),2) + pow(std::abs(y1 - y2),2));
    double b = sqrt(pow(std::abs(x2 - x3),2) + pow(std::abs(y2 - y3),2));
    double c = sqrt(pow(std::abs(x3 - x4),2) + pow(std::abs(y3 - y4),2));
    double d = sqrt(pow(std::abs(x4 - x1),2) + pow(std::abs(y4 - y1),2));

    if (!(a == b && b == c && c == d)){
        return false;
    }

    if (vector_prod(points[1] - points[0], points[3] - points[2]) > eps){
        return false;
    }

    if (scalar_prod(points[2] - points[1], points[0] - points[3]) > eps){
        return false;
    }

    return true;
}

Romb::Romb() : points{Point(), Point(), Point(), Point()} {}

Romb::Romb(Point p1, Point p2, Point p3, Point p4) : points{p1, p2, p3, p4}  {
    if (!this->is_romb()){
        throw std::logic_error("Not a Romb!");
    }
}

Romb::Romb(const Romb& other) : points{Point(), Point(), Point(), Point()}{
    for (int i = 0; i < 4; ++i){
        points[i] = other.points[i];
    }
}

Romb::Romb(Romb&& other) noexcept {
    for (int i = 0; i < 4; ++i){
        points[i] = other.points[i];
        other.points[i] = Point();
    }
}

Point Romb::get_center() const noexcept {
    double x = 0, y = 0;
    for(size_t i = 0; i < 4; ++i){
        x += points[i].x_;
        y += points[i].y_;
    }
    return Point(x / 4.0, y / 4.0);
}

Romb& Romb::operator=(const Romb &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 4; ++i){
        points[i] = other.points[i];
    }

    return *this;
}

Romb& Romb::operator=(Romb &&other){
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

bool Romb::operator==(const Romb& other) const {
    for(size_t i = 0; i < 4; ++i){
        if(points[i] != other.points[i]){
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Romb& other){
    // os << "Romb's coordinates: ";
    for(size_t i = 0; i < 4; ++i){
        os << other.points[i] << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Romb& other) {
    for (size_t i = 0; i < 4; ++i) {
        is >> other.points[i];
    }
    return is;
}

double Romb::get_square() const noexcept {
    double x1 = points[0].x_; double y1 = points[0].y_;
    double x2 = points[1].x_; double y2 = points[1].y_;
    double x3 = points[2].x_; double y3 = points[2].y_;
    double x4 = points[3].x_; double y4 = points[3].y_;
    
    double d1 = std::abs(x1 - x3);
    double d2 = std::abs(x2 - x4);
    double S = d1*d2 / 2;
    return S;
}

Romb::operator double() const noexcept {
    return get_square();
}