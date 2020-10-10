//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH
//HANG DOI PHAN TAN

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
        //Ham tao
        Queue();

        //Ham Huy
        ~Queue();

        //Ham cai dat cac phep toan
        void QInsert(int x);
        int QDlelete();
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

//Ham Huy
Queue::~Queue()
{
    while(F)
    {
        node *P=F;
        F=F->link;
        delete P;
    }
}

//Ham cai dat cac phep toan
void Queue::QInsert(int x)
{
    //1.Tao nut moi
    node *N=new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao hang doi
    if(R==NULL) F=R=N;
    else
    {
        R->link = N;
        R=N;
    }
}

int Queue::QDlelete()
{
    //1.Kiem tra rong
    if(F==NULL)
    {
        cout<<"Hang doi rong!";
        return -1;
    }

    //2.Luu lai phan tu loai bo
    int tg=F->infor;
    node *P=F;

    //3.Thay doi F
    if(F==R) F=R=NULL;
    else
        F=F->link;

    //4.Huy va tra ve nut bi loai bo
    delete P;
    return tg;
}

bool Queue::isEmpty()
{
    return F==NULL;
}



//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH
//HANG DOI KE TIEP

#include<iostream>
#include<stdio.h>

using namespace std;

class Queue
{
    private:
        enum {size=20};
        int F,R;
        int Q[size];

    public:
        //Ham tao
        Queue();

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
Queue::Queue():F(-1),R(-1)
{

}
void Queue::QInsert(int x)
{
    //1.Kiem tra day
    if(F==0 && R==size-1 || R+1==F)
    {
        cout<<"Hang doi ke tiep day!";
        return;
    }

    //2.Thay doi bien chi so R
    if(R==-1) F=R=0; //TH: rong
    else
        if(R==size-1) //TH: quay vong cua R
            R=0;
        else
            R++; //TH: con lai

    //3.Bo sung x vao hang doi ke tiep
    Q[R] = x;
}
int Queue::QDelete()
{
    //1.Kiem tra rong
    if(F==-1)
    {
        cout<<"Hang doi ke tiep rong!";
        return -1;
    }

    //2.Giu lai phan tu loai bo
    int tg=Q[F];

    //3.Thay doi bien chi so F
    if(F==R) F=R=-1; //TH F trung R, chi co 1 phan tu
    else
        if(F==size-1) //TH: quay vong cua F
            F=0;
        else
            F++;

    return tg;
}

bool Queue::isEmpty()
{
    return F==-1;
}

