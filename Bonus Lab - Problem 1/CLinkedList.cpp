// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include <cassert>
#include "CLinkedList.h"
#include "CLinkedListNode.h"

//Constructor
CLinkedList::CLinkedList()
{
    head = nullptr;
    tail = nullptr;
    iSize = 0;
}



//Hàm thêm
void CLinkedList::addFirst(int value)
{
    CLinkedListNode* newNode = new CLinkedListNode(value);
    
    if(iSize == 0)
    {
	head = newNode;
	tail = newNode;

    }

    else
    {
	newNode->insertAddr(head);
    }
    
    ++iSize;
}

void CLinkedList::addLast(int value)
{
    if(iSize == 0)
    {
	addFirst(value);
	return;
    }

    CLinkedListNode* newNode = new CLinkedListNode(value);
    
    tail->insertAddr(newNode);
    tail = newNode;
    
    ++iSize;
}

void CLinkedList::insertAt(int index, int value)
{
    assert(index > -1 && index < iSize);
    
    if(iSize == 0)
    {
	addFirst(value);
	return;
    }
    
    if(index == 0)
    {
	CLinkedListNode* newNode = new CLinkedListNode(value);
	newNode->insertAddr(head);
	head = newNode;
	return;
    }
    
    //Nếu index không phải ở đầu
    //Ta lấy node đằng trước nodeAtIndex (tempNode)
    //Nối nextNode của tempNode này với newNode
    //Đồng thời nối nextNode của newNode với nodeAtIndex
    CLinkedListNode* newNode = new CLinkedListNode(value);
    CLinkedListNode* nodeAtIndex = head;
    CLinkedListNode* tempNode = head;
    
    while(index != 0)
    {
	nodeAtIndex = nodeAtIndex->getAddrNextNode();

	if(index > 1)
	    tempNode = nodeAtIndex;
	
	--index;
    }
    
    tempNode->insertAddr(newNode);
    newNode->insertAddr(nodeAtIndex);

    ++iSize;
}

//Hàm xóa
void CLinkedList::removeFirst()
{
    assert(iSize > 0);    

    CLinkedListNode* tempNode = head->getAddrNextNode();
    delete head;
    head = tempNode;
    --iSize;
}

void CLinkedList::removeLast()
{
    assert(iSize > 0);
    //newTail = node đằng trước tail
    //sửa nextAddr của newTail = null
    CLinkedListNode* newTail = head;
    
    while(newTail->getAddrNextNode() != tail)
    {
	newTail = newTail->getAddrNextNode();
    }

    delete tail;
    tail = newTail;
    tail->insertAddr(nullptr);
    --iSize;
}

void CLinkedList::removeValue(int value)
{
    assert(iSize > 0);
    CLinkedListNode* ptr = head;   

    while(true)
    {
	if(ptr->getData() == value)
	{   
	    if(iSize == 1)
	    {
		delete ptr;
	    }
	    
	    //Nếu ptr là đuôi, ta tìm node ở ngay trước đuôi rồi thay thế
	    //sửa nextAddr của previousNode = null
	    else if(ptr == tail)
	    {
		CLinkedListNode* previousNode = head;
		while(previousNode->getAddrNextNode() != ptr)
		{
		    previousNode = previousNode->getAddrNextNode();
		}
		tail = previousNode;
		tail->insertAddr(nullptr);
		delete ptr;
	    }
	
	    else
	    {   //newNode = node sau của ptr
		CLinkedListNode* newNode = ptr->getAddrNextNode();
	    
		//Nếu ptr là head, ta lấy node sau head làm head mới
		//ptr mới chính là head mới
		if(ptr == head)
		{
		    head = newNode;
		    delete ptr;
		    ptr = head;
		}
		//Nếu ptr ở giữa, ta tìm node ở đằng trước ptr, sửa nextNode của node đó thành node sau của ptr 
		//ptr mới sẽ là node sau của ptr cũ
		else
		{
		    CLinkedListNode* previousNode = head;
		    while(previousNode->getAddrNextNode() != ptr)
		    {
			previousNode = previousNode->getAddrNextNode();
		    }
		    previousNode->insertAddr(newNode);
		
		    delete ptr;
		    ptr = newNode;
		}
	    }
	    --iSize;
	}
	
	
	if(ptr == tail || isEmpty()) break;
	ptr = ptr->getAddrNextNode();
    }
}

int CLinkedList::peek() const
{
    assert(iSize > 0);
    
    return head->getData();
}

void CLinkedList::printList() const
{
    assert(iSize > 0);    

    CLinkedListNode* currNode = head;
    
    while(true)
    {
	std::cout << currNode->getData();
	if(currNode->getAddrNextNode() != nullptr)
	{
	    std::cout << " -> ";
	    currNode = currNode->getAddrNextNode();
	}    
	else break;
    }
}

bool CLinkedList::isEmpty() const
{
    return (iSize == 0);
}
