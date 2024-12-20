#include "../include/figure_vector.hpp"

FigureVector::FigureVector() : buf(nullptr), size_(0), cap(3), head(0){
    buf = new Figure*[cap];
    for (int i = 0; i < cap; i++) {
        buf[i] = nullptr;
    }
}


void FigureVector::Resize(int new_size) {
    Figure** tmp = new Figure*[new_size];
    for (int i = 0; i < new_size; i++) {
        tmp[i] = nullptr;
    }
    for (int i = 0; i < size_; i++) {
        int ind = (head + i) % cap;
        tmp[i] = buf[ind];
    }
    delete [] buf;
    buf = tmp;
    cap = new_size;
    head = 0;
}

int FigureVector::Size() const noexcept { 
    return size_;
}

void FigureVector::Push_back(Figure* val) noexcept {
    if (size_ == cap) {
        Resize(cap * 2);
    }
    int ind = (head + size_) % cap;
    buf[ind] = val;
    size_++;
}


const Figure* FigureVector::Get(int ind) const {
    if (ind >= 0 && ind < size_) {
        int real_ind = (head + ind) % cap;
        return buf[real_ind];
    }
    throw std::out_of_range("Index is out of range");
}

void FigureVector::Remove(int ind){
    if (ind < 0 || ind > size_) {
        throw std::invalid_argument("Index out of range");
    }
    Figure** new_buf = new Figure*[cap];

    for (int i = 0; i < ind; i++) {
        int old_ind = (head + i) % cap;
        new_buf[i] = buf[old_ind];
    }
    for (int i = ind; i < size_ - 1; i++) {
        int old_ind = (head + i + 1) % cap;
        new_buf[i] = buf[old_ind];
    }

    delete [] buf;
    buf = new_buf;
    size_--;

    if (size_ <= cap / 3) {
        Resize(cap * 3/5);
    }
}

FigureVector::~FigureVector(){
    size_ = 0;
    cap = 0;
    head = 0;
    delete [] buf;
    buf = nullptr;
}