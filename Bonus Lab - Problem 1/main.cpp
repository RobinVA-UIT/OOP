// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#include <iostream>
#include "CStack.h"
#include "CLinkedList.h"
#include "CQueue.h"
#include "CBST.h"


using namespace std;

void testStack();
void testLinkedList();
void testQueue();
void testBST();
void searchBST(const CBST& bst);
void minAndMaxBST(const CBST& bst);

int main()
{
    // testStack();
    // testLinkedList();
    // testQueue();
    testBST();

    return 0;
}

void testStack()
{
    CStack st;
    
    cout << "=====STACK=====";
    cout << "\nStack co rong khong: " << (st.isEmpty())? "Co" : "Khong";

    int iInput;
    cout << "\nNhap so can push: ";
    cin >> iInput;
    st.push(iInput);
    cout << "\nNhap so can push lan 2: \n";
    cin >> iInput;
    st.push(iInput);

    cout << "\nPhan tu o dinh stack la: \n";    
    cout << st.peek();

    cout << "\nStack co rong khong: " << ((st.isEmpty())? "Co" : "Khong") << '\n';
    
    cout << "\nPop stack.\n";
    st.pop();

    cout << "\nPhan tu o dinh stack la: \n";    
    cout << st.peek();

    cout << "\nPop stack. Luc nay da het phan tu trong stack.\n";
    st.pop();

    cout << "\nStack co rong khong: " << ((st.isEmpty())? "Co" : "Khong") << '\n';

}

void testLinkedList()
{
    cout << "\n\n=====LINKED LIST=====\n\n";
    CLinkedList LList;
    int iInput;

    cout << "Linked list co rong khong: " << ((LList.isEmpty())? "Co" : "Khong") << '\n';

    cout << "\nNhap so can insert vao dau (head) linked list: ";
    cin >> iInput;
    LList.addFirst(iInput);
    cout << "\nNhap so can insert vao duoi (tail) linked list: ";
    cin >> iInput;
    LList.addLast(iInput);
    cout << "\nNhap so can insert vao giua head va tail: ";
    cin >> iInput;
    LList.insertAt(1, iInput);

    cout << "\nGia tri head linked list: " << LList.peek() << '\n';
    cout << "\nLinked list: "; LList.printList(); cout << '\n';

    cout << "\nNhap vi tri trong linked list can them gia tri moi (vi tri tu 0 den 2): ";
    int iPos; cin >> iPos; iPos = iPos % 3;
    cout << "\nNhap so can insert vao vi tri " << iPos << ": ";
    cin >> iInput;
    LList.insertAt(iPos, iInput);
    
    cout << "Linked list co rong khong: " << ((LList.isEmpty())? "Co" : "Khong") << '\n';
    
    cout << "\nGia tri head linked list: " << LList.peek() << '\n';
    cout << "\nLinked list: "; LList.printList(); cout << '\n';

    cout << "\nNhap gia tri can bi xoa trong linked list: ";
    cin >> iInput;
    LList.removeValue(iInput);
    cout << "\nGia tri head linked list: " << LList.peek() << '\n';
    cout << "\nLinked list: "; LList.printList(); cout << '\n';

    cout << "\nXoa head...\n";
    LList.removeFirst();
    cout << "\nGia tri head linked list: " << LList.peek() << '\n';
    cout << "\nLinked list: "; LList.printList(); cout << '\n';

    cout << "\nXoa tail...\n";
    LList.removeLast();
    cout << "\nGia tri head linked list: " << LList.peek() << '\n';
    cout << "\nLinked list: "; LList.printList(); cout << '\n';

}

void testQueue()
{
    CQueue queue;
    int iValue;

    cout << "\n=====QUEUE (LINKED LIST)=====\n";
    cout << "Queue co rong khong: " << ((queue.isEmpty())? "Co" : "Khong") << '\n';
   
    cout << "\nEnqueue mot gia tri so nguyen (lan 1): ";
    cin >> iValue; queue.enqueue(iValue);
    cout << "\nQueue co rong khong: " << ((queue.isEmpty())? "Co" : "Khong") << '\n';
    cout << "\nPhan tu o front queue: " << queue.peek() << '\n';


    cout << "\nEnqueue mot gia tri so nguyen (lan 2): ";
    cin >> iValue; queue.enqueue(iValue);

    cout << "\nEnqueue mot gia tri so nguyen (lan 3): ";
    cin >> iValue; queue.enqueue(iValue);
    
    cout << "\nDequeue...\n";
    cout << "Phan tu duoc dequeue: " << queue.dequeue();
    cout << "\nPhan tu o front queue: " << queue.peek() << '\n';

    cout << "\nDequeue lan 2...\n";
    cout << "Phan tu duoc dequeue: " << queue.dequeue();
    cout << "\nPhan tu o front queue: " << queue.peek() << '\n';
    
    cout << "\nDequeue lan 3... Da het phan tu.\n";
    cout << "Phan tu duoc dequeue: " << queue.dequeue();
    

    cout << "\nQueue co rong khong: " << ((queue.isEmpty())? "Co" : "Khong") << '\n';

}

void testBST()
{
    CBST bst;
    int iValue, iSize;
    cout << "\n=====BINARY SEARCH TREE=====\n";
    
    cout << "\nNhap so luong phan tu muon nhap: ";
    cin >> iSize;

    for(int i = 0; i<iSize; i++)
    {
	cout << "\nNhap phan tu thu " << i+1 << ": ";
	cin >> iValue;
	bst.insert(iValue);
    }
    
    cout << "\nPhan tu tai root: " << bst.getRoot();
    
    searchBST(bst);

    cout << "\nHay xoa 1 phan tu: ";
    cin >> iValue; bst.Delete(iValue);
    minAndMaxBST(bst);
    cout << "\nPhan tu tai root: " << bst.getRoot();
    
    searchBST(bst);

    
    cout << "\nHay xoa 1 phan tu: ";
    cin >> iValue; bst.Delete(iValue);
    minAndMaxBST(bst);
    cout << "\nPhan tu tai root: " << bst.getRoot();
    
    searchBST(bst);

    cout << "\nNhap so nguyen bat ki: ";
    cin >> iValue;
    cout << "\nFloor cua so nguyen vua nhap trong BST: " << bst.floor(iValue);
    cout << "\nCeil cua so nguyen vua nhap trong BST: " << bst.ceil(iValue);
}

void searchBST(const CBST& bst)
{
    int iValue;
    cout << "\nNhap phan tu can tim kiem: ";
    cin >> iValue;

    if(bst.search(iValue))
	cout << "\nPhan tu " << iValue << " ton tai trong Tree\n";
    else cout << "\nPhan tu " << iValue << " khong ton tai trong Tree\n";
}

void minAndMaxBST(const CBST& bst)
{
    
    cout << "\nPhan tu maximum: " << bst.maximum() << "\n";
    cout << "\nPhan tu minimum: " << bst.minimum() << '\n';
}
