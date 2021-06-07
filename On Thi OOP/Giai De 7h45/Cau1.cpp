#include <bits/stdc++.h>
using namespace std;

class BANGTHONGKE;

class DONVI
{
    char MaDV[20];
    char TenDV[50];
    char DiaChiDV[50];
    char TruongDV[30];

    public:
        void NHAP();
        void XUAT();
};

void DONVI::NHAP()
{
    cout << "Nhap Ma Don Vi: ";
    fflush(stdin);
    gets(MaDV);
    
    cout << "Nhap Ten Don Vi: ";
    fflush(stdin);
    gets(TenDV);

    cout << "Nhap Dia Chi Don Vi: ";
    fflush(stdin);
    gets(DiaChiDV);

    cout << "Nhap Truong Don Vi: ";
    fflush(stdin);
    gets(TruongDV);

}

void DONVI::XUAT()
{
    cout << "Ma Don Vi: " << setw(20) << MaDV<<"\t\t";
    cout << "Ten Don Vi: " << setw(50) << TenDV << endl;
    cout << "Dia Chi Don Vi: " << setw(50) << DiaChiDV<< "\t\t";
    cout << "Truong Don Vi: " << setw(30) << TruongDV << endl;
}

class TAISAN
{
    char MaTS[20];
    char TenTS[50];
    char DonViTinh[30];
    int GiaTri;

    public:
        void NHAP();
        void XUAT();
        friend class BANGTHONGKE;
};

void TAISAN::NHAP()
{
    cout << "Nhap Ma Tai San: ";
    fflush(stdin);
    gets(MaTS);

    cout << "Nhap Ten Tai San: ";
    fflush(stdin);
    gets(TenTS);

    cout << "Nhap Don Vi Tinh : ";
    fflush(stdin);
    gets(DonViTinh);

    cout << "Nhap Gia Tri: ";
    cin >> GiaTri;
}

void TAISAN::XUAT()
{
    cout << setw(20) << MaTS << setw(50) << TenTS << setw(30) << DonViTinh << setw(10) << GiaTri << endl;
}

class BANGTHONGKE
{
    char NgayLap[20];
    char NguoiLap[30];
    DONVI x;
    TAISAN *a;
    int n;

    public:
        void NHAP();
        void XUAT();
};

void BANGTHONGKE::NHAP()
{
    cout << "Nhap Ngay Lap: ";
    fflush(stdin);
    gets(NgayLap);

    cout << "Nhap Nguoi Lap: ";
    fflush(stdin);
    gets(NguoiLap);

    x.NHAP();

    cout << "Nhap So Luong Tai San: ";
    cin >> n;

    a = new TAISAN[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap Tai San Thu " << i + 1 << ": " << endl;
        a[i].NHAP();
    }
}

void BANGTHONGKE::XUAT()
{
    cout << "TONG CONG TY ABC" << endl;
    cout << "\t\t\t\t\tBANG THONG KE TAI SAN" << endl;

    cout << "Ngay Lap: " << setw(20) << NgayLap;
    cout << "Nguoi Lap: " << setw(50) << NguoiLap << endl;

    x.XUAT();

    cout << "Chi Tiet:"<< endl;
    cout << setw(20) << "Ma Tai San"<< setw(50) << "Ten Tai San"<< setw(30) << "Don Vi Tinh" << setw(10) << "Don Gia" << endl;

    int TongDonGia = 0;
    for(int i = 0 ; i < n ; i++)
    {
        a[i].XUAT();
        TongDonGia += a[i].GiaTri;
    }
    cout << "Tong So Thiet Bi La: " << setw(60) << TongDonGia << endl;

    cout << setw(10) << "Giam Doc";
    cout << "\t\t\tPhong Quan Ly";
    cout << "\t\t\tNguoi Lap" << endl;
}

int main()
{
    BANGTHONGKE BTK1;
    BTK1.NHAP();
    BTK1.XUAT();
    return 0;
}