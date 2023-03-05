#pragma once
#include <iostream>
using namespace std;


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