#include <bits/stdc++.h>
using namespace std;

class MONHOC;

class SINHVIEN
{
    char MaSV[10];
    char TenSV[30];
    char Lop[30];
    int Khoa;

    public:
        void NHAP();
        void XUAT();
};

void SINHVIEN::NHAP()
{
    cout << "Nhap ma sinh vien: ";
    fflush(stdin);
    gets(MaSV);

    cout << "Nhap ten sinh vien: ";
    fflush(stdin);
    gets(TenSV);

    cout << "Nhap lop: ";
    fflush(stdin);
    gets(Lop);

    cout << "Nhap Khoa: ";
    cin >> Khoa;
}

void SINHVIEN::XUAT()
{
    cout << "Ma sinh vien: " << MaSV << endl;
    cout << "Ten sinh vien: " << TenSV << endl;
    cout << "Lop: " << Lop << endl;
    cout << "Khoa: " << Khoa << endl;
}

class PHIEUDIEM
{
    SINHVIEN x;
    MONHOC *Monhoc;
    int n;

    public:
        void NHAP();
        void XUAT();
        friend void BONUS1(PHIEUDIEM a);
        friend void BONUS2(PHIEUDIEM a);
};

class MONHOC
{
    char TenMon[30];
    int Sotrinh;
    float Diem;

    public:
        void NHAP();
        void XUAT();
        friend class PHIEUDIEM;
        friend int Xuly1(MONHOC *mh, int n);
    
};

void MONHOC::NHAP()
{
    cout << "Nhap ten mon: ";
    fflush(stdin);
    gets(TenMon);

    cout << "Nhap so trinh: ";
    cin >> Sotrinh;

    cout << "Nhap diem: ";
    cin >> Diem;
}

void MONHOC::XUAT()
{
    cout << setw(30) << TenMon << setw(10) << Sotrinh << setw(10) << Diem << endl;
}

void PHIEUDIEM::NHAP()
{
    x.NHAP();

    cout << "Nhap so luong mon: ";
    cin >> n;

    Monhoc = new MONHOC[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap mon hoc thu " << i + 1 << ": " << endl;
        Monhoc[i].NHAP();
    }   
}

void PHIEUDIEM::XUAT()
{
    x.XUAT();

    cout << setw(30) << "TEN MON" << setw(10) << "SO TRINH" << setw(10) << "DIEM" << endl;

    float Tongdiem = 0;
    int Tongsotrinh = 0;

    for(int i = 0 ; i < n ; i++)
    {
        Monhoc[i].XUAT();

        Tongdiem += Monhoc[i].Sotrinh * Monhoc[i].Diem;
        Tongsotrinh += Monhoc[i].Sotrinh;
    }

    if(Tongsotrinh != 0)
    {
        cout << "Diem trung binh: " << Tongdiem / Tongsotrinh << endl;
    }
}

//Cho biet mon hoc co so trinh lon hon 3

int Xuly1(MONHOC *mh, int n)
{
    int count1 = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(mh[i].Sotrinh > 3)
        {
            count1++;
        }
    }

    return count1;
}

void BONUS1(PHIEUDIEM a)
{
    cout << "So mon hoc: " << Xuly1(a.Monhoc, a.n) << endl;
}

void BONUS2(PHIEUDIEM a)
{
    MONHOC res1;
    res1.NHAP();

    int pos;

    cout << "Nhap vi tri can chen: ";
    cin >> pos;
    pos--;

    if(pos >= 0 && pos <= a.n)
    {
        int n1 = a.n + 1;
        MONHOC *mh = new MONHOC[n1];
        
        for(int i = 0 ; i < a.n ; i++)
        {
            mh[i] = a.Monhoc[i];
        }
		
		for(int i = a.n ; i > pos ; i++)
        {
            mh[i] = mh[i - 1];
        }
        mh[pos] = res1;
        
        delete a.Monhoc;

        a.Monhoc = new MONHOC[n1];
		
	   for(int i = 0 ; i < n1 ; i++)
       {
           a.Monhoc[i] = mh[i];
       }

       cout << setw(30) << "TEN MON" << setw(10) << "SO TRINH" << setw(10) << "DIEM" << endl;
       
       for(int i = 0 ; i < n1 ; i++)
       {
           a.Monhoc[i].XUAT();
       }

        a.n++;
    }
    else
    {
        cout << "Vi tri chen nam ngoai khoang" << endl;
    }
}

int main()
{
    PHIEUDIEM obj1;
    obj1.NHAP();
    obj1.XUAT();
    
    BONUS1(obj1);
    BONUS2(obj1);
    return 0;
}