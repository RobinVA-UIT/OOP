// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include "CLinkedListNode.h"

//Constructor
CLinkedListNode::CLinkedListNode(int iD)
	    : iData(iD)
{
    nextNode = nullptr;
}

//Destructor
CLinkedListNode::~CLinkedListNode()
{
    nextNode = nullptr;
}

void CLinkedListNode::insertAddr(CLinkedListNode* addr)
{
    nextNode = addr;
}

CLinkedListNode* CLinkedListNode::getAddrNextNode() const
{
    return nextNode;
}


int CLinkedListNode::getData() const
{
    return iData;
}
