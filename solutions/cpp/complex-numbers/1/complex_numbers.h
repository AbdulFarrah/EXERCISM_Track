#pragma once
#include <cmath>
namespace complex_numbers {
// TODO: add your solution here
class Complex {
public:
    Complex(double real, double imag = 0.0);
    double real() const;
    double imag() const;
    double abs() const;
    Complex conj() const;
    Complex exp() const;
    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    Complex operator/(const Complex&) const;
private:
    double realpart;
    double imagpart;
};
Complex operator/(double, const Complex&);
Complex operator*(double, const Complex&);
Complex operator+(double, const Complex&);
Complex operator-(double, const Complex&);
}  // namespace complex_numbers
