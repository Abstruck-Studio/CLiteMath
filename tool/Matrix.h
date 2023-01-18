//
// Created by Goulixiaoji on 2023/1/18.
//

#ifndef CLITEMATH_MATRIX_H
#define CLITEMATH_MATRIX_H

template <typename T, int width, int height>
class Matrix {
public:
    Matrix();

    T* operator [] (int index);
    void operator = (T **elementsIn);

private:
    T elements[width][height];
};

template<typename T, int width, int height>
void Matrix<T, width, height>::operator=(T **elementsIn) {
    this -> elements = elementsIn;
}

template<typename T, int width, int height>
T *Matrix<T, width, height>::operator[](int index) {
    return this -> elements[index];
}

template<typename T, int width, int height>
Matrix<T, width, height>::Matrix() {

}


#endif //CLITEMATH_MATRIX_H
