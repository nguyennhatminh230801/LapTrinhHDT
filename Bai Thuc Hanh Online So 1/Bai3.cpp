#include <bits/stdc++.h>
using namespace std;

class NHANVIEN
{
    char TenNV[20];
    char ChucVu[20];

    public:
        void NHAP();
        void XUAT();
};

void NHANVIEN::NHAP()
{
    cout << "Nhap ten nhan vien: ";
    fflush(stdin);
    gets(TenNV);

    cout << "Nhap chuc vu: ";
    fflush(stdin);
    gets(ChucVu);
}

void NHANVIEN::XUAT()
{
    cout << "Ten nhan vien: " << TenNV << endl;
    cout << "Chuc vu: " << ChucVu << endl;
}

class PHONG
{
    char MaPhong[10];
    char TenPhong[30];
    char TruongPhong[30];

    public:
        void NHAP();
        void XUAT();
};

void PHONG::NHAP()
{   
    cout << "Nhap ma phong: ";
    fflush(stdin);
    gets(MaPhong);

    cout << "Nhap ten phong: ";
    fflush(stdin);
    gets(TenPhong);

    cout << "Nhap truong phong: ";
    fflush(stdin);
    gets(TruongPhong);

}

void PHONG::XUAT()
{
    cout << "Ma phong: " << MaPhong << endl;
    cout << "Ten phong: " << TenPhong << endl;
    cout << "Truong phong: " << TruongPhong << endl;
}

class TAISAN
{
    char TenTS[30];
    int Soluong;
    char Tinhtrang[50];

    public:
        void NHAP();
        void XUAT();
        friend class PHIEU;
        friend void Xuly1(TAISAN ts[], int n);
        friend void Xuly2(TAISAN ts[], int n);
};

void TAISAN::NHAP()
{
    cout << "Nhap ten tai san: ";
    fflush(stdin);
    gets(TenTS);

    cout << "Nhap so luong: ";
    cin >> Soluong;

    cout << "Nhap tinh trang: ";
    fflush(stdin);
    gets(Tinhtrang);
}

void TAISAN::XUAT()
{
    cout << setw(30) << TenTS << setw(10) << Soluong << setw(50) << Tinhtrang << endl;
}

class PHIEU
{
    char MaPhieu[10];
    char NgayKiemKe[10];
    NHANVIEN x;
    PHONG Y;
    TAISAN *array1;
    int n;

    public:
        void NHAP();
        void XUAT();
        friend void BONUS1(PHIEU a);
        friend void BONUS2(PHIEU a);
};

void PHIEU::NHAP()
{
    cout << "Nhap ma phieu: ";
    fflush(stdin);
    gets(MaPhieu);

    cout << "Nhap ngay kiem ke: ";
    fflush(stdin);
    gets(NgayKiemKe);

    x.NHAP();
    Y.NHAP();

    cout << "Nhap So Luong: ";
    cin >> n;

    array1 = new TAISAN[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap tai san thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }
}

void PHIEU::XUAT()
{
    cout << "Ma phieu: " << MaPhieu << endl;
    cout << "Ngay kiem ke: " << NgayKiemKe << endl;

    x.XUAT();
    Y.XUAT();

    cout << setw(30) << "TEN TS" << setw(10) << "SO LUONG" << setw(50) << "TINH TRANG" << endl;
    
    int TongSL = 0;

    for(int i = 0 ; i < n ; i++)
    {
        array1[i].XUAT();
        TongSL += array1[i].Soluong;
    }

    cout << "So tai san da kiem ke: " << n << endl;
    cout << "Tong So Luong: " << TongSL << endl;
}

void Xuly1(TAISAN ts[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(stricmp(ts[i].TenTS, "May vi tinh") == 0)
        {
            ts[i].Soluong = 20;
        }
    }
}

void Xuly2(TAISAN ts[], int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(ts[j].Soluong > ts[j + 1].Soluong)
            {
                TAISAN change = ts[j];
                ts[j] = ts[j + 1];
                ts[j + 1] = change;
            }
        }
    }
}

void BONUS1(PHIEU a)
{
    Xuly1(a.array1, a.n);
    a.XUAT();
}

void BONUS2(PHIEU a)
{
    Xuly2(a.array1, a.n);
    a.XUAT();
}

int main()
{
    PHIEU a;
    a.NHAP();
    a.XUAT();

    BONUS1(a);
    BONUS2(a);
    return 0;
}