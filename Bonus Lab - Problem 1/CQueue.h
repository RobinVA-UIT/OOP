// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#ifndef CQUEUE_H
#define CQUEUE_H

#include <iostream>
#include "CLinkedList.h"
#include "CLinkedListNode.h"

class CQueue
{
private:
    CLinkedListNode* queuefront;
    CLinkedListNode* queueback;
public:
    //Constructor
    CQueue();

    //Destructor
    ~CQueue();

    //Enqueue and dequeue
    void enqueue(int value);
    int dequeue();
    int peek() const;

    bool isEmpty() const;
};

#endif // CQUEUE_H
