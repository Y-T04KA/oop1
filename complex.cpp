#include "Tcomplex.h"
#include <iostream>

complex::complex() {

}

complex::complex(const int& r) {
	re = r;
	im = 0;
}

complex complex::operator*(complex c) {
	complex t;
	t.re = re*c.re - im*c.im;
	t.im = re*c.im + im*c.re;
	return t;
}

void complex::operator*=(complex c) {
	complex t;
	t.re = re * c.re - im * c.im;
	t.im = re * c.im + im * c.re;
	re = t.re;
	im = t.im;
}

void complex::operator/=(complex c) {
	complex t;
	t.re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
	t.im = (c.re * im - re * c.im) / (c.re * c.re + c.im * c.im);
	re = t.re;
	im = t.im;
}

void complex::operator-=(complex c) {
	complex t;
	t.re = re - c.re;
	t.im = im - c.im;
	re = t.re;
	im = t.im;
}

double complex::abs() {
	double i = std::sqrt(re * re + im * im);
	return i;
}

ostream& operator<<(ostream& os, complex c) {
	os << c.re << "+" << c.im << "i";
	return os;
};

istream& operator>>(istream& is, complex c) {
	is >> c.re >> c.im;
	return is;
};