#include <bits/stdc++.h>
using namespace std;

class KHOA
{
    char Makhoa[10];
    char Tenkhoa[30];
    char Truongkhoa[30];
public:
    friend class TRUONGDH;
};

class BAN
{
    char Maban[10];
    char Tenban[30];
    char NgayThanhLap[15];
public:
    friend class TRUONGDH;
};

class TRUONG
{
protected:
    char Matruong[10];
    char Tentruong[30];
    char Diachi[50];

public:
    void Nhap();
    void Xuat();
};

void TRUONG::Nhap()
{
    cout << "Nhap ma truong: ";
    fflush(stdin);
    gets(Matruong);

    cout << "Nhap ten truong: ";
    fflush(stdin);
    gets(Tentruong);

    cout << "Nhap dia chi: ";
    fflush(stdin);
    gets(Diachi);
}

void TRUONG::Xuat()
{
    cout << "Ma truong: " << Matruong << endl;
    cout << "Ten truong: " << Tentruong << endl;
    cout << "Dia chi: " << Diachi << endl;
}

class TRUONGDH : public TRUONG
{
    KHOA *x;
    int n;
    BAN *y;
    int m;
public:
    void Nhap();
    void Xuat();
};

void TRUONGDH::Nhap()
{
    TRUONG::Nhap();
    cout << "Nhap So luong Khoa: ";
    cin >> n;
    x = new KHOA[n];
    for(int i = 0 ; i < n ; i++){
        cout << "Nhap Khoa Thu " << i + 1 << ": " << endl;
        cout << "Nhap Ma Khoa: ";
        fflush(stdin);
        gets(x[i].Makhoa);

        cout << "Nhap ten khoa: ";
        fflush(stdin);
        gets(x[i].Tenkhoa);

        cout << "Nhap truong khoa: ";
        fflush(stdin);
        gets(x[i].Truongkhoa);
    }

    cout << "Nhap so luong ban: ";
    cin >> m;

    y = new BAN[m];

    for(int i = 0 ; i < m ; i++){
        cout << "Nhap Ban Thu " << i + 1 << ": " << endl;
        cout << "Nhap Ma ban: ";
        fflush(stdin);
        gets(y[i].Maban);

        cout << "Nhap ten ban: ";
        fflush(stdin);
        gets(y[i].Tenban);

        cout << "Nhap ngay thanh lap: ";
        fflush(stdin);
        gets(y[i].NgayThanhLap);
    }
}

void TRUONGDH::Xuat()
{
    //In thong tin
    TRUONG::Xuat();

    cout << "THONG TIN KHOA" << endl;
    cout << setw(10) <<  "MA KHOA" << setw(30) << "TEN KHOA" << setw(30) << "TRUONG KHOA" << endl;

    for(int i = 0 ; i < n ; i++)
    {
        cout << setw(10) << x[i].Makhoa << setw(30) << x[i].Tenkhoa << setw(30) << x[i].Truongkhoa << endl;
    }

    cout << "THONG TIN BAN" << endl;
    cout << setw(10) << "MA BAN" << setw(30) << "TEN BAN" << setw(15) << "NGAY THANH LAP" << endl;

    for(int i = 0 ; i < m ; i++)
    {
        cout << setw(10) << y[i].Maban << setw(30) << y[i].Tenban << setw(15) << y[i].NgayThanhLap << endl;
    }

    //Bonus1: Xoa thong tin ve Khoa co Ma Khoa la KH01

    while(true)
    {
        int pos = -1;

        for(int i = 0 ; i < n ; i++)
        {
            if(stricmp(x[i].Makhoa, "KH01") == 0)
            {
                pos = i;
                break;
            }
        }

        if(pos == -1)
        {
            break;
        }

        for(int i = pos ; i < n ; i++)
        {
            strcpy(x[i].Makhoa, x[i + 1].Makhoa);
            strcpy(x[i].Tenkhoa, x[i + 1].Tenkhoa);
            strcpy(x[i].Truongkhoa, x[i + 1].Truongkhoa);
        }

        n--;
    }

    cout << "THONG TIN SAU KHI XOA" << endl;

    TRUONG::Xuat();
    cout << "THONG TIN KHOA" << endl;
    cout << setw(10) <<  "MA KHOA" << setw(30) << "TEN KHOA" << setw(30) << "TRUONG KHOA" << endl;

    for(int i = 0 ; i < n ; i++)
    {
        cout << setw(10) << x[i].Makhoa << setw(30) << x[i].Tenkhoa << setw(30) << x[i].Truongkhoa << endl;
    }
    cout << "THONG TIN BAN" << endl;
    cout << setw(10) << "MA BAN" << setw(30) << "TEN BAN" << setw(15) << "NGAY THANH LAP" << endl;

    for(int i = 0 ; i < m ; i++)
    {
        cout << setw(10) << y[i].Maban << setw(30) << y[i].Tenban << setw(15) << y[i].NgayThanhLap << endl;
    }
}

int main()
{
    TRUONGDH DH1;
    DH1.Nhap();
    DH1.Xuat();
    return 0;
}
