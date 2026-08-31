#include "complex_numbers.h"
namespace complex_numbers {
// TODO: add your solution here
Complex::Complex(double r,double i)
{
    realpart=r;imagpart=i;
}
double Complex::real() const
{
    return realpart;
}
double Complex::imag() const
{
    return imagpart;
}
double Complex::abs() const
{
    return sqrt((realpart*realpart)+(imagpart*imagpart));
}
Complex Complex::conj() const
{
    return Complex(realpart,-imagpart);
}
Complex Complex::exp() const
{
    return Complex(std::exp(realpart) * std::cos(imagpart),std::exp(realpart) * std::sin(imagpart));
}
Complex Complex::operator+(const Complex& other) const
{
    return Complex(realpart + other.realpart,imagpart + other.imagpart);
}
Complex Complex::operator-(const Complex& other) const
{
    return Complex(realpart - other.realpart,imagpart - other.imagpart);
}
Complex Complex::operator*(const Complex& other) const
{
    return Complex((realpart * other.realpart) - (imagpart * other.imagpart),(imagpart * other.realpart)+(realpart*other.imagpart));
}
Complex Complex::operator/(const Complex& other) const
{
    return Complex(((realpart * other.realpart)+(imagpart * other.imagpart))/((other.realpart*other.realpart)+(other.imagpart*other.imagpart)),((imagpart * other.realpart)-(realpart*other.imagpart))/((other.realpart*other.realpart)+(other.imagpart*other.imagpart)));
}
Complex operator/(double lhs, const Complex& rhs)
{
    return Complex(lhs) / rhs;
}
Complex operator*(double lhs, const Complex& rhs)
{
    return Complex(lhs) * rhs;
}
Complex operator-(double lhs, const Complex& rhs)
{
    return Complex(lhs) - rhs;
}
Complex operator+(double lhs, const Complex& rhs)
{
    return Complex(lhs) + rhs;
}
    
}  // namespace complex_numbers
