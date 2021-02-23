#include <bits/stdc++.h>
using namespace std;

class HANG;

class NSX
{
    char MaNCC[10];
    char TenNCC[30];
    char Diachi[50];

    public:
        void NHAP();
        void XUAT();
};

void NSX::NHAP()
{
    cout << "Nhap ma NCC:";
    fflush(stdin);
    gets(MaNCC);

    cout << "Nhap ten NCC:";
    fflush(stdin);
    gets(TenNCC);

    cout << "Nhap dia chi:";
    fflush(stdin);  
    gets(Diachi);
}

void NSX::XUAT()
{
    cout << "Ma NCC: " << MaNCC << endl;
    cout << "Ten NCC: " << TenNCC << endl;
    cout << "Dia Chi: " << Diachi << endl;
}

class PHIEUNHAP
{
    char Maphieu[10];
    char Ngaylap[20];
    NSX X;
    HANG *MatHang;
    int n;

    public:
        void NHAP();
        void XUAT();
};
void PHIEUNHAP::NHAP()
{
    cout << "Nhap ma phieu: ";
    fflush(stdin);
    gets(Maphieu);

    cout << "Nhap ngay lap: ";
    fflush(stdin);
    gets(Ngaylap);

    X.NHAP();
    cout << "Nhap so mat hang: ";
    cin >> n;

    MatHang = new HANG[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap mat hang thu " << i + 1 << ": " << endl;
        MatHang[i].NHAP();
    }
}

void PHIEUNHAP::XUAT()
{
    cout << "Ma Phieu: " << Maphieu << endl;
    cout << "Ngay Lap: " << Ngaylap << endl;
    
    X.XUAT();

    float CongThanhTien = 0;

    cout << setw(30) << "TEN HANG" << setw(10) << "DON GIA" << setw(10) << "SO LUONG" << setw(10) << "THANH TIEN" << endl;

    for(int i = 0 ; i < n ; i++)
    {
        MatHang[i].XUAT();
        cout << setw(10) << MatHang[i].Dongia * MatHang[i].Soluong << endl;
        CongThanhTien += MatHang[i].Dongia * MatHang[i].Soluong;
    }

    cout << "CONG THANH TIEN: " << CongThanhTien << endl;
}

class HANG
{
    char Tenhang[30];
    float Dongia;
    int Soluong;

    public:
        void NHAP();
        void XUAT();
        friend class PHIEUNHAP;
};

void HANG::NHAP()
{
    cout << "Nhap ten hang: ";
    fflush(stdin);
    gets(Tenhang);

    cout << "Nhap don gia:";
    cin >> Dongia;

    cout << "Nhap so luong:";
    cin >> Soluong;
}

void HANG::XUAT()
{
    cout << setw(30) << Tenhang << setw(10) << Dongia << setw(10) << Soluong;  
}

int main()
{
    PHIEUNHAP p1;

    p1.NHAP();
    p1.XUAT();
    return 0;
}