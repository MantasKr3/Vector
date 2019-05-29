#ifndef VEKTORIUKSTIS_H
#define VEKTORIUKSTIS_H

#include <iostream>
#include <string>
#include <string.h>
#include <iterator>
#include <cstddef>
#include <cstring>
#include <utility>
#include <iterator>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include <utility>
#include <iterator>
#include <stdexcept>
template <typename T>
class Vector{

private:
size_t vsize_;
size_t cap_; 
T *arr_;
public:
typedef T *pointer;
typedef T *iterator;

 pointer begin()
    {
        pointer it;
        it = (&arr_[0]);
        return it;
    }
    pointer end()
    {
        pointer it;
        it = &arr_[vsize_ - 1];
        return it;
    };
   
    Vector()
    {
        cap_ = 20;
        arr_ = new T[cap_];
        vsize_ = 0;
    };
    Vector(T i)
    {
        cap_ = i;
        arr_ = new T[cap_];
        vsize_ = 0;
    };
Vector(const Vector &vec)
    {
        cap_ = vec.cap_;
        vsize_ = vec.vsize_;
        arr_ = new T[cap_];
        for (size_t i = 0; i <= vec.vsize_; i++)
        {
            arr_[i] = vec.arr_[i];
        }
    };

~Vector()
    {
        delete[] arr_;
    };

     Vector& operator=(const Vector& v) {
        if (&v == this) return *this; 
        T* laikinas = new T[v.vsize_];
        for (size_t i=0; i!=v.vsize_; i++)
            laikinas[i] = v.arr_[i];
        delete[] arr_; 
        arr_ = laikinas;    
        vsize_ = v.vsize_;    
        cap_=v.capacity();
        return *this;  
    }

    T operator[](size_t i){

        if (i < vsize_)
        return arr_[i];
        throw std::out_of_range("out of range");
    }

size_t size() const { return vsize_; }
size_t capacity() const { return cap_; }

bool empty()
    {
        if (vsize_ == 0)
            return true;
        else
            return false;
    }
    
void assign(size_t val, T data) {
        vsize_ = val;
        cap_ = val;
        delete[] arr_;
        T * other = new T[vsize_];
        std::fill_n(other, vsize_, data);
        arr_ = other;
    }
       void erase(size_t val) {
        if (val < 0 || val >= vsize_)
            return;
        vsize_--;
        std::move(&arr_[val + 1], &arr_[vsize_], &arr_[val]);
    }

    void clear()
    {
        vsize_ = 0;
        delete[] arr_;
        arr_ = new T[cap_];
    }

        void push_back(T data) {
        if (vsize_ >= cap_){
            resize(vsize_*2);
        }
        arr_[vsize_] = data;
        vsize_++;
    }
  void pop_back()
    {
        vsize_ = vsize_ - 1;
        T *laikinas = new T[vsize_];
        for (size_t i = 0; i < vsize_; i++)
            laikinas[i] = arr_[i];
        delete[] arr_;
        arr_ = laikinas;
    };
iterator resize(size_t dydis) {
        if (dydis == 0) { 
            vsize_ = 0;
            cap_ = 2;
            T *other = new T[cap_];
            delete[] arr_;
            arr_ = other;
            return 0;
        }
        size_t lim;
        T *other = new T[dydis]; 
        if (dydis < vsize_) {
            vsize_ = dydis;
            lim = dydis;
        }
        else lim = vsize_;
        std::move(&arr_[0], &arr_[lim], other);
        cap_ = dydis;
        delete[] arr_; 
        arr_ = other;
    }
    
};


#endif
