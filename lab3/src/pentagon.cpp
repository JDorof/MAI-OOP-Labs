#include "../include/pentagon.hpp"

bool Pentagon::Is_pentagon() const noexcept {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((i != j) && (this->points[i].x_ == this->points[j].x_) && (this->points[i].y_ == this->points[j].y_)) {
                return false;
            }
        }
    }
    return true;
}

Pentagon::Pentagon() : points{Point(), Point(), Point(), Point(), Point()} {}

Pentagon::Pentagon(Point p1, Point p2, Point p3, Point p4, Point p5) : points{p1, p2, p3, p4, p5}  {
    if (!this->Is_pentagon()) {
        throw std::logic_error("Not a Pentagon!");
    }
}

Pentagon::Pentagon(const Pentagon& other) : points{Point(), Point(), Point(), Point(), Point()} {
    for (int i = 0; i < 5; ++i) {
        points[i] = other.points[i];
    }
}

Pentagon::Pentagon(Pentagon&& other) noexcept {
    for (int i = 0; i < 5; ++i){
        points[i] = other.points[i];
        other.points[i] = Point();
    }
}

Point Pentagon::Get_center() const noexcept {
    double x = 0, y = 0;
    for(size_t i = 0; i < 5; ++i) {
        x += points[i].x_;
        y += points[i].y_;
    }
    return Point(x / 5.0, y / 5.0);
}

Pentagon& Pentagon::operator=(const Pentagon &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 5; ++i) {
        points[i] = other.points[i];
    }

    return *this;
}

Pentagon& Pentagon::operator=(Pentagon &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 5; ++i){
        points[i] = std::move(other.points[i]);
        //points[i] = other.points[i];
        //other.points[i] = nullptr;
        
    }

    return *this;
}

bool Pentagon::operator==(const Pentagon& other) const {
    for(size_t i = 0; i < 5; ++i){
        if(points[i] != other.points[i]){
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Pentagon& other){
    for(size_t i = 0; i < 5; ++i){
        os << other.points[i] << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Pentagon& other) {
    for (size_t i = 0; i < 5; ++i) {
        is >> other.points[i];
    }
    return is;
}

double Pentagon::Get_square() const noexcept {
    double S = 0;
    for (int i = 0; i < 5; ++i){
        int j = (i + 1) % 5;
        S += Vector_prod(points[i], points[j]) / 2;
    }
    return std::abs(S);
}

Pentagon::operator double() const noexcept {
    return Get_square();
}