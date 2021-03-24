#include <bits/stdc++.h>
using namespace std;

class PERSON
{
    protected:
        char Hoten[30];
        char Ngaysinh[20];
        char Quequan[50];
};

class KYSU : public PERSON
{
    char Nganh[30];
    int NamTN;

    public:
        void NHAP();
        void XUAT();
        friend void InThongTin(KYSU array1[], int n);
};

void KYSU::NHAP()
{
    cout << "Nhap Nganh: ";
    fflush(stdin);
    cin.getline(Nganh, 30);

    cout << "Nhap nam tot nghiep: ";
    cin >> NamTN;

    cout << "Nhap ho ten: ";
    fflush(stdin);
    cin.getline(Hoten, 30);

    cout << "Nhap Ngay Sinh: ";
    fflush(stdin);
    cin.getline(Ngaysinh, 20);

    cout << "Nhap que quan: ";
    fflush(stdin);
    cin.getline(Quequan, 50);
}

void KYSU::XUAT()
{
    cout << setw(30) << Nganh
         << setw(10) << NamTN
         << setw(30) << Hoten
         << setw(20) << Ngaysinh
         << setw(50) << Quequan 
         << endl;
}

void InThongTin(KYSU array1[], int n)
{
    int NamTNMax = array1[0].NamTN;

    for(int i = 1 ; i < n ; i++)
    {
        if(NamTNMax < array1[i].NamTN)
        {
            NamTNMax = array1[i].NamTN;
        }
    }

    cout << setw(30) << "NGANH" << setw(10) << "NAM TN" << setw(30) << "HO TEN" << setw(20) << "NGAY SINH" << setw(50) << "QUE QUAN" << endl;

    for(int i = 0 ; i < n ; i++)
    {
        if(array1[i].NamTN == NamTNMax)
        {
            array1[i].XUAT();
        }
    }
}

int main()
{
    KYSU *array1;
    int n;

    cout << "Nhap so luong ky su: ";
    cin >> n;

    array1 = new KYSU[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap Thong Tin Ky Su Thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }

    cout << setw(30) << "NGANH" << setw(10) << "NAM TN" << setw(30) << "HO TEN" << setw(20) << "NGAY SINH" << setw(50) << "QUE QUAN" << endl;

    for(int i = 0 ; i < n ; i++)
    {
        array1[i].XUAT();
    }

    cout << "THONG TIN CAC KY SU VUA MOI TOT NGHIEP" << endl;

    InThongTin(array1, n);

    return 0;
}