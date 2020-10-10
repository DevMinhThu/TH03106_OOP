//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class Stack
{
    private:
        enum {size=20};
        int T;
        int S[size];

    public:
        //Ham tao
        Stack();

        //Ham cai dat cac phep toan
        void push(int x);
        int pop();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Stack::Stack():T(-1)
{

}

void Stack::push(int x)
{
    //1.Kiem tra ngan xep day
    if(T==size-1)
    {
        cout<<"Ngan xep day!";
        return;
    }

    //2-3. Tang T len 1 va bo sung x vao
    S[++T] = x;
}

int Stack::pop()
{
    //1.Kiem tra rong
    if(T==-1)
    {
        cout<<"Ngan xep rong!";
        return 1;
    }

    //2-3: Tra ve phan tu loai bo va giam T di 1
    return S[T--];
}

bool Stack::isEmpty()
{
    return T==-1;
}



