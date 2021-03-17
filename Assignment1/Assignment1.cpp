#include <bits/stdc++.h>
using namespace std;

class PHIEU;

class NHACUNGCAP
{
    char MaNCC[10];
    char TenNCC[50];
    char DiaChiNCC[50];
    char SoDienThoaiNCC[11];

    public:
        void NHAP();
        void XUAT();
};

void NHACUNGCAP::NHAP()
{
    cout << "Nhap ma nha cung cap: ";
    fflush(stdin);
    gets(MaNCC);

    cout << "Nhap ten nha cung cap: ";
    fflush(stdin);
    gets(TenNCC);

    cout << "Nhap dia chi nha cung cap: ";
    fflush(stdin);
    gets(DiaChiNCC);

    cout << "Nhap so dien thoai nha cung cap: ";
    fflush(stdin);
    gets(SoDienThoaiNCC);
}

void NHACUNGCAP::XUAT()
{
    cout << "Ma NCC: " << setw(12) << "Ten NCC: " << setw(50) << TenNCC << endl;
    cout << "Dia Chi: " << setw(52) << "So Dien Thoai: " << setw(15) << SoDienThoaiNCC << endl;
}

class HANG
{
    char MaSP[10];
    char TenSP[30];
    int Soluong;
    float Dongia;

    public:
        void NHAP();
        void XUAT();
        friend class PHIEU;
        friend void BONUS1(PHIEU p1);
        friend void BONUS2(PHIEU p1);
};

void HANG::NHAP()
{
    cout << "Nhap Ma San Pham: ";
    fflush(stdin);
    gets(MaSP);

    cout << "Nhap Ten San Pham: ";
    fflush(stdin);
    gets(TenSP);

    cout << "Nhap So Luong: ";
    cin >> Soluong;

    cout << "Nhap Don Gia: ";
    cin >> Dongia;
}

void HANG::XUAT()
{
    cout << setw(10) << MaSP << setw(30) << TenSP << setw(10) << Soluong << setw(10) << Dongia;
}

class PHIEU
{
    char Maphieu[10];
    char Ngaylap[30];
    NHACUNGCAP Ncc1;
    HANG *MatHang;
    int n;

    public:
        void NHAP();
        void XUAT();
        friend void BONUS1(PHIEU p1);
        friend void BONUS2(PHIEU p1);
};

void PHIEU::NHAP()
{
    cout << "Nhap Ma Phieu: ";
    fflush(stdin);
    gets(Maphieu);

    cout << "Nhap Ngay Thanh Lap: " << endl;
    fflush(stdin);
    gets(Ngaylap);

    Ncc1.NHAP();

    cout << "Nhap So Luong Mat Hang: ";
    cin >> n;

    MatHang = new HANG[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap mat hang thu " << i + 1 << ": " << endl;
        MatHang[i].NHAP();
    }
}

void PHIEU::XUAT()
{
    cout << setw(40) << "PHIEU NHAP VAN PHONG PHAM" << endl;
    cout << "Ma Phieu: " << setw(10) << Maphieu << " Ngay Lap: " << setw(10) << Ngaylap << endl;
    Ncc1.XUAT();

    cout << setw(10) << "MA SP" << setw(30) << "TEN SP" << setw(10) << "SO LUONG" << setw(10) << "DON GIA" << setw(10) << "THANH TIEN" << endl;
    float Tongtien = 0;

    for(int i = 0 ; i < n ; i++)
    {
        MatHang[i].XUAT();

        cout << setw(10) << MatHang[i].Soluong * MatHang[i].Dongia << endl;
        Tongtien += MatHang[i].Soluong * MatHang[i].Dongia;
    }

    cout << setw(60) << "TONG TIEN: " << Tongtien << endl;
}

//Cho biet co bao nhieu san pham co so luong nhap nho hon 80 trong phieu
void BONUS1(PHIEU p1)
{
    int count1 = 0;

    for(int i = 0 ; i < p1.n ; i++)
    {
        if(p1.MatHang[i].Soluong < 80)
        {
            count1++;
        }
    }

    cout << "So san pham co so luong nhap nho hon 80 trong phieu la: " << count1 << endl;
}

//Sap xep danh sach cac san pham theo chieu tang dan cua don gia va in lai phieu
void BONUS2(PHIEU p1)
{
    for(int i = 0 ; i < p1.n - 1 ; i++)
    {
        for(int j = 0 ; j < p1.n - i - 1 ; j++)
        {
            if(p1.MatHang[j].Dongia > p1.MatHang[j + 1].Dongia)
            {
                HANG change = p1.MatHang[j];
                p1.MatHang[j] = p1.MatHang[j + 1];
                p1.MatHang[j + 1] = change;
            }
        }
    }

    p1.XUAT();
}

int main()
{
    PHIEU p1;
    p1.NHAP();
    p1.XUAT();
    
    BONUS1(p1);
    BONUS2(p1);
    return 0;
}
