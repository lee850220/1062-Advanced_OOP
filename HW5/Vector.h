#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <typeinfo>
using namespace std;

template <class T> 
class vector {
    private:
        T *v;
        int sz;
        int count = 0;
    
    public:
        vector(int size);

        ~vector();

        T& elem(int i) {
            return v[i];
        }

        T& operator[] (int i) {
            return v[i];
        }

};

template <> 
class vector<void*> {
    private:
        void **p;
        int sz;
        static int count;
    
    public:
        
        vector(int);
        ~vector();

        void*& elem(int i) {
            return p[i];
        }

        void*& operator[](int i) {
            return p[i];
        }
};


template <class T>
class vector<T*> : private vector<void*> {

    typedef vector<void*> Base;

    public:
        vector(int size);
        ~vector();

        T*& elem(int i) {
            return reinterpret_cast<T*&>(Base::elem(i));
        }

        T*& operator[](int i) {
            return reinterpret_cast<T*&>(Base::operator[](i));
        }
};


#endif