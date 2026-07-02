// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include <cassert>
#include "CQueue.h"
#include "CLinkedListNode.h"
#include "CLinkedList.h"

//Constructor
CQueue::CQueue()
{
    queuefront = nullptr;
    queueback = nullptr;
}

//Destructor
CQueue::~CQueue()
{
    queuefront = nullptr;
    queueback = nullptr;
}

//Enqueue and dequeue
void CQueue::enqueue(int value)
{
    if(queuefront == nullptr)
    {
	queuefront = new CLinkedListNode(value);
	queueback = queuefront;
    }

    else
    {
	CLinkedListNode* newNode = new CLinkedListNode(value);
	queueback->insertAddr(newNode);
	queueback = newNode;
    }
}

int CQueue::dequeue()
{
    assert(queuefront != nullptr);    

    int toReturn = queuefront->getData();
    
    CLinkedListNode* newfront = queuefront->getAddrNextNode();
    delete queuefront;
    queuefront = newfront;
    
    return toReturn;
}

bool CQueue::isEmpty() const
{
    return (queuefront == nullptr);
}

int CQueue::peek() const
{
    return queuefront->getData();
}

