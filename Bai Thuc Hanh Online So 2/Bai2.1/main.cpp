#include <bits/stdc++.h>
using namespace std;

class DATE;
class HANG;

class NSX
{
    char TenNSX[30];
    char DiaChi[50];

    public:
        void NHAP();
        void XUAT();
        friend class HANG;
};

void NSX::NHAP()
{
    cout << "Nhap ten NSX: ";
    fflush(stdin);
    gets(TenNSX);

    cout << "Nhap dia chi: ";
    fflush(stdin);
    gets(DiaChi);
}

void NSX::XUAT()
{
    cout << "Ten NSX: " << TenNSX << endl;
    cout << "Dia chi: " << DiaChi << endl;
}

class HANG
{
    protected:
        char Tenhang[30];
        NSX x;
        float Dongia;

    public:
        void NHAP();
        void XUAT();
        HANG();
};

HANG::HANG()
{
    strcpy(Tenhang, "");
    strcpy(x.TenNSX, "");
    strcpy(x.DiaChi, "");
    Dongia = 0;
}

void HANG::NHAP()
{
    cout << "Nhap Ten Hang: ";
    fflush(stdin);
    gets(Tenhang);

    x.NHAP();

    cout << "Nhap don gia: ";
    cin >> Dongia;
}

void HANG::XUAT()
{
    cout << "Ten hang: " << Tenhang << endl;
    x.XUAT();
    cout << "Don gia: " << Dongia << endl;
}

class DATE
{
    int D;
    int M;
    int Y;

    public:
        void NHAP();
        void XUAT();
        friend class TIVI;
};

void DATE::NHAP()
{
    cout << "Nhap ngay: ";
    cin >> D;
    cout << "Nhap thang: ";
    cin >> M;
    cout << "Nhap nam: ";
    cin >> Y;
}

void DATE::XUAT()
{
    cout << D << "/" << M << "/" << Y;
}

class TIVI : public HANG
{
    float Kichthuoc;
    DATE NgayNhap;

    public:
        void NHAP();
        void XUAT();
        TIVI();
};

TIVI::TIVI() : HANG()
{
    Kichthuoc = 0;
    NgayNhap.D = 0;
    NgayNhap.M = 0;
    NgayNhap.Y = 0;
}

void TIVI::NHAP()
{
    HANG::NHAP();
    cout << "Nhap Kich thuoc: ";
    cin >> Kichthuoc;

    NgayNhap.NHAP();
}

void TIVI::XUAT()
{
    HANG::XUAT();
    cout << "Kich thuoc: " << Kichthuoc << endl;
    cout << "Ngay Nhap: ";
    NgayNhap.XUAT();
    cout << endl;
}

int main()
{
    TIVI tv1;
    tv1.NHAP();
    cout << "MAT HANG VUA NHAP: " << endl;
    tv1.XUAT();
    return 0;
}
