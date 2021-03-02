#include <bits/stdc++.h>
using namespace std;

class NGUOI
{
protected:
    char Hoten[30];
    int Tuoi;

public:
    void Nhap();
    void Xuat();
};

void NGUOI::Nhap()
{
    cout << "Nhap ho ten: ";
    fflush(stdin);
    gets(Hoten);

    cout << "Nhap tuoi: ";
    cin >> Tuoi;
}

void NGUOI::Xuat()
{
    cout << "Ho ten: " << Hoten << endl;
    cout << "Tuoi: " << Tuoi << endl;
}

class BENHVIEN
{
    char Tenbenhvien[30];
    char Diachi[50];
    NGUOI Giamdoc;
public:
    friend class BENHNHAN;
};

class BENHNHAN : public NGUOI
{
    char MaBenhNhan[10];
    char Tiensu[30];
    char Chandoan[30];
    BENHVIEN bv1;

public:
    void Nhap();
    void Xuat();
    friend void BONUS1(BENHNHAN *array1, int n);
    friend void BONUS2(BENHNHAN *array1, int n);
};

void BENHNHAN::Nhap()
{
    NGUOI::Nhap();
    cout << "Nhap Ma Benh Nhan: ";
    fflush(stdin);
    gets(MaBenhNhan);

    cout << "Nhap tien su: ";
    fflush(stdin);
    gets(Tiensu);

    cout << "Nhap chan doan: ";
    fflush(stdin);
    gets(Chandoan);

    cout << "Nhap Ten Benh Vien: ";
    fflush(stdin);
    gets(bv1.Tenbenhvien);

    cout << "Nhap Dia Chi: ";
    fflush(stdin);
    gets(bv1.Diachi);

    cout << "Nhap giam doc benh vien: " << endl;
    bv1.Giamdoc.Nhap();

}

void BENHNHAN::Xuat()
{
    NGUOI::Xuat();
    cout << "Ma Benh Nhan: " << MaBenhNhan << endl;
    cout << "Tien su: " << Tiensu << endl;
    cout << "Chan doan: " << Chandoan << endl;
    cout << "Ten Benh vien: " << bv1.Tenbenhvien << endl;
    cout << "Dia chi: " << bv1.Diachi << endl;
    cout << "Thong tin giam doc benh vien:" << endl;
    bv1.Giamdoc.Xuat();
}

void BONUS1(BENHNHAN *array1, int n)
{
    int count1 = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(array1[i].Tuoi > 30)
        {
            count1++;
        }
    }

    cout << "So benh nhan lon hon 30: " << count1 << endl;
}

void BONUS2(BENHNHAN *array1, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(stricmp(array1[i].MaBenhNhan, "BN01") == 0)
        {
            array1[i].Tuoi = 20;
        }
    }
}

int main()
{
    BENHNHAN *array1;
    int n;

    cout << "Nhap so luong benh nhan: ";
    cin >> n;

    array1 = new BENHNHAN[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "--------------------------------------------" << endl;
        cout << "Nhap benh nhan thu "<< i + 1 <<": " << endl;
        array1[i].Nhap();
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout << "--------------------------------------------" << endl;
        cout << "Thong Tin Benh Nhan Thu " << i + 1 << ": " << endl;
        array1[i].Xuat();
    }

    //Bonus 1: Dem so benh nhan lon hon 30 tuoi;
    BONUS1(array1, n);

    //Bonus 2: Sua thong tin benh nhan co ma BN01(neu co thanh 20 tuoi)
    BONUS2(array1, n);

    cout << "THONG TIN SAU KHI SUA" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << "--------------------------------------------" << endl;
        cout << "Thong Tin Benh Nhan Thu " << i + 1 << ": " << endl;
        array1[i].Xuat();
    }
    return 0;
}
