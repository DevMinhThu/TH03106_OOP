//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class Queue
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *F,*R;

    public:
        //Ham tao va ham huy
        Queue();
        ~Queue();

        //Ham cai dat cac phep toan
        void QInsert(int x);
        int QDelete();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Queue::Queue():F(NULL),R(NULL)
{

}

Queue::~Queue()
{
    while(F)
    {
        node *P=F;
        F=F->link;
        delete P;
    }
}

void Queue::QInsert(int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Bo sung vao hang doi
    if(F==NULL) F=R=N;
    else
        R->link = N;
        R=N;
}

int Queue::QDelete()
{
    //1.Kiem tra rong
    if(F==NULL)
    {
        cout<<"Hang doi rong!";
        return 1;
    }

    //2.Giu lai phan tu loai bo
    int tg = F->infor;
    node *P=F;

    //3.Cho F tro toi nut phia sau
    if(F==R) F=R=NULL; // Truong hop 2 nut trung nhau
    else
        F=F->link;

    //4.Huy va tra ve phan tu loai bo
    delete P;
    return tg;
}

bool Queue::isEmpty()
{
    return F==NULL;
}



