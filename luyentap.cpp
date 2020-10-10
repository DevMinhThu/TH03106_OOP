//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH
/*
Câu 1: Tính tổng n số, trong đó có cả số phức và phân số,
số phức biết phần thực và phần ảo, phân số biết tử số và mẫu số.
Yêu cầu trong chương trình cài đặt đa hình động cho hàm nhập .
2 hàm chồng toán tử cộng và xuất ra màn hình.
*/

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class So
{
    private:

    public:
        virtual void nhap()=0;
};

class SoPhuc:public So
{
    private:
        float thuc,ao;

    public:
        void nhap();
        SoPhuc operator+(SoPhuc &sp2);
        friend ostream& operator<<(ostream &cout, SoPhuc &sp2);
};

class PhanSo:public So
{
    private:
        float tuSo,mauSo;

    public:
        void nhap();
        PhanSo operator+(PhanSo &ps2);
        friend ostream& operator<<(ostream &cout, PhanSo &ps2);
};

//===chuong trinh chinh===
int main()
{
    //Khai bao con tro lop co so
    So *s1, *s2;

    //Khoi tao doi tuong so phuc va phan so
    SoPhuc sp1,sp2,tongSP;
    PhanSo ps1,ps2,tongPS;

    //Tao 1 doi tuong SoPhuc va 1 doi tuong PhanSo
    s1 = new SoPhuc;
    s2 = new PhanSo;

    //Thuc hien da hinh dong
    s1->nhap(); //Nhap so phuc
    s2->nhap(); //Nhap phan so

    //Xuat so phuc va phan so vua nhap
    cout<<"\nSo phuc vua nhap la: "<<s1;
    cout<<"\nPhan So vua nhap la: "<<s2;

    //Tinh tong
    tongSP = sp1 + sp2;
    tongPS = ps1 + ps2;

    cout<<"\nTong hai so phuc la: "<<tongSP;
    cout<<"\nTong hai phan so la: "<<tongPS;

    //Huy doi tuong
    delete s1;
    delete s2;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//So Phuc
void SoPhuc::nhap()
{
    cout<<"Nhap vao phan thuc: ";
    cin>>thuc;
    cout<<"Nhap vao phan ao: ";
    cin>>ao;
}

SoPhuc SoPhuc::operator+(SoPhuc &sp2)
{
    SoPhuc tong;

    tong.thuc = thuc + sp2.thuc;
    tong.ao = ao + sp2.ao;

    return tong;
}

ostream& operator<<(ostream &cout, SoPhuc &sp2)
{
    if(sp2.ao>=0) cout<<sp2.thuc<<" + "<<sp2.ao<<"j";
    else
        cout<<sp2.thuc<<" - "<<sp2.ao<<"j";

    return cout;
}

//Phan So
void PhanSo::nhap()
{
    cout<<"Nhap tu so: ";
    cin>>tuSo;

    do
    {
        cout<<"Nhap mau so: ";
        cin>>mauSo;

        if(mauSo==0)
        {
            cout<<"Mau so phai khac 0!"<<endl;
        }
    }
    while(mauSo==0);
}

PhanSo PhanSo::operator+(PhanSo &ps2)
{
    PhanSo tong;

    tong.tuSo = tuSo*ps2.mauSo + ps2.tuSo*mauSo;
    tong.mauSo = mauSo*ps2.mauSo;

    return tong;
}

ostream& operator<<(ostream &cout, PhanSo &ps2)
{
    cout<<ps2.tuSo<<"/"<<ps2.mauSo;

    return cout;
}
