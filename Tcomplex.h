#pragma once
#include <iostream>
using namespace std;


class TComplex {
public:
    double re, im;
    TComplex();
    TComplex(const int&);
    TComplex operator* (TComplex);
    void operator*= (TComplex);
    void operator/= (TComplex);
    void operator-= (TComplex);
    friend ostream& operator<<(ostream&, TComplex);
    friend istream& operator>>(istream&, TComplex&);
};

double abs(TComplex);
