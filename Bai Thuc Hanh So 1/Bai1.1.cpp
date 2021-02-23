#include <bits/stdc++.h>
using namespace std;

class SINHVIEN
{
    char Masv[10];
    char Hoten[30];
    int Tuoi;
    float Diem;

    public:
        void NHAP();
        void XUAT();
};

void SINHVIEN::NHAP()
{
    cout << "Nhap ma sinh vien: ";
    fflush(stdin);
    gets(Masv);

    cout << "Nhap ho ten: ";
    fflush(stdin);
    gets(Hoten);

    cout << "Nhap tuoi: ";
    cin >> Tuoi;

    cout << "Nhap diem: ";
    cin >> Diem;
}

void SINHVIEN::XUAT()
{
    cout << setw(10) << Masv << setw(30) << Hoten << setw(10) << Tuoi << setw(10) << Diem << endl;
}

int main()
{
    SINHVIEN A, B;

    A.NHAP();
    B.NHAP();

    cout << setw(10) << "MA SV" << setw(30) << "HO TEN" << setw(10) << "TUOI" << setw(10) << "DIEM" << endl;
    A.XUAT();
    B.XUAT();
    return 0;
}