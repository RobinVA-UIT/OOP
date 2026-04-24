// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include "CVector.h"
#include "CMatrix.h"

using namespace std;

int main()
{
    CMatrix matrix1, matrix2;
    CVector Vector;

    cout << "Nhap vector:\n";
    cin >> Vector;
    cout << "\n\nVector =\n";
    cout << Vector;

    cout << "\n\nNhap ma tran 1:\n";
    cin >> matrix1;
    cout << "\n\nMa tran 1 =\n";
    cout << matrix1;

    cout << "\n\nMa tran 1 * Vector =\n";
    cout << endl <<  matrix1 * Vector;


    cout << "\n\nNhap ma tran 2:\n";
    cin >> matrix2;
    cout << "\n\nMa tran 2 =\n";
    cout << matrix2;

    cout << "\n\nMa tran 1 * Ma tran 2 =\n";
    cout << endl << matrix1 * matrix2;

    return 0;
}
