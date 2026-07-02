// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#ifndef CBSTNODE_H
#define CBSTNODE_H

#include <iostream>

class CBSTNode
{
private:
    int data;
    CBSTNode* left;
    CBSTNode* right;
public:
    //Constructor
    CBSTNode(int value);

    //Getter data
    int getData() const;

    //Getter left and right
    CBSTNode* getLeft() const;
    CBSTNode* getRight() const;

    //Setter left and right
    void setLeft(CBSTNode* node);
    void setRight(CBSTNode* node);
};

#endif // CBSTNODE_H
