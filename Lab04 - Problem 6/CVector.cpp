// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include "CVector.h"

//Constructor
CVector::CVector(int iS) : iSize(iS)
{
    if(iSize < 1) iSize = 1;

    arrValue = new float[iSize];

    for(int i = 0; i<iSize; i++)
    {
        arrValue[i] = 0;
    }
}

//Destructor
CVector::~CVector()
{
    delete[] arrValue;
    arrValue = nullptr;
}

//Toán tử nhập, xuất
std::istream& operator>>(std::istream& is, CVector& Vector)
{
    int iSizeInput = 0;

    while(iSizeInput < 1)
    {
        std::cout << "Nhap chieu cua vector: ";
        is >> iSizeInput;
    }
    if(iSizeInput != Vector.getSize()) Vector.toResize(iSizeInput);

    for(int i = 0; i<iSizeInput; i++)
    {
        std::cout << "\nNhap phan tu thu " << i+1 << " cua vector: ";
        is >> Vector[i];
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const CVector& Vector)
{
    int iSize = Vector.getSize();

    for(int i = 0; i<iSize; i++)
    {
        if(i == 0) os << "/ ";
        else if(i < iSize - 1) os << "| ";
        else os << "\\ ";

        os << Vector[i];

        if(i == 0) os << " \\\n";
        else if(i < iSize - 1) os << " |\n";
        else os << " /";
    }

    return os;
}

//Hàm resize mảng giá trị
void CVector::toResize(int iSizeInput)
{
    delete[] arrValue;

    iSize = iSizeInput;

    arrValue = new float[iSize];

    for(int i = 0; i<iSize; i++)
        arrValue[i] = 0;
}

//Nạp chồng toán tử []
float& CVector::operator[](const int iIndex)
{
    if(iIndex < 0 || iIndex > iSize -1 )
    {
        throw std::out_of_range("Khong ton tai phan tu " + std::to_string(iIndex) + " trong vector nay.");
    }

    return arrValue[iIndex];
}

const float CVector::operator[](const int iIndex) const
{
    if(iIndex < 0 || iIndex > iSize -1 )
    {
        throw std::out_of_range("Khong ton tai phan tu " + std::to_string(iIndex) + " trong vector nay.");
    }

    return arrValue[iIndex];
}

//Getter size
const int CVector::getSize() const
{
    return iSize;
}
