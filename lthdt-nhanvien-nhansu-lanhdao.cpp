//Ho ten: Vu Minh Thu
//Lop: k63TH
//MaSV: 637865
//De:
/*
Bài 40(lthdtbai40.cpp): Một nhân sự nói chung có họ tên và ngày sinh. Nhân viên trong
một công ty là một loại nhân sự nhưng có thêm mã nhân viên và hệ số lương. Lãnh đạo
trong công ty là một loại nhân viên có thêm chức vụ. Nhập vào thông tin của một số nhân viên
và lãnh đạo trong công ty. Đưa ra các thông tin đã nhập.
*/

#include<iostream>
#include<stdio.h>

using namespace std;

class NhanSu
{
    private:
        char hoTen[30];
        char ngaySinh[11];

    public:
        void nhap();
        void xuat();
};

class NhanVien:public NhanSu
{
    private:
        char maNV[30];
        float heSoLuong;

    public:
        void nhap();
        void xuat();
};

class LanhDao:public NhanVien
{
    private:
        char chucVu[30];

    public:
        void nhap();
        void xuat();
};

//===chuong trinh chinh===
int main()
{
    //Khai bao doi tuong nhan vien va lanh dao
    NhanVien nv;
    LanhDao ld;

    //Nhap
    cout<<"Nhap thong tin cua 1 nhan vien: \n";
    nv.nhap();

    cout<<"\nNhap thong tin cua 1 lanh dao: \n";
    ld.nhap();

    //Xuat ra man hinh
    cout<<"\n\nThong tin cua 1 nhan vien la: \n";
    nv.xuat();
    cout<<"\n\nThong tin cua 1 lanh dao la: \n";
    ld.xuat();


    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//NhanSu
void NhanSu::nhap()
{
    cout<<"Nhap ho va ten: ";
    scanf(""); cin.get(hoTen,sizeof(hoTen));
    cout<<"Nhap ngay sinh: ";
    cin>>ngaySinh;
}

void NhanSu::xuat()
{
    cout<<"Ho ten: "<<hoTen;
    cout<<"\nNgay sinh: "<<ngaySinh;
}

//NhanVien
void NhanVien::nhap()
{
    NhanSu::nhap(); // Goi ham nhap tt cua NhanSu khi ke thua

    cout<<"Nhap ma nhan vien: ";
    cin>>maNV;
    cout<<"Nhap he so luong: ";
    cin>>heSoLuong;
}

void NhanVien::xuat()
{
    NhanSu::xuat();

    cout<<"\nMa nhan vien: "<<maNV;
    cout<<"\nHe so luong: "<<heSoLuong;
}

//LanhDao
void LanhDao::nhap()
{
    NhanVien::nhap();

    cout<<"Nhap chuc vu: ";
    cin>>chucVu;
}

void LanhDao::xuat()
{
    NhanVien::xuat();

    cout<<"\nChuc vu la: "<<chucVu;
}

