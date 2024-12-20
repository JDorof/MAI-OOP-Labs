#include "solution.h"
#include <iostream>

Seven::Seven() : arr(nullptr), size(0) {}


Seven::Seven(const size_t n, const unsigned char c) : arr(nullptr), size(0) {
    if (c < '0' || c > '6') throw std::invalid_argument("Use chars between '0' and '6'");
    if (c != '0') {
        this->arr = new unsigned char[n];
        for (; this->size < n; ++this->size) {
            new (this->arr + this->size) unsigned char(c);
        }
    } else {
        this->arr = new unsigned char[1];
        new (this->arr) unsigned char(c);
        ++this->size;
    }
}

Seven::Seven(const size_t n, const unsigned char* other_arr) : size(0) {
    this->size = 0;
    this->arr = new unsigned char[n];
    for (; this->size < n; ++this->size) {
        new (this->arr + this->size) unsigned char(other_arr[this->size]);
    }
    Numerical_optimization();
}

Seven::Seven(const std::initializer_list<unsigned char>& init) : size(0) {
    for (const unsigned char& c : init)
    if (c < '0' || c > '6') throw std::invalid_argument("Use chars between '0' and '6'");
    
    this->arr = new unsigned char[init.size()];
    for (const unsigned char& c : init) {
        new (this->arr + this->size) unsigned char(c);
        ++this->size;
    }
}


Seven::Seven(const std::string &t) : size(0) {
    for (const unsigned char& c : t)
    if (c < '0' || c > '6') throw std::invalid_argument("Use chars between '0' and '6'");
    
    this->arr = new unsigned char[t.size()];
    for (; this->size < t.size(); ++this->size) {
        new (this->arr + this->size) unsigned char(t[this->size]);
    }
}


Seven::Seven(const Seven& other) : size(0) { // TODO exception when <0 or >7
    this->arr = new unsigned char[other.size];
    for (;this->size < other.size;++this->size) {
        new (this->arr + this->size) unsigned char(other.arr[this->size]);
    }
}


Seven& Seven::operator=(const Seven& other) {
    if (this->size == other.size) {
        this->size = 0;
        for (; this->size < other.size; ++this->size) {
            this->arr[this->size] = other.arr[this->size];
        }
    } else {
        this->size = 0;
        if (this->arr != nullptr) {
            delete[] this->arr;
            this->arr = nullptr;
        }
        this->arr = new unsigned char[other.size];
        for (;this->size < other.size;++this->size) {
            new (this->arr + this->size) unsigned char(other.arr[this->size]);
        }    
    }
    return *this;
}


Seven::Seven(Seven&& other) noexcept : arr(other.arr), size(other.size) {
    other.arr = nullptr;
    other.size = 0;
}


Seven& Seven::operator=(Seven&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    if (this->arr != nullptr) {
        delete[] this->arr;
    }
    this->size = 0;
    std::swap(this->arr, other.arr);
    std::swap(this->size, other.size);
    return *this;
}


Seven::~Seven() noexcept {
    delete[] this->arr;
}


void Seven::Numerical_optimization() {
    for (int i = 0; i < this->size - 1; ++i) {
        if (this->arr[i] > '6') {
            this->arr[i] = static_cast<unsigned char>(this->arr[i] - 7);
            ++this->arr[i + 1];
        }
    }
    if (this->arr[this->size - 1] > '6') {
        ++this->size;
        unsigned char* new_arr = new unsigned char[this->size];
        for (int i = 0; i < this->size - 1; ++i) {
            new (new_arr + i) unsigned char(this->arr[i]);
        }
        new_arr[this->size - 1] = '1';
        new_arr[this->size - 2] = static_cast<unsigned char>(new_arr[this->size - 2] - 7);
        delete[] this->arr;
        this->arr = new_arr; 
    }
}


bool Seven::operator==(const Seven& other) {
    if (this == &other) return true;
    size_t min_size = std::min(this->size, other.size);
    size_t max_size = std::max(this->size, other.size);
    if (this->size > other.size) for (int i = min_size; i < max_size; ++i) if (this->arr[i] > '0') return false;
    if (this->size < other.size) for (int i = min_size; i < max_size; ++i) if (other.arr[i] > '0') return false;
    for (int i = 0; i < min_size; ++i) if (this->arr[i] != other.arr[i]) return false;
    return true;
}


bool Seven::operator!=(const Seven& other) {
    return !(*this == other);
}


bool Seven::operator>(const Seven& other) {
    size_t min_size = std::min(this->size, other.size);
    size_t max_size = std::max(this->size, other.size);
    if (this->size > other.size) for (int i = min_size; i < max_size; ++i) if (this->arr[i] > '0') return true;
    if (this->size < other.size) for (int i = min_size; i < max_size; ++i) if (other.arr[i] > '0') return false;
    for (int i = min_size - 1; i > -1; --i) if (this->arr[i] > other.arr[i]) return true;
    return false;
}


bool Seven::operator<(const Seven& other) {
    return !(*this > other) && !(*this == other);
}


Seven Seven::operator+(const Seven& other) {
    size_t min_size = std::min(this->size, other.size);
    size_t max_size = std::max(this->size, other.size);
    unsigned char new_arr[max_size];
    for (int i = 0; i < min_size; ++i) {
        new_arr[i] = static_cast<unsigned char>(this->arr[i] + other.arr[i] - 48);
    }
    if (this->size > other.size) {
        for (int i = min_size; i < max_size; ++i) {
            new_arr[i] = this->arr[i];
        }
    } else if (this->size < other.size) {
        for (int i = min_size; i < max_size; ++i) {
            new_arr[i] = other.arr[i];
        }
    }
    return Seven(max_size, new_arr);
}


Seven Seven::operator-(const Seven& other) {
    if (*this < other) throw std::invalid_argument("You cannot subtract a number greater than that given in an unsigned type");
    if (*this == other) return Seven(1, '0');
    unsigned char new_arr[this->size];
    for (int i = 0; i < this->size; ++i) {
        new_arr[i] = this->arr[i];
    }
    for (int i = 0; i < other.size; ++i) {
        if (new_arr[i] >= other.arr[i]) {
            new_arr[i] = static_cast<unsigned char>(new_arr[i] - other.arr[i] + 48);
        } else {
            new_arr[i] = static_cast<unsigned char>(new_arr[i] - other.arr[i] + '7');
            for (int j = 1;;++j) {
                if (new_arr[i + j] > '0' && new_arr[i + j] < '7') {
                    --new_arr[i + j]; 
                    break;
                } else if (new_arr[i + j] == '0') {
                    new_arr[i + j] = '6';
                }
            }
        }
    }
    return Seven(this->size, new_arr);
}