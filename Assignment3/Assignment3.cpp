#include <bits/stdc++.h>
using namespace std;

class PhanSo
{
    float TuSo, MauSo;

    public:
        PhanSo();
        PhanSo(float TuSo, float MauSo);
        PhanSo operator* (PhanSo obj1);
        float operator! (); //Tra Ve Gia Tri 2 Phan So
        friend istream &operator>>(istream &input, PhanSo &obj1);
        friend ostream &operator<<(ostream &output, PhanSo obj1);
};

PhanSo::PhanSo()
{
    TuSo = 0;
    MauSo = 0;
}

PhanSo::PhanSo(float TuSo, float MauSo)
{
    this->TuSo = TuSo;
    this->MauSo = MauSo;
}

PhanSo PhanSo::operator*(PhanSo obj1)
{
    PhanSo ans;
    ans.TuSo = TuSo * obj1.TuSo;
    ans.MauSo = MauSo * obj1.MauSo;
    return ans;
}

float PhanSo::operator!()
{
    return (float) TuSo / MauSo;
}

istream &operator>>(istream &input, PhanSo &obj1)
{
    cout << "Nhap Tu So: ";
    input >> obj1.TuSo;
    cout << "Nhap Mau So: ";
    input >> obj1.MauSo;
    return input;
}

ostream &operator<<(ostream &output, PhanSo obj1)
{
    output << obj1.TuSo << "/" << obj1.MauSo;
    return output;
}

int main()
{
    PhanSo PS1, PS2;

    cout << "Nhap Phan So Thu Nhat: " << endl;
    cin >> PS1;

    cout << "Nhap Phan So Thu Hai: " << endl;
    cin >> PS2;

    PhanSo PS3 = PS1 * PS2;

    ofstream outfile("PHANSO.txt", ios::out);

    outfile << "Tich 2 Phan So La : " << PS3 << endl;
    outfile << "Ket qua Tich 2 Phan So: " << !PS3 << endl;
    
    outfile.close();
    return 0;
}