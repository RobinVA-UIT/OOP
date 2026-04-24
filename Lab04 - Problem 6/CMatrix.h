// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#ifndef CMATRIX_H_INCLUDED
#define CMATRIX_H_INCLUDED

#include <iostream>
#include "CVector.h"

class CMatrix
{
private:
    int iColumn;
    int iRow;
    float* matValue;

public:
    //Constructor
    CMatrix(int iR = 1, int iC = 1);

    //Copy constructor
    CMatrix(const CMatrix& toCopy);

    //Copy assignment operator
    CMatrix& operator=(const CMatrix& toCopy);

    //Destructor
    ~CMatrix();

    //Toán tử nhập/xuất ma trận
    friend std::istream& operator>>(std::istream& is, CMatrix& Matrix);
    friend std::ostream& operator<<(std::ostream& os, const CMatrix& Matrix);

    //Các phép nhân
    CVector operator*(const CVector& Vector);
    CMatrix operator*(const CMatrix& toMultiply);

    //Getter hàng và cột
    const int getRow() const;
    const int getColumn() const;

    //Hàm resize ma trận
    void toResize(int iR, int iC);

    //Overload toán tử []
    float& operator[](const int iIndex);
    const float operator[](const int iIndex) const;
};


#endif // CMATRIX_H_INCLUDED
