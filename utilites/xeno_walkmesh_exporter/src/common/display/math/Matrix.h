// $Id: Matrix.h 76 2006-08-25 18:41:20Z crazy_otaku $

#ifndef MATRIX_H
#define MATRIX_H
// The Matrix Structs : Represent matrix for math operations


// Matrix elements are specified in row-major order.  This
// means that the translate terms are located in the fourth row and the
// projection terms in the fourth column.  This is consistent with the way
// MAX, Direct3D, and OpenGL all handle matrices.  Even though the OpenGL
// documentation is in column-major form, the OpenGL code is designed to
// handle matrix operations in row-major form.
struct Matrix
{
    Matrix() {};
    Matrix(const float *f);
    Matrix(const Matrix& other);
    Matrix(float v00, float v01, float v02, float v03,
           float v10, float v11, float v12, float v13,
           float v20, float v21, float v22, float v23,
           float v30, float v31, float v32, float v33);

    // access grants
    float& operator () (int Row, int Col)       {return m[Col][Row];}
    float  operator () (int Row, int Col) const {return m[Col][Row];}

    Matrix GetTranspose() const;

    float m[4][4];
};



#endif
