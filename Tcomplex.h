#pragma once
#include <iostream>
using namespace std;
/*class TTComplex<double> {
public:
    typedef double value_type;

    constexpr TTComplex(double re = 0.0, double im = 0.0);
    constexpr TTComplex(const TTComplex<float>&);
    explicit constexpr TTComplex(const TTComplex<long double>&);

    constexpr double real() const;
    constexpr void real(double);
    constexpr double imag() const;
    constexpr void imag(double);

    constexpr TTComplex<double>& operator= (double);
    constexpr TTComplex<double>& operator+=(double);
    constexpr TTComplex<double>& operator-=(double);
    constexpr TTComplex<double>& operator*=(double);
    constexpr TTComplex<double>& operator/=(double);

    constexpr TTComplex<double>& operator=(const TTComplex<double>&);
    template<class X> constexpr TTComplex<double>& operator= (const TTComplex<X>&);
    template<class X> constexpr TTComplex<double>& operator+=(const TTComplex<X>&);
    template<class X> constexpr TTComplex<double>& operator-=(const TTComplex<X>&);
    template<class X> constexpr TTComplex<double>& operator*=(const TTComplex<X>&);
    template<class X> constexpr TTComplex<double>& operator/=(const TTComplex<X>&);
};*/

//template<class T>
//class TComplex {
//public:
//    typedef T value_type;
//    constexpr TComplex(const T& re = T(), const T& im = T());
//    constexpr TComplex(const TComplex&);
//    template<class X> constexpr TComplex(const TComplex<X>&);
//
//    constexpr T real() const;
//    constexpr void real(T);
//    constexpr T imag() const;
//    constexpr void imag(T);
//
//    constexpr TComplex<T>& operator= (const T&);
//    constexpr TComplex<T>& operator+=(const T&);
//    constexpr TComplex<T>& operator-=(const T&);
//    constexpr TComplex<T>& operator*=(const T&);
//    constexpr TComplex<T>& operator/=(const T&);
//
//    constexpr TComplex& operator=(const TComplex&);
//    template<class X> constexpr TComplex<T>& operator= (const TComplex<X>&);
//    template<class X> constexpr TComplex<T>& operator+=(const TComplex<X>&);
//    template<class X> constexpr TComplex<T>& operator-=(const TComplex<X>&);
//    template<class X> constexpr TComplex<T>& operator*=(const TComplex<X>&);
//    template<class X> constexpr TComplex<T>& operator/=(const TComplex<X>&);
//};

class complex {
    double re, im;
public:
    complex();
    complex(const int&);
    complex operator* (complex);
    void operator*= (complex);
    void operator/= (complex);
    void operator-= (complex);
    double abs();
    friend ostream& operator<<(ostream&, complex);
    friend istream& operator>>(istream&, complex);
};