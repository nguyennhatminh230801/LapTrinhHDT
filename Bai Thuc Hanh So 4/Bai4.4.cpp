#include <bits/stdc++.h>
using namespace std;

class ELECTRONIC
{
    protected:
        float Congsuat;
        float Dienap;
    
    public:
        ELECTRONIC(float Congsuat, float Dienap);
};

ELECTRONIC::ELECTRONIC(float Congsuat, float Dienap)
{
    this->Congsuat = Congsuat;
    this->Dienap = Dienap;
}

class MAYGIAT : public ELECTRONIC
{
    float Dungtich;
    char Loai[20];
    
    public:
        MAYGIAT(float Dungtich, char Loai[], float Congsuat, float Dienap);
        void XUAT();
};

MAYGIAT::MAYGIAT(float Dungtich, char Loai[], float Congsuat, float Dienap) : ELECTRONIC(Congsuat, Dienap)
{
    this->Dungtich = Dungtich;
    strcpy(this->Loai, Loai);
}

void MAYGIAT::XUAT()
{
    cout << setw(10) << Dungtich
         << setw(20) << Loai
         << setw(10) << Congsuat
         << setw(10) << Dienap
         << endl;
}

class TULANH : public ELECTRONIC
{
    float Dungtich;
    int SoNgan;

    public:
        TULANH(float Dungtich, int SoNgan, float Congsuat, float Dienap);
        void XUAT();
};

TULANH::TULANH(float Dungtich, int SoNgan, float Congsuat, float Dienap) : ELECTRONIC(Congsuat, Dienap)
{
    this->Dungtich = Dungtich;
    this->SoNgan = SoNgan;
}

void TULANH::XUAT()
{
    cout << setw(10) << Dungtich
         << setw(10) << SoNgan
         << setw(10) << Congsuat
         << setw(10) << Dienap
         << endl;
}

int main()
{
    MAYGIAT mg1(25, "Chat luong cao", 250, 125);
    TULANH tl1(25, 5, 300, 120);

    cout << "THONG TIN MAY GIAT" << endl;
    cout << setw(10) << "DUNG TICH" << setw(20) << "LOAI" << setw(10) << "CONG SUAT" << setw(10) << "DIEN AP" << endl;
    mg1.XUAT();

    cout << "THONG TIN TU LANH" << endl;
    cout << setw(10) << "DUNG TICH" << setw(10) << "SO NGAN" << setw(10) << "CONG SUAT" << setw(10) << "DIEN AP" << endl;
    tl1.XUAT();
    
    return 0;
}