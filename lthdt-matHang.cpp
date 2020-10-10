//Ho ten: Vu Minh Thu
//Lop: k63TH
//MaSV: 637865
//De:
/*
Bài 23(lthdtbai23.cpp): Nhập vào một danh sách n mặt hàng;
mỗi mặt hàng có tên hàng, số lượng, đơn giá.
Tính tổng tiền của n mặt hàng.
*/

#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao class
class MatHang
{
    private:
        char tenHang[21];
        int soLuong;
        float donGia;

    public:
        //Ham tao
        MatHang();

        //Ham tinh tien
        int tinhTien();

        //Ham ban
        friend istream& operator>>(istream &cin, MatHang &mh);
        friend ostream& operator<<(ostream &cout, MatHang &mh);
};


//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    int n,sum=0;

    //Nhap vao n mat hanng
    cout<<"Nhap vao n mat hang: ";
    cin>>n;

    //Khai bao mang doi tuong dong mat hang voi n phan tu
    MatHang *mh = new MatHang[n];

    //Doc vao thong tin cua n mat hang doc tu ban phim
    for(int i=0;i<n;i++)
    {
        cout<<"Mat hang thu "<<i+1<<" la:"<<endl;
        cin>>mh[i];

        //tinh tong tien
        sum+=mh[i].tinhTien();
    }

    //Dua ra man hinh thong tin cua mat hang
    cout<<"=== Thong tin cua mat hang ==="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Mat hang thu "<<i+1<<" la:"<<endl;
        cout<<mh[i]<<endl;
    }

    //Tong tien cua n mat hang
    cout<<"Tong tien cua"<< n <<"mat hang: "<<sum;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
 MatHang::MatHang():soLuong(0),donGia(0)
 {

 }

//Ham tinh tien
int MatHang::tinhTien()
{
    return soLuong*donGia;
}

//Ham ban
istream& operator>>(istream &cin, MatHang &mh)
{
    cout<<"Nhap vao ten hang: ";
    scanf(" "); cin.get(mh.tenHang,sizeof(mh.tenHang));
    cout<<"Nhap vao so luong: ";
    cin>>mh.soLuong;
    cout<<"Nhap vao don gia: ";
    cin>>mh.donGia;

    return cin;
}

ostream& operator<<(ostream &cout, MatHang &mh)
{
    cout<<"Ten mat hang: "<<mh.tenHang<<endl;
    cout<<"So luong: "<<mh.soLuong<<endl;
    cout<<"Don gia: "<<mh.donGia<<endl;

    return cout;
}

