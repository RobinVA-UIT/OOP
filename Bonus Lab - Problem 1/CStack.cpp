// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include "CStack.h"
#include <cassert>

//Constructor
CStack::CStack()
{
    iTop = -1;
}


//Push
void CStack::push(int x)
{
    assert(iTop < MAXN - 1);
    ++iTop;
    arr[iTop] = x;
}

//Pop
void CStack::pop()
{
    assert(iTop >= 0);
    --iTop;
}

//Kiểm tra xem stack có empty hay không
bool CStack::isEmpty() const
{
    return (iTop == -1)? true : false;

}

//Peek
int CStack::peek() const
{
    assert(iTop > -1);
    
    return arr[iTop];
}

