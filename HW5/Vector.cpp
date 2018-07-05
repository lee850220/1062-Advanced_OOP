#include "Vector.h"
#include "Trace.h"

template <class T>
vector<T>::vector(int size) {
    TRACE(dummy, "vector<T>::vector(int)");
    v = new T[size];
    sz = size;   
    cout << "  count = " << ++count << endl;
}

template <class T>
vector<T>::~vector() {
    TRACE(dummy, "vector<T>::~vector");
    cout << "  count = " << count-- << endl;
    delete [] v;
}

int vector<void*>::count = 0;
vector<void*>::vector(int size) {
    TRACE(dummy, "vector<void*>::vector(int)");
    p = new void*[size];
    sz = size;
    cout << "  count = " << ++vector::count << endl;
}

vector<void*>::~vector() {
    TRACE(dummy, "vector<void*>::~vector");
    cout << "  count = " << vector::count-- << endl;
    delete [] p;
}

template <class T>
vector<T*>::vector(int size) : Base(size) {
    TRACE(dummy, "vector<T*>::vector(int)");

}

template <class T>
vector<T*>::~vector() {
    TRACE(dummy, "vector<T*>::~vector");
}

template class vector<float>;
template class vector<int>;
template class vector<char>;
template class vector<void*>;
template class vector<float*>;
template class vector<int*>;
template class vector<char*>;
