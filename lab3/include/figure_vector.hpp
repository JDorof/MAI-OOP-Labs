#pragma once
#include "./figure.hpp"

class FigureVector
{
    public:
        FigureVector();
        void Resize(int new_size);
        int  Size() const noexcept;
        void Push_back(Figure* val)noexcept;
        const Figure* Get(int ind) const;
        void Remove(int ind) ;

        ~FigureVector();

    private:
        Figure** buf;
        int size_;
        int cap;
        int head;
};