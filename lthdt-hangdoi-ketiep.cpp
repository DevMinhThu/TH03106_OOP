//Ho ten: Vu Minh Thu
//Lop: K63TH
//MaSV: 637865
/*
Bài 30(lthdtbai30.cpp): Đọc vào một dãy số nguyên từ tệp văn bản,
trong đó có cả số dương và số âm.
Sử dụng hàng đợi lưu trữ kế tiếp theo kiểu quay vòng để tách, đưa ra màn hình đồng thời
ghi ra tệp văn bản dãy các số dương và dãy các số âm.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class Queue
{
    private:
        enum {size=30};
        int Q[size];
        int F,R;

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
    //Khai bao doi tuong doc tep
    ifstream fin("daysonguyen.txt");

    //Khai bao doi tuong ngan xep
    Queue q1,q2;

    //Khai bao bien
    int x,soDuong,soAm;

    //Doc vao cac phan tu trong tep
    while(fin>>x)
    {
        if(x<0)
            q1.QInsert(x);
        else
            q2.QInsert(x);
    }

    //Xuat ra man hinh
    cout<<"Day so duong la: ";
    while(!q2.isEmpty())
    {
        soDuong=q2.QDelete();
        cout<<soDuong<<"  ";
    }

    cout<<"\nDay so am la: ";
    while(!q1.isEmpty())
    {
        soAm=q1.QDelete();
        cout<<soAm<<"  ";
    }
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
        cout<<"Hang doi day!";
        return;
    }

    //2.Tang R len 1
    if(R==-1) F=R=0;
    else
        R++;

    //3.Bo sung x vao hang doi
    Q[R] = x;
}

int Queue::QDelete()
{
    //1.Kiem tra rong
    if(F==-1)
    {
        cout<<"Hang doi rong!";
        return 1;
    }

    //2.Giu lai phan tu loai bo
    int tg=Q[F];

    //3.Tang F len 1
    if(F==R) F=R=-1;
    else
        if(F==size-1) F=0;
        else
            F++;

    return tg;
}

bool Queue::isEmpty()
{
    return F==-1;
}


