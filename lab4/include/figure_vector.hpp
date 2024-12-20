#pragma once
#include "./figure.hpp"

template<Scalar T>
class FigureVector
{
    public:
        FigureVector();
        void Resize(int new_size);
        int  Size() const noexcept;
        void Push_back(Figure<T>* val)noexcept;
        const Figure<T>* Get(int ind) const;
        void Remove(int ind) ;

        ~FigureVector();

    private:
        Figure<T>** buf;
        int size_;
        int cap;
        int head;
};