#include <bits/stdc++.h>
using namespace std;

class HANG
{
    char Mahang[10];
    char Tenhang[30];
    float Dongia;
    int Soluong;

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

    cout << "Nhap so luong: ";
    cin >> Soluong;
}

void HANG::XUAT()
{
    cout << setw(10) << Mahang << setw(30) << Tenhang << setw(10) << Dongia << setw(10) << Soluong << endl;
}

int main()
{
    HANG *array1;
    int n;

    cout << "Nhap n: ";
    cin >> n;

    array1 = new HANG[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap Mat Hang Thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }
    
    cout << setw(10) << "MA HANG"<< setw(30) << "TEN HANG" << setw(10) << "DON GIA" << setw(10) << "SO LUONG" << endl;
    
    for(int i = 0 ; i < n ; i++)
    {
        array1[i].XUAT();
    }
    return 0;
}