//Ho ten: Vu Minh Thu
//Lop: K63TH
//MaSV: 637865

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class SList
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *F;

    public:
        //Ham tao, ham huy
        SList();
        ~SList();

        //Ham cai dat cac phep toan
        void lastInsert(int x);
        void TopInsert(int x);
        void show();
        bool searchX(int x);
        bool deleteX(int x);
};

//===chuong trinh chinh
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
SList::SList():F(NULL)
{

}

SList::~SList()
{
    while(F)
    {
        node *P=F;
        F=F->link;
        delete P;
    }
}

void SList::lastInsert(int x)
{
    //1.Tao nnut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao cuoi DSLKD
    if(F==NULL) F=N;
    else
    {
        //Lay link cua nut cuoi cung
        node *P=F;
        while(P->link)
            P=P->link;

        //Noi nut moi vao cuoi DSLKD
        P->link = N;
    }
}

void SList::TopInsert(int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao dau DSLKD
    if(F==NULL) F=N;
    else
    {
        N->link = F;
        F=N;
    }

}

void SList::show()
{
    node *P=F;

    while(P)
    {
        cout<<P->infor<<"  ";
        P=P->link;
    }
}

bool SList::searchX(int x)
{
    node *P=F;

    while(P)
    {
        if(P->infor==x) return P;
        else P=P->link;
    }

    //Khong tim thay
    return NULL;
}

bool SList::deleteX(int x)
{
    if(F==NULL) return 0;

    //Tim nut chua phan tu x va nut dung truoc no
    node *M=F, *P;

    while(M)
    {
        if(M->infor==x) break;

        P=M;//luu lai link cua nut phia truoc M
        M=M->link;
    }

    if(M)
    {
        //M trung voi F
        if(M==F) F=F->link;
        else P->link = M->link; //Noi nut truoc M voi nut sau M

        //Huy nut M va tra ve
        delete M;
        return 1;
    }

    return 0;
}

