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
    //Khai bao bien
    SoPhuc tong;

    //Khai bao bien
    int n;

    //Nhap vao n so phuc
    cout<<"Nhap vao n so phuc: ";
    cin>>n;

    //Khai bao mang doi tuong dong
    SoPhuc *sp = new SoPhuc[n];

    //Nhap thong tin n so phuc
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap vao so phuc "<<i+1<<": \n";
        cin>>sp[i];

        //Tinh tong
        tong = tong + sp[i];
    }

    //Xuat cac so phuc vua nhap ra man hinh
    for(int i=0;i<n;i++)
    {
        cout<<"\nSo phuc thu "<<i+1<<": \n";
        cout<<sp[i];
    }

    cout<<"\nTong "<<n<<" so phuc la: "<<tong;

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

