// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include "CBSTNode.h"


//Constructor
CBSTNode::CBSTNode(int value)
{
    data = value;
    left = nullptr;
    right = nullptr;
}

//Getter data
int CBSTNode::getData() const
{
    return data;
}

//Getter left and right
CBSTNode* CBSTNode::getLeft() const
{
    return left;
}

CBSTNode* CBSTNode::getRight() const
{
    return right;
}

//Setter left and right
void CBSTNode::setLeft(CBSTNode* node)
{
    left = node;
    std::cout << '\n' << left;
}

void CBSTNode::setRight(CBSTNode* node)
{
    right = node;
    std::cout << '\n' << right;
}
