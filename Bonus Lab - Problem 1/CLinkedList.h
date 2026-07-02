// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include <iostream>
#include "CLinkedListNode.h"

class CLinkedList
{
private:
    CLinkedListNode* head;
    CLinkedListNode* tail;
    int iSize;
public:
    //Constructor
    CLinkedList();
    
    //Hàm thêm
    void addFirst(int value);
    void addLast(int value);
    void insertAt(int index, int value);

    //Hàm xóa
    void removeFirst();
    void removeLast();
    void removeValue(int value);
    
    //Xuất giá trị ở đầu linked list
    int peek() const;
    
    //Xuất linked list
    void printList() const;

    //Hàm kiểm tra linked list trống hay không
    bool isEmpty() const;
};

#endif // CLINKEDLIST_H
