#pragma once

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <utility>
#include <string>

class Seven {
public:
    unsigned char* arr;
    size_t size;

public:
    Seven();
    Seven(const size_t n, const unsigned char c);
private:
    Seven(const size_t n, const unsigned char* c);
public:
    Seven(const std::initializer_list<unsigned char>& init);
    Seven(const std::string &t);
    Seven(const Seven& other);
    Seven& operator=(const Seven& other);
    Seven& operator=(Seven&& other) noexcept;
    Seven(Seven&& other) noexcept; 
    virtual ~Seven() noexcept;

    bool operator==(const Seven& other);
    bool operator!=(const Seven& other);
    bool operator>(const Seven& other);
    bool operator<(const Seven& other);

    Seven operator+(const Seven& other);
    Seven operator-(const Seven& other);

private:
    void Numerical_optimization();
};