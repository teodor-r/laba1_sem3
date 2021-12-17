

#include "complex.h"


complex::complex()
{
    this->real = 0.;
    this->imagine = 0.;
}

complex::complex(float a, float b)
{
    this->real = a;
    this->imagine = b;
}

complex enter_complex ()
{
    float real, imagine;
    scanf ("%f %f", &real, &imagine);
    return complex(real, imagine);
}

complex complex_conj (complex a)
{
    return complex(a.real, (-1) * a.imagine);
}

complex complex_mult (complex a, complex b)
{
    complex rez;
    rez.real = a.real * b.real - a.imagine * b.imagine;
    rez.imagine = a.imagine * b.real + b.imagine * a.real;
    return rez;
}

complex complex_sum (complex a, complex b)
{
    complex rez;
    rez.real = a.real + b.real;
    rez.imagine = a.imagine + b.imagine;
    return rez;
}

complex complex_sub (complex a, complex b)
{
    complex rez;
    rez.real = a.real - b.real;
    rez.imagine = a.imagine - b.imagine;
    return rez;
}

complex complex_div (complex a, complex b)
{
    if (b.real * b.real + b.imagine * b.imagine == 0)
    {
        printf ("Division by zero!\n");
        exit(1);
    }
    complex tmp = complex_mult (a, complex_conj(b));
    return (complex_mult(tmp, complex(1.0 / (b.real * b.real + b.imagine * b.imagine), 0)));
}

bool isequal_cmp (complex a, complex b)
{
    if ((a.real == b.real) && (a.imagine == b.imagine))
        return true;
    return false;
}

bool isequal_cmp (complex a, float b)
{
    if ((a.imagine == 0.) && (a.real == b))
        return true;
    return false;
}

complex complex::operator+ (complex other)
{
    return complex_sum(*this, other);
}

complex complex::operator* (complex other)
{
    return complex_mult(*this, other);
}

complex complex::operator- (complex other)
{
    return complex_sub(*this, other);
}

complex complex::operator/ (complex other)
{
    return complex_div(*this, other);
}

bool complex::operator== (complex other)
{
    return isequal_cmp(*this, other);
}

bool complex::operator==(float other) {
    return isequal_cmp(*this, other);
}

bool complex::operator!=(complex other) {
    return !(*this == other);
}

bool complex::operator!=(float other) {
    return !(*this == other);
}

complex::complex(float Real)
{
    this->imagine = 0;
    this->real = Real;
}

complex complex::operator*(int a) {
    return (*this * complex((float)a, 0));
}

complex complex::operator*(float a){
    return (*this * complex(a, 0));
}

std::ostream& operator<<(std::ostream& out, complex this1) {
    if (this1.real * this1.real + this1.imagine * this1.imagine == 0)
        out << "0";
    else if (this1.real == 0)
        out << this1.imagine << "i";
    else if (this1.imagine == 1)
        out << this1.real << " + i";
    else if (this1.imagine == -1)
        out << this1.real << " - i";
    else if (this1.imagine == 0)
        out << this1.real;
    else if (this1.imagine > 0)
        out << this1.real << " + " << this1.imagine << "i";
    else if (this1.imagine < 0)
        out << this1.real << " - " << -1 * this1.imagine << "i";
    return out;
}

std::istream& operator>>(std::istream &in, complex &c) {
    in >> c.real;
    in >> c.imagine;
    return in;
}

float complex::module() {
    return sqrt (real * real + imagine * imagine);
}
