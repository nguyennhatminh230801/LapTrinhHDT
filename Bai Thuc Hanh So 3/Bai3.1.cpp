#include <bits/stdc++.h>
using namespace std;

class SINHVIEN
{
    char Masv[10];
    char Hoten[30];
    float DiemToan, DiemLy, DiemHoa;

public:
    void NHAP();
    void XUAT();
    friend void SapXep(SINHVIEN *array1, int n);
};

void SINHVIEN::NHAP()
{
    cout << "Nhap ma sinh vien: ";
    fflush(stdin);
    gets(Masv);

    cout << "Nhap ho ten: ";
    fflush(stdin);
    gets(Hoten);

    cout << "Nhap Diem Toan: ";
    cin >> DiemToan;

    cout << "Nhap Diem Ly: ";
    cin >> DiemLy;

    cout << "Nhap Diem Hoa: ";
    cin >> DiemHoa;
}

void SINHVIEN::XUAT()
{
    cout << setw(10) << Masv << setw(30) << Hoten << setw(5) << DiemToan << setw(5) << DiemLy << setw(5) << DiemHoa << setw(10) << DiemToan + DiemLy + DiemHoa << endl;
}

void SapXep(SINHVIEN *array1, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array1[j].DiemToan + array1[j].DiemLy + array1[j].DiemHoa > array1[j + 1].DiemToan + array1[j + 1].DiemLy + array1[j + 1].DiemHoa)
            {
                SINHVIEN change = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = change;
            }
        }
    }
}

int main()
{
    SINHVIEN *array1;
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    array1 = new SINHVIEN[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap sinh vien thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }

    SapXep(array1, n);
    
    cout << setw(10) << "MA SV" << setw(30) << "HO TEN" << setw(5) << "TOAN" << setw(5) << "LY" << setw(5) << "HOA" << setw(10) << "TONG DIEM" << endl;
    
    for (int i = 0; i < n; i++)
    {
        array1[i].XUAT();
    }
    return 0;
}
