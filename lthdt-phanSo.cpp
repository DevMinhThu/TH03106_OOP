//Ho ten: Vu Minh Thu
//Lop: k63TH
//MaSV: 637865
//De:
/*
Bài 15(lthdtbai15.cpp): Tính tổng 2 phân số, đưa các phân số ra màn hình ở dạng chưa rút gọn
và đã rút gọn.
*/

#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao class
class PhanSo
{
    private:
        float a,b;

    public:
        //Ham chong toan tu cong
        PhanSo operator+(PhanSo &ps);

        void rutGon();

        //Ham ban
        friend istream& operator>>(istream &cin, PhanSo &ps);
        friend ostream& operator<<(ostream &cout, PhanSo &ps);
};

//===chuong trinh chinh===
int main()
{
    //Tao doi tuong phan so
    PhanSo ps1,ps2,tong;

    //Nhap
    cout<<"Nhap phan so thu 1: \n";
    cin>>ps1;

    cout<<"Nhap phan so thu 2: \n";
    cin>>ps2;

    //Tinh tong
    tong = ps1+ps2;

    //Xuat ra man hinh
    cout<<"\nPhan so thu 1 la: "<<ps1;
    cout<<"\nPhan so thu 2 la: "<<ps2;
    cout<<"\nTong hai phan so la: "<<tong;

    //Rut gon
    ps1.rutGon();
    ps2.rutGon();
    tong.rutGon();

    //Sau khi rut gon
    cout<<"\n\nCac phan so sau khi rut gon:";
    cout<<"\nPhan so 1: "<<ps1;
    cout<<"\nPhan so 2: "<<ps2;
    cout<<"\nTong 2 phan so: "<<tong;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
PhanSo PhanSo::operator+(PhanSo &ps)
{
    PhanSo tong;

    tong.a = a*ps.b + ps.a*b;
    tong.b = b*ps.b;

    return tong;
}

void PhanSo::rutGon()
{
    int x=a,y=b,r=x%y;

    while(r)
    {
        x = y;
        y = r;
        r = x%y;
    }

    //Rut phan so
    a/=y;
    b/=y;
}

istream& operator>>(istream &cin, PhanSo &ps)
{
    cout<<"Nhap vao tu so: ";
    cin>>ps.a;
    do
    {
        cout<<"Nhap vao mau so: ";
        cin>>ps.b;
        if(ps.b==0)
        {
            cout<<"Khong hop le!"<<endl;
        }
    }
    while(ps.b==0);

    return cin;
}

ostream& operator<<(ostream &cout, PhanSo &ps)
{
    cout<<ps.a<<"/"<<ps.b;

    return cout;
}

