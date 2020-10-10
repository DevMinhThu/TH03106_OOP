//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH
/*
Tính diện tích n hình: Hình chữ nhật biết 2 cạnh,
hình tròn biết bán kính. Y/c cài đặt đa hình động cho
hàm nhập kích thước và hàm tính diện tích
*/

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class Hinh
{
    private:

    public:
        virtual void nhap()=0;
        virtual float tinhDT()=0;
};

class HinhCN:public Hinh
{
    private:
        float a,b;

    public:
        void nhap();
        float tinhDT();
};

class HinhTron:public Hinh
{
    private:
        float r;

    public:
        void nhap();
        float tinhDT();
};

//===chuong trinh chinh===
int main()
{
    //Khai bao con tro lop co so
    Hinh *h1, *h2;

    //Tao 1 doi tuong HinhCN va 1 doi tuong HinhTron
    h1 = new HinhCN;
    h2 = new HinhTron;

    //Da hinh
    h1->nhap(); //Nhap cua hinhCN
    h2->nhap(); //Nhap cua hinhTron

    //Tinh DT
    cout<<"Dien tich HinhCN la: "<<h1->tinhDT();
    cout<<"\nDien tich HinhTron la: "<<h2->tinhDT();

    //Huy doi tuong
    delete h1;
    delete h2;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//HinhCN
void HinhCN::nhap()
{
    cout<<"Nhap vao 2 canh cua HCN: \n";
    cin>>a>>b;
}

float HinhCN::tinhDT()
{
    return a*b;
}

//HinhTron
void HinhTron::nhap()
{
    cout<<"Nhap vao ban kinh cua HinhTron: \n";
    cin>>r;
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

