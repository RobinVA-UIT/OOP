// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#ifndef CBST_H
#define CBST_H

#include <iostream>
#include "CBSTNode.h"

class CBST
{
private:
    CBSTNode* root;    
public:
    //Constructor
    CBST();
    
    int getRoot() const;

    void insert(int value);
    bool search(int target) const;
    void Delete(int target);

    int minimum() const;
    int maximum() const;

    //Floor: Tìm node có value lớn nhất mà bé hơn hoặc bằng value
    int floor(int value) const;
    
    //Ceil: Tìm node có value bé nhất mà lớn hơn hoặc bằng value
    int ceil(int value) const;

    CBSTNode* predecessor(CBSTNode* k) const;
    CBSTNode* successor(CBSTNode* k) const;

};

#endif // CBST_H
