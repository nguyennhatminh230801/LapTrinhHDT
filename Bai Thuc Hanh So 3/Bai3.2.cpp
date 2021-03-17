#include <bits/stdc++.h>
using namespace std;

class NSX
{
    char Mansx[10];
    char Tennsx[30];
    char Dcnsx[50];

    public:
        friend class HANG;
};

class HANG
{
    char Mahang[10];
    char Tenhang[30];
    float Dongia;
    float Trongluong;
    NSX x;

    public:
        void NHAP();
        void XUAT();
};  

void HANG::NHAP()
{
    cout << "Nhap ma hang: ";
    fflush(stdin);
    gets(Mahang);

    cout << "Nhap ten hang: ";
    fflush(stdin);
    gets(Tenhang);

    cout << "Nhap don gia: ";
    cin >> Dongia;

    cout << "Nhap trong luong: ";
    cin >> Trongluong;

    cout << "Nhap ma nha san xuat: ";
    fflush(stdin);
    gets(x.Mansx);

    cout << "Nhap ten nha san xuat: ";
    fflush(stdin);
    gets(x.Tennsx);

    cout << "Nhap dia chi nha san xuat: ";
    fflush(stdin);
    gets(x.Dcnsx);
}

void HANG::XUAT()
{
    cout << "MA HANG: " << Mahang << endl;
    cout << "TEN HANG: " << Tenhang << endl;
    cout << "DON GIA: " << Dongia << endl;  
    cout << "TRONG LUONG: " << Trongluong << endl;
    cout << "MA NSX: " << x.Mansx << endl;
    cout << "TEN NSX: " << x.Tennsx << endl;
    cout << "DIA CHI NSX: " << x.Dcnsx << endl;
}

int main()
{
    HANG x;

    x.NHAP();
    x.XUAT();   
    return 0;
}