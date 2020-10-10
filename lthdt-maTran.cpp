//Ho ten: Vu Minh Thu
//MaSV: 637865
//Lop: K63TH
/*
De:Bài 21(lthdtbai21.cpp): Tính tổng 2 ma trận nguyên: Cmxn = Amxn + Bmxn.
Ma trận Amxn để trong
tệp văn bản 'matran-A.txt', ma trận Bmxn để trong tệp văn bản 'matran-B.txt'.
Đưa các ma trận ra màn hình theo định dạng hàng, cột.

*/

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class MaTran
{
    private:
        enum {size=20};
        int a[size][size];
        int m,n;

    public:
        //Ham tao
        MaTran();

        //Ham chong toan tu cong
        MaTran operator+(const MaTran &mt2);
        MaTran operator-(const MaTran &mt2);

        //Ham ban
        friend ifstream& operator>>(ifstream &fin, MaTran &mt);
        friend ostream& operator<<(ostream &cout, MaTran &mt);
};

//===chuong trinh chinh===
int main()
{

    //Tao 3 doi tuong ma tran
    MaTran A,B,C,D;

    //Tao doi tuong doc vao tu tep
    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");

    //Doc 2 ma tran tu tep
    finA>>A;
    finB>>B;

    //Tong hieu
    C=A+B;
    D=A-B;

    //Dua ra cac ma tran
    cout<<"Ma tran A:\n"<<A;

    cout<<"\n\nMa tran B:\n"<<B;

    cout<<"\n\nMa tran C = A + B:\n"<<C;
    cout<<"\n\nMa tran C = A - B:\n"<<D;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
MaTran::MaTran():m(0),n(0)
{

}

MaTran MaTran::operator+(const MaTran &mt2)
{
    MaTran tong;

    if(m == mt2.m || n == mt2.n)
    {
        //Cong hai ma tran
        tong.m=m;
        tong.n=n;

        for(int i=0; i<mt2.m; i++)
            for(int j=0; j<mt2.n; j++)
                tong.a[i][j]=a[i][j] + mt2.a[i][j];
    }

    return tong;
}

MaTran MaTran::operator-(const MaTran &mt2)
{
    MaTran hieu;

    if(m == mt2.m || n == mt2.n)
    {
        hieu.m = m;
        hieu.n=n;

        for(int i=0;i<mt2.m;i++)
            for(int j=0;j<mt2.n;j++)
                hieu.a[i][j] = a[i][j] - mt2.a[i][j];
    }

    return hieu;
}

ifstream& operator>>(ifstream &fin, MaTran &mt)
{
    //Doc vao m hang, n cot cua ma tran
    fin>>mt.m>>mt.n;

    for(int i=0; i<mt.m; i++)
        for(int j=0; j<mt.n; j++)
            fin>>mt.a[i][j];

    return fin;
}

ostream& operator<<(ostream &cout, MaTran &mt)
{
    for(int i=0; i<mt.m; i++)
    {
        for(int j=0; j<mt.n; j++)
        {
            cout<<mt.a[i][j]<<"  ";
        }

        cout<<"\n";
    }
    return cout;
}

