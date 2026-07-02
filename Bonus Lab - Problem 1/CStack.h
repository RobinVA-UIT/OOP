// Mã số sinh viên: 25521594
// Họ và tên sinh viên: Lương Công Tiến Sơn
// Ngày sinh: 04/01/2007
// Lớp: IT002.Q27.2

#ifndef CSTACK_H
#define CSTACK_H

class CStack {
private:
    static const int MAXN = 1e5 + 2;
    int arr[MAXN];
    int iTop;
public:
    //Constructor
    CStack();

    //Push
    void push(int x);
    //Pop
    void pop();
    //Peek
    int peek() const;
    //Kiểm tra xem stack có empty hay không
    bool isEmpty() const;
};

#endif // CSTACK_H

