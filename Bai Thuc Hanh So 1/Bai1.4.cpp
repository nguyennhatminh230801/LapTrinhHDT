#include <bits/stdc++.h>
using namespace std;

class SACH
{
    char Masach[10];
    char Tensach[20];
    char Nxb[20];
    int Sotrang;
    float Giatien;

    public:
        void NHAP();
        void XUAT();
};

void SACH::NHAP()
{
    cout << "Nhap ma sach: ";
    fflush(stdin);
    gets(Masach);

    cout << "Nhap ten sach: ";
    fflush(stdin);
    gets(Tensach);

    cout << "Nhap nha xuat ban: ";
    fflush(stdin);
    gets(Nxb);

    cout << "Nhap so trang: ";
    cin >> Sotrang;

    cout << "Nhap gia tien: ";
    cin >> Giatien;
}

void SACH::XUAT()
{
    cout << setw(10) << Masach << setw(20) << Tensach << setw(20) << Nxb << setw(10) << Sotrang << setw(10) << Giatien << endl;
}

int main()
{
    SACH *array1;
    int n;

    cout << "Nhap so luong sach: ";
    cin >> n;

    array1 = new SACH[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap sach thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }

    cout << setw(10) << "MA SACH" << setw(20) << "TEN SACH" << setw(20) << "NXB" << setw(10) << "SO TRANG" << setw(10) << "GIA TIEN" << endl;

    for(int i = 0 ; i < n ; i++)
    {
        array1[i].XUAT();
    }
    
    return 0;
}