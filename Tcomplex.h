#pragma once
#include <iostream>
using namespace std;


class complex {
public:
    double re, im;
    complex();
    complex(const int&);
    complex operator* (complex);
    void operator*= (complex);
    void operator/= (complex);
    void operator-= (complex);
    friend ostream& operator<<(ostream&, complex);
    friend istream& operator>>(istream&, complex&);
};

double abs(complex);
