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
        struct node
        {
            int infor;
            node *link;
        } *T;

    public:
        //Ham tao va ham huy
        Stack();
        ~Stack();

        //Ham thanh vien thao tac
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
Stack::Stack():T(NULL)
{

}

Stack::~Stack()
{
    while(T)
    {
        node *P=T;
        T=T->link;
        delete P;
    }
}

void Stack::push(int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Bo sung x vao ngan xep
    N->link = T;

    //3.Cho T tro toi nut moi
    T = N;
}

int Stack::pop()
{
    //1.Kiem tra rong
    if(T==NULL)
    {
        cout<<"Ngan xep rong!";
        return -1;
    }

    //2.Giu lai phan tu loai bo
    int tg=T->infor;
    node *P=T;

    //3.Chuyen T xuong nut duoi
    T=T->link;

    //4.Huy nut va tra ve phan tu bi huy
    delete P;
    return tg;
}

bool Stack::isEmpty()
{
    return T==NULL;
}



