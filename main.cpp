#include <iostream>

#include "CLiteMath.h"

int main() {
    Complex<double> z1(1, 1);
    Complex<double> z2(2, 3);
    Complex<double> z3 = z2 - z1;
    std::cout << z3.getReal() << "+" << z3.getImaginary()  << "i" << std::endl;

    Matrix<double, 2, 2> mat = {1, 1, 1, 1};
    return 0;
}
