//
// Created by Goulixiaoji on 2023/1/18.
//

#ifndef CLITEMATH_COMPLEX_H
#define CLITEMATH_COMPLEX_H

template <typename T>
class Complex {
public:
    Complex(T realIn, T imaginaryIn);

    T getReal();
    T getImaginary();
    Complex<T> getConjugate();

    Complex<T>& operator + (Complex<T> &z);
    Complex<T>& operator - (Complex<T> &z);
    Complex<T>& operator * (Complex<T> &z);
    Complex<T>& operator / (Complex<T> &z);
    Complex<T>& operator % (Complex<T> &z);

    Complex<T>& operator + ();
    Complex<T>& operator - ();

    bool operator == (Complex<T> &z);
    bool operator != (Complex<T> &z);

    void operator = (Complex<T> &z);
    void operator += (Complex<T> &z);
    void operator -= (Complex<T> &z);
    void operator *= (Complex<T> &z);
    void operator /= (Complex<T> &z);
    void operator %= (Complex<T> &z);

private:
    T real, imaginary;
};

template<typename T>
Complex<T>& Complex<T>::operator-() {
    return Complex<T>(-(this -> real), -(this -> imaginary));
}

template<typename T>
Complex<T>& Complex<T>::operator+() {
    return *this;
}

template<typename T>
bool Complex<T>::operator!=(Complex<T> &z) {
    return ((this -> real != z.real) || (this -> imaginary != z.imaginary));
}

template<typename T>
bool Complex<T>::operator==(Complex<T> &z) {
    return ((this -> real == z.real) && (this -> imaginary == z.imaginary));
}

template<typename T>
void Complex<T>::operator%=(Complex<T> &z) {
    Complex<T> complex(this -> real, this -> imaginary);
    (*this) = complex % z;
}

template<typename T>
void Complex<T>::operator/=(Complex<T> &z) {
    Complex<T> complex(this -> real, this -> imaginary);
    (*this) = complex / z;
}

template<typename T>
void Complex<T>::operator*=(Complex<T> &z) {
    Complex<T> complex(this -> real, this -> imaginary);
    (*this) = complex * z;
}

template<typename T>
void Complex<T>::operator-=(Complex<T> &z) {
    this -> real -= z.real;
    this -> imaginary -= z.imaginary;
}

template<typename T>
void Complex<T>::operator=(Complex<T> &z) {
    this -> real = z.real;
    this -> imaginary = z.imaginary;
}

template<typename T>
void Complex<T>::operator+=(Complex<T> &z) {
    this -> real += z.real;
    this -> imaginary += z.imaginary;
}

template<typename T>
Complex<T>& Complex<T>::operator%(Complex<T> &z) {
    Complex<T> complex(this -> real, this -> imaginary);
    while (complex.real > z.real && complex.imaginary > z.imaginary){
        complex -= z;
    }
    return complex;
}

template<typename T>
Complex<T>& Complex<T>::operator/(Complex<T> &z) {
    Complex<T> conjugate = z.getConjugate();
    Complex<T> complex = (*this) * (conjugate);
    T dividend = (z.getReal() * z.getReal() + z.getImaginary() * z.getImaginary());
    return Complex((complex.getReal()) / dividend,
                   (complex.getImaginary() / dividend));
}

template<typename T>
Complex<T>& Complex<T>::operator*(Complex<T> &z) {
    return Complex<T>(((this -> real) * (z.real)) - ((this -> imaginary) * (z.imaginary)),
                      ((this -> real) * (z.imaginary)) + ((this -> imaginary) * (z.real)));
}

template<typename T>
Complex<T>& Complex<T>::operator-(Complex<T> &z) {
    return Complex<T>((this -> real) - (z.real),
                      (this -> imaginary) - (z.imaginary));
}

template<typename T>
Complex<T>& Complex<T>::operator+(Complex<T> &z) {
    return Complex<T>((this -> real) + (z.real),
                      (this -> imaginary) + (z.imaginary));
}

template<typename T>
Complex<T> Complex<T>::getConjugate() {
    return Complex<T>(this -> real, -(this -> imaginary));
}

template<typename T>
T Complex<T>::getImaginary() {
    return this -> imaginary;
}

template<typename T>
T Complex<T>::getReal() {
    return this -> real;
}

template<typename T>
Complex<T>::Complex(T realIn, T imaginaryIn) : real(realIn), imaginary(imaginaryIn){

}


#endif //CLITEMATH_COMPLEX_H
