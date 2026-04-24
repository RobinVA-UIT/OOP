// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#ifndef CVECTOR_H_INCLUDED
#define CVECTOR_H_INCLUDED

#include <iostream>

class CVector
{
private:
    float* arrValue;
    int iSize;

    //Hàm resize mảng giá trị
    void toResize(int iSizeInput);

public:
    //Constructor
    CVector(int iS = 1);

    //Destructor
    ~CVector();

    //Toán tử nhập, xuất
    friend std::istream& operator>>(std::istream& is, CVector& Vector);
    friend std::ostream& operator<<(std::ostream& os, const CVector& Vector);

    //Nạp chồng toán tử []
    float& operator[](const int iIndex);
    const float operator[](const int iIndex) const;

    //Getter size
    const int getSize() const;
};

#endif // CVECTOR_H_INCLUDED
