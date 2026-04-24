// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include <stdexcept>
#include "CMatrix.h"
#include "CVector.h"

//Constructor
CMatrix::CMatrix(int iR, int iC) : iColumn(iC), iRow(iR)
{
    if(iColumn < 1) iColumn = 1;
    if(iRow < 1) iRow = 1;

    matValue = new float[iRow * iColumn];

    for(int i = 0; i<iRow * iColumn; i++)
    {
        matValue[i] = 0;
    }
}

//Copy constructor
CMatrix::CMatrix(const CMatrix& toCopy)
{
    this->iRow = toCopy.iRow;
    this->iColumn = toCopy.iColumn;

    this->matValue = new float[iRow * iColumn];

    for(int i = 0; i < iRow * iColumn; i++)
    {
        this->matValue[i] = toCopy[i];
    }
}

//Copy assignment operator
CMatrix& CMatrix::operator=(const CMatrix& toCopy)
{
    if(this == &toCopy) return *this;

    delete[] this->matValue;

    this->iColumn = toCopy.iColumn;
    this->iRow = toCopy.iRow;

    matValue = new float[toCopy.iColumn * toCopy.iRow];

    for(int i = 0; i<iColumn*iRow; i++)
    {
        this->matValue[i] = toCopy.matValue[i];
    }

    return *this;
}

//Destructor
CMatrix::~CMatrix()
{
    delete[] matValue;
}

//Toán tử nhập/xuất ma trận
std::istream& operator>>(std::istream& is, CMatrix& Matrix)
{
    int iRow = 0;

    while(iRow < 1)
    {
        std::cout << "\nNhap so hang cua ma tran: ";
        is >> iRow;
    }

    int iColumn = 0;

    while(iColumn < 1)
    {
        std::cout << "\nNhap so cot cua ma tran: ";
        is >> iColumn;
    }

    Matrix.toResize(iRow, iColumn);

    for(int i = 0; i<iRow; i++)
    {
       for(int j = 0; j<iColumn; j++)
       {
           std::cout << "\nNhap phan tu [" << i+1 << "][" << j+1 << "]: ";
           is >> Matrix[i*iColumn + j];
       }
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const CMatrix& Matrix)
{
    int iRow = Matrix.getRow();
    int iColumn = Matrix.getColumn();

    for(int i = 0; i<iRow * iColumn; i++)
    {
        if(i == 0) os << "/ ";
        else if(i == (iRow * iColumn) - iColumn) os << "\\ ";
        else if(i % iColumn == 0) os << "| ";

        os << Matrix[i] << " ";

        if(i+1 == iColumn) os << "\\\n";
        else if(i == (iRow * iColumn) -1) os << "/\n";
        else if((i+1) % iColumn == 0) os << "|\n";
    }

    return os;
}

//Các phép nhân
CVector CMatrix::operator*(const CVector& Vector)
{
    if(Vector.getSize() != this->iColumn)
    {
        throw std::invalid_argument("So cot cua ma tran khong giong so chieu cua vector.");
    }

    CVector vectorResult(iRow);

    int iCheckedRow = 0;
    for(int i = 0; i<iRow; i++)
    {
        float fResult = 0;

        for(int j = 0; j<iColumn; j++)
        {
            fResult += this->matValue[iCheckedRow * iColumn + j] * Vector[j];
        }

        iCheckedRow++;
        vectorResult[i] = fResult;
    }


    return vectorResult;
}

CMatrix CMatrix::operator*(const CMatrix& toMultiply)
{
    if(this->iColumn != toMultiply.iRow)
    {
        throw std::invalid_argument("So cot cua ma tran 1 khong giong so hang cua ma tran 2.");
    }

    CMatrix matrixResult(this->iRow, toMultiply.iColumn);

    int iM1Row= 0; //Biến lưu số hàng đã xét của ma trận 1
    //i: biến duyệt từng phần tử trong matrixResult
    for(int i = 0; i<this->iRow * toMultiply.iColumn; i++)
    {
        int iM2Row = 0;//Biến lưu số hàng đã xét của ma trận 2
        float fSum = 0;//Tổng giá trị cuối cùng. Giá trị này sẽ được set cho matrixResult[i]

        int iColOffset = i % toMultiply.iColumn;//Offset cho cột của ma trận 2

        //Phần tử [a][b] trong ma trận kết quả
        //= Tổng của M1[a][0->M1.Col - 1] * M2[0->M2.Row - 1][b]
        //j: Biến đếm "a"
        for(int j = 0; j<this->iColumn; j++)
        {
            //Giá trị từ ma trận 1:
            //= (Số hàng đã duyệt * số phần tử của mỗi hàng) + offset.
            // (Số hàng đã duyệt * số phần tử của mỗi hàng) thực chất để bỏ qua giá trị của các hàng
            //đã tính, chỉ tập trung vào hàng hiện tại tương ứng với index trong matrixResult.
            //Offset chính là j, giúp duyệt qua hàng hiện tại
            float fVal1 = (*this)[(iM1Row * this->iColumn) + j];

            //Giá trị của ma trận 2 cũng có ý tưởng tương tự
            float fVal2 = toMultiply[(iM2Row * toMultiply.iColumn) + iColOffset];

            fSum += fVal1 * fVal2;

            //Tăng số hàng đã duyệt của ma trận 2 giúp nhảy cóc đến hàng sau, nhưng cột vẫn như vậy
            //Lí do: iColOffset không đổi sau mỗi vòng lặp j
            iM2Row++;
        }

        matrixResult[i] = fSum;

        //Nếu i đã đến cột cuối của hàng, tăng biến đếm số hàng đã duyệt
        if((i+1) % toMultiply.iColumn == 0) iM1Row++;
    }

    return matrixResult;
}

//Getter hàng và cột
const int CMatrix::getRow() const
{
    return iRow;
}

const int CMatrix::getColumn() const
{
    return iColumn;
}

//Hàm resize ma trận
void CMatrix::toResize(int iR, int iC)
{
    if(matValue != nullptr) delete[] matValue;

    this->iRow = iR;
    this->iColumn = iC;

    matValue = new float[iRow * iColumn];

    for(int i = 0; i<iRow * iColumn; i++)
    {
        matValue[i] = 0;
    }
}

//Overload toán tử []
float& CMatrix::operator[](const int iIndex)
{
    if(iIndex < 0 || iIndex > iRow * iColumn)
    {
        throw std::out_of_range("Ma tran khong ton tai vi tri nay.");
    }

    return matValue[iIndex];
}

const float CMatrix::operator[](const int iIndex) const
{
    if(iIndex < 0 || iIndex > iRow * iColumn)
    {
        throw std::out_of_range("Ma tran khong ton tai vi tri nay.");
    }

    return matValue[iIndex];
}
