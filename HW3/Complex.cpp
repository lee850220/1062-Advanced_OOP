#include "Complex.h"

Complex::Complex(const double re, const double im) {
    real = re;
    imag = im;
}

Complex::Complex(const Complex& c) {
    real = c.real;
    imag = c.imag;
}

Complex::~Complex() {
    //do nothing
}

Complex Complex::Polar(const double leng, const double arg) {
    real = leng * cos(arg);
    imag = leng * sin(arg);
    return *this;
}

Complex Polar(const double leng, const double arg) {
    return Complex(leng * cos(arg), leng * sin(arg));
}

double Complex::Real() {
    return real;
}

double Complex::Imag() {
    return imag;
}

double Complex::Norm() {
    return pow(real, 2) + pow(imag, 2);
}

double Complex::Abs() {
    return sqrt(Norm());
}

double Complex::Arg() {
    return atan2(imag, real);
}

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    imag = c.imag;
    return *this;
}

Complex Complex::operator++() {
    return Complex(++real, ++imag);
}

Complex Complex::operator++(int) {
    return Complex(real++, imag++);
}

double Norm(const Complex& x) {
    return pow(x.real, 2) + pow(x.imag, 2);
}

double Abs(const Complex& x) {
    return sqrt(Norm(x));
}

double Arg(const Complex& x) {
    return atan2(x.imag, x.real);
}

Complex operator+(const Complex& x, const Complex& y) {
    Complex complex;
    complex.real = x.real + y.real;
    complex.imag = x.imag + y.imag;
    return complex;    
}

Complex operator-(const Complex& x, const Complex& y) {
    Complex complex;
    complex.real = x.real - y.real;
    complex.imag = x.imag - y.imag;
    return complex;    
}

Complex operator*(const Complex& x, const Complex& y) {
    Complex complex;
    complex.real = x.real * y.real - x.imag * y.imag;
    complex.imag = x.real * y.imag + x.imag * y.real;
    return complex;    
}

Complex operator/(const Complex& x, const Complex& y) {
    Complex complex;
    complex.real = (x.real * y.real + x.imag * y.imag) / (pow(y.real, 2) + pow(y.imag, 2));
    complex.imag = (x.imag * y.real - x.real * y.imag) / (pow(y.real, 2) + pow(y.imag, 2));
    return complex;    
}

Complex operator+=(Complex& x, const Complex& y) {
    x.real += y.real;
    x.imag += y.imag;
    return x;    
}

Complex operator-=(Complex& x, const Complex& y) {
    x.real -= y.real;
    x.imag -= y.imag;
    return x;    
}

Complex operator*=(Complex& x, const Complex& y) {
    double rt;
    rt = x.real * y.real - x.imag * y.imag;
    x.imag = x.real * y.imag + x.imag * y.real;
    x.real = rt;
    return x;    
}

Complex operator/=(Complex& x, const Complex& y) {
    double rt;
    rt = (x.real * y.real + x.imag * y.imag) / (pow(y.real, 2) + pow(y.imag, 2));
    x.imag = (x.imag * y.real - x.real * y.imag) / (pow(y.real, 2) + pow(y.imag, 2));
    x.real = rt;
    return x;    
}

bool operator==(const Complex& x, const Complex& y) {
    return (x.real == y.real && x.imag == y.imag);
}

bool operator!=(const Complex& x, const Complex& y) {
    return (x.real != y.real && x.imag != y.imag);
}

ostream& operator<<(ostream& o, const Complex& x) {
    o << '(' << x.real << ',' << x.imag << ')';
    return o;
}