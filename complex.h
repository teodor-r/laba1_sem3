
#ifndef LAB2_VECTOR_COMPLEX_H
#define LAB2_VECTOR_COMPLEX_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

class complex
{
public:
    float real, imagine;
    complex (float, float);
    complex ();
    complex (float);
    float module ();
    complex operator+(complex);
    complex operator*(complex);
    complex operator*(int);
    complex operator*(float);
    complex operator-(complex);
    complex operator/(complex);
    bool operator==(complex);
    bool operator==(float);
    bool operator!=(complex);
    bool operator!=(float);
};

std::ostream& operator<<(std::ostream &, complex);

std::ostream& operator>>(std::ostream &, complex);

complex enter_complex ();

complex complex_conj (complex );

complex complex_mult (complex , complex );

complex complex_sum (complex , complex );

complex complex_sub (complex, complex);

complex complex_div (complex , complex );

bool isequal_cmp (complex , complex);

bool isequal_cmp (complex, float);

#endif //LAB2_VECTOR_COMPLEX_H
