#include <bits/stdc++.h>
using namespace std;

class HANG;

class DATE
{
    int D, M, Y;

    public:
        friend class HANG;
        friend void In(HANG *array1, int n);
};

class HANG
{
    char Mahang[10];
    char Tenhang[30];
    DATE Ngaysx;

    public:
        void NHAP();
        void XUAT();
        friend void In(HANG *array1, int n);
};

void HANG::NHAP()
{
    cout << "Nhap Ma Hang: ";
    fflush(stdin);
    gets(Mahang);

    cout << "Nhap ten hang: ";
    fflush(stdin);
    gets(Tenhang);

    cout << "Nhap Ngay San Xuat:" << endl;
    
    cout << "Nhap ngay: ";
    cin >> Ngaysx.D;
    
    cout << "Nhap thang: ";
    cin >> Ngaysx.M;
    
    cout << "Nhap nam: ";
    cin >> Ngaysx.Y;
}

void HANG::XUAT()
{
    cout << setw(10) << Mahang
         << setw(30) << Tenhang
         << setw(30) << Ngaysx.D << "/" << Ngaysx.M << "/" << Ngaysx.Y
         << endl;
}

void In(HANG *array1, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(array1[i].Ngaysx.Y == 2017)
        {
            array1[i].XUAT();
        }
    }
}

int main()
{
    HANG *array1;
    int n;
    
    cout << "Nhap so luong hang: ";
    cin >> n;

    array1 = new HANG[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap mat hang thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }

    cout << setw(10) << "MA HANG" << setw(30) << "TEN HANG" << setw(30) << "NGAY SX" << endl;
    
    for(int i = 0 ; i < n ; i++)
    {
        array1[i].XUAT();
    }

    cout << "MAT HANG SAN XUAT NAM 2017" << endl;
    cout << setw(10) << "MA HANG" << setw(30) << "TEN HANG" << setw(30) << "NGAY SX" << endl;

    In(array1, n);
    return 0;
}