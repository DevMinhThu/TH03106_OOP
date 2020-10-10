//Ho ten: Vu Minh Thu
//Lop: k63TH
//MaSV: 637865
//De:
/*
Bài 25(lthdtbai25.cpp): Viết chương trình nhập vào một thời gian có giờ và phút.
Tính và đưa ra màn hình thời gian sau n phút nhập vào từ bàn phím.
*/

#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao class
class ThoiGian
{
    private:
        int gio,phut;

    public:
        //Ham tao khong doi so
        ThoiGian();

        //Ham tinh thoi gian
        ThoiGian tinhTG(int n);

        //Ham ban
        friend istream& operator>>(istream &cin, ThoiGian &tg);
        friend ostream& operator<<(ostream &cout, ThoiGian &tg);
};


//===chuong trinh chinh===
int main()
{
    //Khai bao doi tuong thoi gian
    ThoiGian tg, kq;

    //Khai bao bien
    int n;

    //Nhap vao thoi gian
    cout<<"\nNhap vao thoi gian: ";
    cin>>tg;

    //Xuat ra thoi gian
    cout<<"\nThoi gian vua nhap la: ";
    cout<<tg;

    //Nhap vao n phut
    cout<<"\nNhap vao so phut: ";
    cin>>n;

    //Tinh thoi  gian
    kq = tg.tinhTG(n);

    //Xuat ra kq
    cout<<"\nThoi gian sau khi them "<<n<<" phut la:"<<kq;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
ThoiGian::ThoiGian():gio(0),phut(0)
{

}

ThoiGian ThoiGian::tinhTG(int n)
{
    ThoiGian tg;

    if(phut + n < 60)
    {
        tg.gio = gio;
        tg.phut = phut + n;
    }
    else
    {
        //Khai bao bien temp de luu lai so phut
        int temp = phut + n;

        //TH khi so phut > 60

        //tem/60: so phut chia nguyen cho 60
        //roi lay phan nguyen cong vao gio
        tg.gio = gio + temp/60;

        //Phut moi, chia lay du
        tg.phut = temp%60;
    }

    return tg;
}

istream& operator>>(istream &cin, ThoiGian &tg)
{
    cout<<"\nNhap so gio: ";
    cin>>tg.gio;
    cout<<"Nhap vao so phut: ";
    cin>>tg.phut;

    return cin;
}
ostream& operator<<(ostream &cout, ThoiGian &tg)
{
    cout<<tg.gio<<" gio "<<tg.phut<<" phut. ";

    return cout;
}

