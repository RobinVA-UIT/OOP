// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include <cassert>
#include "CBSTNode.h"
#include "CBST.h"

//Constructor
CBST::CBST()
{
    root = nullptr;
}

void CBST::insert(int value)
{
    CBSTNode* toInsert = new CBSTNode(value);
    
    if(root == nullptr)
    {
	root = toInsert;
	return;
    }
    
    int currVal = root->getData();
    CBSTNode* currNode = root;    

    while(true)
    {
	if(value > currVal)
	{
	    if(currNode->getRight() == nullptr)
	    {
		currNode->setRight(toInsert);
		std::cout << "\nDia chi right: " << currNode->getRight();
		return;
	    }
	    else
	    {
		currNode = currNode->getRight();
	    }
	}
	else
	{
	    if(currNode->getLeft() == nullptr)
	    {
		currNode->setLeft(toInsert);
		std::cout << "\nDia chi left: " << currNode->getLeft();
		return;
	    }
	    else
	    {
		currNode = currNode->getLeft();
	    }
	}

    	currVal = currNode->getData();	
    }
}

bool CBST::search(int target) const
{
    if(root == nullptr) return false;
    
    CBSTNode* currNode = root;    
    std::cout << "\nDia chi root: " << currNode;    

    while(currNode != nullptr)
    {
	int value = currNode->getData();
	if(value == target) return true;
	std::cout << "\nChua chay xong. Dia chi hien tai: " << currNode;
	if(target < value) currNode = currNode->getLeft();
	else currNode = currNode->getRight();
    }

    return false;
}

CBSTNode* CBST::predecessor(CBSTNode* k) const
{
    int kValue = k->getData();

    if(kValue == minimum()) return nullptr;

    //Nếu k có nhánh bên trái  ==> Predecessor nằm ở nhánh trái
    //Tìm giá trị lớn nhất mà bé hơn value 
    if(k->getLeft() != nullptr)
    {
	//Bắt đầu từ node trái của k
	k = k->getLeft();

	//Duyệt nhánh phải của k mới cho đến khi giá trị của checkingNode > kValue
	while(k->getRight() != nullptr)
	{
	    k = k->getRight();
	}

	return k;
    }

    //Nếu k không có nhánh trái
    //Ta duyệt ưu tiên nhánh phải, nếu không thì nhánh trái
    //Miễn làm sao mà 1 trong 2 phải có value < kValue
    //Nếu không, ta return
    else
    {
	CBSTNode* currNode = root;
	CBSTNode* leftNode = nullptr;
	CBSTNode* rightNode = nullptr;

	while(true)
	{
	    leftNode = currNode->getLeft();
	    rightNode = currNode->getRight();
	    
	    bool isChanged = false;		
	    
	    if(rightNode != nullptr)
	    {
		if(rightNode->getData() < kValue)
		{
		    isChanged = true;
		    currNode = rightNode;
		}	
	    }

	    if(!isChanged && leftNode != nullptr)
	    {	
	        if(leftNode->getData() < kValue)
	        {
		    isChanged = true;
		    currNode = leftNode;
		}
	    }

	    if(!isChanged) return currNode;
	}	
    }
}

CBSTNode* CBST::successor(CBSTNode* k) const
{
    int kValue = k->getData();

    if(kValue == maximum()) return nullptr;

    //Nếu k có nhánh phải ==> Successor nằm ở nhánh phải
    if(k->getRight() != nullptr)
    {
	//Bắt đầu từ node phải của k
	CBSTNode* checkingNode = k->getRight();
	
	//Duyệt trái cho đến ngọn 
	while(true)
	{
	    checkingNode = checkingNode->getLeft();
	    if(checkingNode == nullptr) break;

	    k = checkingNode;
	}
	
	return k;	
    }

    //Nếu k không có nhánh phải
    //Ta duyệt ưu tiên nhánh trái, nếu không thì nhánh phải
    //Miễn làm sao mà 1 trong 2 phải có value > kValue
    //Nếu không, ta return
    else
    {
	CBSTNode* currNode = root;
	CBSTNode* leftNode = nullptr;
	CBSTNode* rightNode = nullptr;

	while(true)
	{
	    leftNode = currNode->getLeft();
	    rightNode = currNode->getRight();
	    
	    bool isChanged = false;		
	    
	    if(leftNode != nullptr)
	    {
		if(leftNode->getData() > kValue)
		{
		    isChanged = true;
		    currNode = leftNode;
		}	
	    }

	    if(!isChanged && rightNode != nullptr)
	    {	
	        if(rightNode->getData() > kValue)
	        {
		    isChanged = true;
		    currNode = rightNode;
		}
	    }

	    if(!isChanged) return currNode;
	}	
    }

}


void CBST::Delete(int target)
{
    if(root == nullptr) return;
    
    CBSTNode* currNode = root;
    int currVal;

    CBSTNode* prevNode = nullptr;

    //Biến right dùng để xác định currNode là node phải hay trái của prevNode
    bool isFound = false, isRight = false, isRoot = true;

    while(currNode != nullptr)
    {
	currVal = currNode->getData();

	if(target == currVal)
	{
	    isFound = !isFound;
	    break;
	}
	
	prevNode = currNode;	
	if(isRoot) isRoot = false;	

	if(target > currVal)
	{
	    isRight = true;
	    currNode = currNode->getRight();
	}
	else
	{
	    isRight = false;
	    currNode = currNode->getLeft();
	}
    }

    if(!isFound) return;

    CBSTNode* leftNode = currNode->getLeft();
    CBSTNode* rightNode = currNode->getRight();

    if(leftNode == nullptr && rightNode == nullptr)
    {	
	if(isRoot)
	{
	    root = nullptr;
	    delete currNode;
	    return;
	}

	if(currNode->getData() > prevNode->getData()) prevNode->setRight(nullptr);
	else prevNode->setLeft(nullptr);

	delete currNode;
    }

    else if(leftNode == nullptr || rightNode == nullptr)
    {

	if(isRoot)
	{
	    CBSTNode* newRoot;
	    if(leftNode == nullptr)
		newRoot = root->getRight();

	    else
		newRoot = root->getLeft();

	    delete root;
	    root = newRoot;
	    return;
	}

	if(leftNode == nullptr)
	{
	    prevNode = rightNode;
	    
	    delete currNode;
	}
	else
	{
	    prevNode = leftNode;

	    delete currNode;
	}

    }
    
    else
    {
	CBSTNode* newNode = successor(currNode);
	
	if(newNode == rightNode) newNode->setRight(nullptr);
	else newNode->setRight(rightNode);

	newNode->setLeft(leftNode);

	if(isRight)
	{
	    prevNode->setRight(newNode);
	}
	else
	{
	    prevNode->setLeft(newNode);
	}

	delete currNode;

	if(isRoot) root = newNode;
    }

}


int CBST::maximum() const
{
    assert(root != nullptr);    

    CBSTNode* currNode = root;
    CBSTNode* nextNode = currNode->getRight();

    while(nextNode != nullptr)
    {
	currNode = nextNode;

	nextNode = nextNode->getRight();
    }

    return currNode->getData();
}

int CBST::minimum() const
{
    assert(root != nullptr);    

    CBSTNode* currNode = root;
    CBSTNode* nextNode = currNode->getLeft();

    while(nextNode != nullptr)
    {
	currNode = nextNode;

	nextNode = nextNode->getLeft();
    }

    return currNode->getData();
}

//Floor: Tìm node có value lớn nhất mà bé hơn hoặc bằng value
int CBST::floor(int value) const
{
    assert(root != nullptr);
    
    CBSTNode* currNode = root;

    int result = currNode->getData();

    while(true)
    {
	CBSTNode* leftNode = currNode->getLeft();
	CBSTNode* rightNode = currNode->getRight();
	

	if(rightNode != nullptr)
	{
	    if(rightNode->getData() <= value)
	    {
		result = rightNode->getData();
		currNode = rightNode;
		continue;
	    }
	}
	if(leftNode != nullptr)
	{
	    if(leftNode->getData() <= value)
	    {
		result = leftNode->getData();
		currNode = leftNode;
		continue;
	    }
	}

	return result;
    }
}

//Ceil: Tìm node có value bé nhất mà lớn hơn hoặc bằng value
int CBST::ceil(int value) const
{
    assert(root != nullptr);
    
    CBSTNode* currNode = root;

    int result = currNode->getData();

    while(true)
    {
	CBSTNode* leftNode = currNode->getLeft();
	CBSTNode* rightNode = currNode->getRight();
	

	if(leftNode != nullptr)
	{
	    if(leftNode->getData() >= value)
	    {
		result = leftNode->getData();
		currNode = leftNode;
		continue;
	    }
	}
	if(rightNode != nullptr)
	{
	    if(rightNode->getData() >= value)
	    {
		result = rightNode->getData();
		currNode = rightNode;
		continue;
	    }
	}

	return result;
    }

}

int CBST::getRoot() const
{
    return root->getData();
}

