// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#ifndef CLINKEDLISTNODE_H
#define CLINKEDLISTNODE_H

#include <iostream>

class CLinkedListNode 
{
private:
    int iData;
    CLinkedListNode* nextNode;
public:
    //Constructor
    CLinkedListNode(int iD = 0);

    //Destructor
    ~CLinkedListNode();

    void insertAddr(CLinkedListNode* addr);

    CLinkedListNode* getAddrNextNode() const;
    
    int getData() const;
};

#endif // CLINKEDLISTNODE_H
