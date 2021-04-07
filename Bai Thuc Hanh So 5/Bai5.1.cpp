#include <bits/stdc++.h>
using namespace std;

class PhanSo
{
    float TuSo, MauSo;

    public:
        PhanSo operator+ (PhanSo obj1);
        PhanSo operator- (PhanSo obj1);
        PhanSo operator* (PhanSo obj1);
        PhanSo operator/ (PhanSo obj1);
        friend istream &operator>>(istream &input, PhanSo &obj1);
        friend ostream &operator<<(ostream &output, PhanSo obj1);
        float operator-();//Toan tu tinh gia tri
};

PhanSo PhanSo::operator+ (PhanSo obj1)
{
    PhanSo ans;
    ans.TuSo = this->TuSo * obj1.MauSo + this->MauSo * obj1.TuSo;
    ans.MauSo = this->MauSo * obj1.MauSo;
    return ans;
}

PhanSo PhanSo::operator- (PhanSo obj1)
{
    PhanSo ans;
    ans.TuSo = this->TuSo * obj1.MauSo - this->MauSo * obj1.TuSo;
    ans.MauSo = this->MauSo * obj1.MauSo;
    return ans;
}

PhanSo PhanSo::operator* (PhanSo obj1)
{
    PhanSo ans;
    ans.TuSo = this->TuSo * obj1.TuSo;
    ans.MauSo = this->MauSo * obj1.MauSo;
    return ans;
}

PhanSo PhanSo::operator/ (PhanSo obj1)
{
    PhanSo ans;
    ans.TuSo = this->TuSo * obj1.MauSo;
    ans.MauSo = this->MauSo * obj1.TuSo;
    return ans;
}

istream &operator>>(istream &input, PhanSo &obj1)
{
    cout << "Nhap Phan So: ";
    input >> obj1.TuSo >> obj1.MauSo;
    return input;
}

ostream &operator<<(ostream &output, PhanSo obj1)
{
    output << obj1.TuSo << "/" << obj1.MauSo << endl;
    return output;
}

float PhanSo::operator-()
{
    return TuSo / MauSo;
}

int main()
{
    PhanSo a, b;
    cin >> a >> b;

    cout << a;
    cout << b;

    PhanSo c = a + b;
    PhanSo d = a - b;
    PhanSo e = a * b;
    PhanSo f = a / b;

    cout << "Tong 2 Phan So: " << c;
    cout << "Gia Tri Tong 2 Phan So: "  << -c << endl;

    cout << "Hieu 2 Phan So: " << d;
    cout << "Gia Tri Hieu 2 Phan So: " << -d << endl;

    cout << "Nhan 2 Phan So: " << e;
    cout << "Gia Tri Nhan 2 Phan So: " << -e << endl;

    cout << "Chia 2 Phan So: " << f;
    cout << "Gia Tri Chia 2 Phan So: " << -f << endl;

    ofstream outfile("5.1.txt", ios::app);

    outfile << "Tong 2 Phan So: " << c;
    outfile << "Gia Tri Tong 2 Phan So: " << -c << endl;

    outfile << "Hieu 2 Phan So: " << d;
    outfile << "Gia Tri Hieu 2 Phan So: " << -d << endl;

    outfile << "Nhan 2 Phan So: " << e;
    outfile << "Gia Tri Nhan 2 Phan So: " << -e << endl;

    outfile << "Chia 2 Phan So: " << f;
    outfile << "Gia Tri Chia 2 Phan So: " << -f << endl;

    outfile.close();

    return 0;
}