//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH
/*
Bài 42(lthdtbai42.cpp): Tính diện tích và chu vi các hình: Hình chữ nhật biết 2 cạnh,
hình tam giác biết 3 cạnh, hình tròn biết bán kính. Nhập vào một số hình trong đó
có cả hình chữ nhật, hình tam giác và hình tròn. Đưa ra diện tích
và chu vi các hình đã nhập. Y/c cài đặt đa hình động và lớp trừu tượng; viết 1 hàm
lựa chọn hình, nhập kích thước cho hình và trả về hình đã nhập; viết 1 hàm đưa ra
diện tích và chu vi của một hình truyền vào qua đối số.
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
        //Ham ao thuan tuy, khong phai dinh nghia ham
        /*Khi lớp cha khai báo hàm ảo thuần túy
        ==> lớp con kế thừa từ lớp cha phải định nghĩa lại tất cả các hàm đó.*/
        virtual void nhap()=0;
        virtual float tinhCV()=0;
        virtual float tinhDT()=0;
};

class HinhCN:public Hinh
{
    private:
        float a,b;

    public:
        void nhap();
        float tinhCV();
        float tinhDT();
};

class HinhTG:public Hinh
{
    private:
        float a,b,c;

    public:
        void nhap();
        float tinhCV();
        float tinhDT();
};

class HinhTron:public Hinh
{
    private:
        float r;

    public:
        void nhap();
        float tinhCV();
        float tinhDT();
};

//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//Hinh CN
void HinhCN::nhap()
{
    cout<<"Nhập vào 2 cạnh của hình chữ nhật: ";
    cin>>a>>b;
}

float HinhCN::tinhDT()
{
    return a*b;
}

float HinhCN::tinhCV()
{
    return (a+b)*2;
}

//Hinh TG
void HinhTG::nhap()
{
    do
    {
        cout<<"Nhập vào 3 cạnh của tam giác: ";
        cin>>a>>b>>c;
        if (a >= b + c || b >= a + c || c >= a + b)
            cout << "Ba cạnh vừa nhập không phải là 3 cạnh của tam giác!";
    }
    while(a >= b + c || b >= a + c || c >= a + b);
}

float HinhTG::tinhCV()
{
    return a+b+c;
}

float HinhTG::tinhDT()
{
    float p = (a+b+c) / 2.0;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

//Hinh tron
void HinhTron::nhap()
{
  cout<<"Nhap vao ban kinh: ";
  cin>>r;
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}

