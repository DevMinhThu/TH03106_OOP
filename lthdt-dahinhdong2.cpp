/*
Bài 43(lthdtbai43.cpp): Viết chương trình quản lý nhân sự của một trường học;
nhân sự gồm có giảng viên và sinh viên; giảng viên có mã gv, họ tên và số bài báo;
sinh viên có mã sv, họ tên và điểm tbc. Nhập vào một số nhân sự trong đó có cả giảng viên
và sinh viên. Đưa ra thông tin của các nhân sự đã nhập kèm theo đánh giá:
giảng viên đánh giá là giỏi nếu số bài báo >=5, sinh viên đánh giá là giỏi
nếu điểm TBC>=8.0. Y/c cài đặt đa hình động.
*/

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class NhanSu
{
    private:

    public:
       virtual void nhap()=0;
       virtual void xuat()=0;
};

class GiangVien:public NhanSu
{
    private:
        char maGV[10];
        char hoTen[30];
        int soBaiBao;

    public:
       void nhap();
       void xuat();
};

class SinhVien:public NhanSu
{
    private:
        char maSV[10];
        char hoTen[30];
        float diemTB;

    public:
       void nhap();
       void xuat();
};

//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    int n, luaChon;

    cout<<"Nhap vao so luong nhan su: ";
    cin>>n;

    //Khai bao mang doi tuong dong
    NhanSu *ns[n];

    for(int i=0;i<n;i++)
    {
        cout<<"\nNhap vao lua chon (1-GiangVien, 2-SinhVien): ";
        cin>>luaChon;
        switch(luaChon)
        {
            case 1:
                ns[i] = new GiangVien;
                ns[i]->nhap();
                break;
            case 2:
                ns[i] = new SinhVien;
                ns[i]->nhap();
                break;
            default:
                ns[i] = new GiangVien;
                ns[i]->nhap();
        }
    }

    //Xuat
    cout<<"\nDanh sach cac nhan su la: \n";
    for(int i=0;i<n;i++)
    {
        cout<<"\nNhan su thu "<<i+1<<"la: \n";
        ns[i]->xuat();
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//Giang Vien
void GiangVien::nhap()
{
    cout<<"Nhap vao ma giang vien: ";
    scanf(" "); cin.get(maGV,sizeof(maGV));
    cout<<"\NNhap vao ten giang vien: ";
    scanf(" "); cin.get(hoTen,sizeof(hoTen));
    cout<<"\NNhap vao so bai bao: ";
    cin>>soBaiBao;
}
void GiangVien::xuat()
{
    cout<<"\nMa giang vien la: "<<maGV;
    cout<<"\nTen giang vien la: "<<hoTen;
    cout<<"\nSo bai bao la: "<<soBaiBao;
    if(soBaiBao>=5)
        cout<<"\nXep loai gioi!";
}

//Sinh Vien
void SinhVien::nhap()
{
    cout<<"Nhap vao ma sinh vien: ";
    scanf(""); cin.get(maSV,sizeof(maSV));
    cout<<"\NNhap vao ten sinh vien: ";
    scanf(""); cin.get(hoTen,sizeof(hoTen));
    cout<<"\NNhap vao diem TB: ";
    cin>>diemTB;
}
void SinhVien::xuat()
{
    cout<<"\nMa sinh vien la: "<<maSV;
    cout<<"\nTen sinh vien la: "<<hoTen;
    cout<<"\nDiem TB la: "<<diemTB;
    if(diemTB>=9)
        cout<<"\nXep loai gioi!";
}
