#include <bits/stdc++.h>
using namespace std;

class DOTPRINTER;
class LASERPRINTER;

class PRINTER
{
    protected:
        float Trongluong;
        char Hangsx[30];
        int Namsx;
        int Tocdo;
    
    public:
        friend void ChinhNamSX(DOTPRINTER &dt1, LASERPRINTER &ls1);
};

class DOTPRINTER : public PRINTER
{
    char Matdokim[30];

    public:
        void NHAP();
        void XUAT();
};

void DOTPRINTER::NHAP()
{
    cout << "Nhap trong luong: ";
    cin >> Trongluong;

    cout << "Nhap hang sx: ";
    fflush(stdin);
    cin.getline(Hangsx, 30);

    cout << "Nhap nam sx: ";
    cin >> Namsx;

    cout << "Nhap toc do: ";
    cin >> Tocdo;

    cout << "Nhap mat do kim: ";
    fflush(stdin);
    cin.getline(Matdokim, 30);
}

void DOTPRINTER::XUAT()
{
    cout << setw(10) << Trongluong
         << setw(30) << Hangsx
         << setw(10) << Namsx
         << setw(10) << Tocdo
         << setw(30) << Matdokim
         << endl;
}

class LASERPRINTER : public PRINTER
{
    char Dophangiai[30];

    public:
        void NHAP();
        void XUAT();
};

void LASERPRINTER::NHAP()
{
    cout << "Nhap trong luong: ";
    cin >> Trongluong;

    cout << "Nhap hang sx: ";
    fflush(stdin);
    cin.getline(Hangsx, 30);

    cout << "Nhap nam sx: ";
    cin >> Namsx;

    cout << "Nhap toc do: ";
    cin >> Tocdo;

    cout << "Nhap do phan giai: ";
    fflush(stdin);
    cin.getline(Dophangiai, 30);
}

void LASERPRINTER::XUAT()
{
    cout << setw(10) << Trongluong
         << setw(30) << Hangsx
         << setw(10) << Namsx
         << setw(10) << Tocdo
         << setw(30) << Dophangiai
         << endl;
}

void ChinhNamSX(DOTPRINTER &dt1, LASERPRINTER &ls1)
{
    dt1.Namsx = 2020;
    ls1.Namsx = 2020;
}

int main()
{
    LASERPRINTER ls1;
    DOTPRINTER dt1;

    cout << "NHAP THONG TIN MAY LASER PRINTER: " << endl;
    ls1.NHAP();
    
    cout << "NHAP THONG TIN MAY DOT PRINTER: " << endl;
    dt1.NHAP();

    cout << "THONG TIN MAY LASER PRINTER: " << endl;
    cout << setw(10) << "TRONG LUONG" << setw(30) << "HANG SX" << setw(10) << "NAM SX" << setw(10) << "TOC DO" << setw(30) << "MAT DO KIM" << endl;
    ls1.XUAT();
    
    cout << "THONG TIN MAY DOT PRINTER: " << endl;
    cout << setw(10) << "TRONG LUONG" << setw(30) << "HANG SX" << setw(10) << "NAM SX" << setw(10) << "TOC DO" << setw(30) << "DO PHAN GIAI" << endl;
    dt1.XUAT();

    ChinhNamSX(dt1, ls1);

    cout << "SAU KHI THAY DOI THONG TIN" << endl;
    cout << "THONG TIN MAY LASER PRINTER: " << endl;
    cout << setw(10) << "TRONG LUONG" << setw(30) << "HANG SX" << setw(10) << "NAM SX" << setw(10) << "TOC DO" << setw(30) << "MAT DO KIM" << endl;
    ls1.XUAT();
    
    cout << "THONG TIN MAY DOT PRINTER: " << endl;
    cout << setw(10) << "TRONG LUONG" << setw(30) << "HANG SX" << setw(10) << "NAM SX" << setw(10) << "TOC DO" << setw(30) << "DO PHAN GIAI" << endl;
    dt1.XUAT();

    return 0;
}