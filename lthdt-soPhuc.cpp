//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class SoPhuc
{
    private:
        float a,b;

    public:
        //Ham tao va ham huy
        SoPhuc();
        ~SoPhuc();

        //Ham chong toan tu cong
        SoPhuc operator+(SoPhuc &p);

        //Ham ban
        friend istream& operator>>(istream &cin, SoPhuc &p);
        friend ostream& operator<<(ostream &cout, SoPhuc &p);
};

//===chuong trinh chinh===
int main()
{
    //Tao 3 doi tuong so phuc
    SoPhuc p1,p2,p3,tong;

    //Nhap
    cout<<"Nhap vao so phuc p1: \n";
    cin>>p1;

    cout<<"Nhap vao so phuc p2: \n";
    cin>>p2;

    cout<<"Nhap vao so phuc p3: \n";
    cin>>p3;

    //Tinh tong
    tong = p1+p2+p3;

    //Dua ra
    cout<<"\nSo phuc p1 la: \n"<<p1;
    cout<<"\nSo phuc p2 la: \n"<<p2;
    cout<<"\nSo phuc p3 la: \n"<<p3;
    cout<<"\nTong 2 so phuc la: \n"<<tong;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
SoPhuc::SoPhuc():a(0),b(0)
{

}

SoPhuc::~SoPhuc()
{

}

//Ham chong toan tu cong
SoPhuc SoPhuc::operator+(SoPhuc &p)
{
    SoPhuc tong;

    tong.a = a + p.a;
    tong.b = b +p.b;

    return tong;
}

//Ham ban
istream& operator>>(istream &cin, SoPhuc &p)
{
    cout<<"Nhap vao phan thuc: ";
    cin>>p.a;
    cout<<"Nhap vao phan ao: ";
    cin>>p.b;

    return cin;
}

ostream& operator<<(ostream &cout, SoPhuc &p)
{
    if(p.b>=0) cout<<p.a<<" + "<<p.b<<"j";
    else cout<<p.a<<" - "<<-p.b<<"j";

    return cout;
}

