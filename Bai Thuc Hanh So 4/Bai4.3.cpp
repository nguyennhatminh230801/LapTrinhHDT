#include <bits/stdc++.h>
using namespace std;

class VEHICLE
{
    protected:
        char Nhanhieu[30];
        int Namsx;
        char Hang[30];

    public:
        void NHAP();
        void XUAT();
};

void VEHICLE::NHAP()
{
    cout << "Nhap nhan hieu: ";
    fflush(stdin);
    cin.getline(Nhanhieu, 30);

    cout << "Nhap nam SX: ";
    cin >> Namsx;

    cout << "Nhap hang: ";
    fflush(stdin);
    cin.getline(Hang, 30);
}

void VEHICLE::XUAT()
{
    cout << "Nhan hieu: " << Nhanhieu << endl;
    cout << "Nam SX: " << Namsx << endl;
    cout << "Hang: " << Hang << endl;
}

class OTO : public VEHICLE
{
    int SoChoNgoi;
    float DungTich;

    public:
        void NHAP();
        void XUAT();
        friend void SuaDungTich(OTO &obj1);
};

void OTO::NHAP()
{
    VEHICLE::NHAP();

    cout << "Nhap So Cho Ngoi: ";
    cin >> SoChoNgoi;

    cout << "Nhap dung tich: ";
    cin >> DungTich;
}

void OTO::XUAT()
{
    VEHICLE::XUAT();
    cout << "So cho ngoi: " << SoChoNgoi << endl;
    cout << "Dung Tich: " << DungTich << endl;
}

class MOTO : public VEHICLE
{
    char Phankhoi[10];

    public:
        void NHAP();
        void XUAT();
};

void MOTO::NHAP()
{
    VEHICLE::NHAP();

    cout << "Nhap phan khoi: ";
    fflush(stdin);
    cin.getline(Phankhoi, 10);
}

void MOTO::XUAT()
{
    VEHICLE::XUAT();
    cout << "Phan khoi: " << Phankhoi << endl;
}

void SuaDungTich(OTO &obj1)
{
    obj1.DungTich = 3.0;
}

int main()
{
    OTO lamborgini;
    MOTO kawasaki;

    cout << "NHAP THONG TIN OTO" << endl;
    lamborgini.NHAP();

    cout << "NHAP THONG TIN MOTO" << endl;
    kawasaki.NHAP();

    cout << "THONG TIN OTO" << endl;
    lamborgini.XUAT();

    cout << "THONG TIN MOTO" << endl;
    kawasaki.XUAT();

    SuaDungTich(lamborgini);

    cout << "SAU KHI SAU THONG TIN" << endl;
    cout << "THONG TIN OTO" << endl;
    lamborgini.XUAT();
    return 0;
}