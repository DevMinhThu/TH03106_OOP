//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH
/*
Bài 27(lthdtbai27.cpp): Viết chương trình nhập vào danh sách n sinh viên,
mỗi sinh viên có thông tin về mã sinh viên, tên và điểm tbc.
Mã SV là các số nguyên được lấy tự động có giá trị từ 11 trở đi.
Đưa ra màn hình số lượng (không dùng n) và danh sách sinh viên đã nhập.
Yêu cầu trong chương trình có sử dụng biến tĩnh và hàm tĩnh;
sử dụng mảng đối tượng động.

*/

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class SinhVien
{
    private:
        char tenSV[31];
        int maSV;
        float diemTB;
        static int stt;

    public:
        void nhap();
        void hienThi();
        static int laySL();
};

//===chuong trinh chinh===
int main()
{


    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void SinhVien::nhap()
{
    cout<<"Nhap ten sinh vien: ";
    scanf(""); cin.get(tenSV,sizeof(tenSV));

    //MaSV duoc lay tu dong
    maSV = ++stt;

    cout<<"Nhap vao diem trung binh: ";
    cin>>diemTB;
}

void SinhVien::hienThi()
{
    cout<<"Ho va ten: "<<tenSV<<endl;
    cout<<"Ma sinh vien: "<<maSV<<endl;
    printf("Diem trung binh: %.1f",diemTB);
}

int SinhVien::laySL()
{
    return stt-10;
}

