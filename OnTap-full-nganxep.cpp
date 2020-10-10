//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH
//NGAN XEP PHAN TAN

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

    //2.Noi nut moi vao
    N->link = T;

    //3.Cho T tro toi nut ben tren
    T=N;
}

int Stack::pop()
{
    //1.Kiem tra rong
    if(T==NULL)
    {
        cout<<"Ngan xep rong!";
        return -1;
    }

    //2.Luu lai phan tu bi loai bo
    int tg=T->infor;

    //3.Luu lai dia chi nut loai bo
    node *P = T;

    //4.Cho T tro xuong nut duoi
    T=T->link;

    //5.Huy va tra ve phan tu loai bo
    delete P;
    return tg;
}
bool Stack::isEmpty()
{
    return T==NULL;
}


//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH
//NGAN XEP KE TIEP

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class Stack
{
    private:
        enum {size=20};
        int S[size];
        int T;

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
    //1.Kiem tra day
    if(T==size-1)
    {
        cout<<"Ngan xep ke tiep day!";
        return;
    }

    //2.3: Tang T len 1 va bo sung x vao
    S[++T] = x;
}

int Stack::pop()
{
    //1.Kiem tra rong
    if(T==-1)
    {
        cout<<"Ngan xep ke tiep rong!";
        return -1;
    }

    //2.3.4.Tra ve phan tu loai bo va giam T di 1
    return S[T--];
}

bool Stack::isEmpty()
{
    return T==-1;
}


