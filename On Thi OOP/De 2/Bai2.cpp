#include <bits/stdc++.h>
using namespace std;

class THOIGIAN
{
    int gio, phut, giay;

    public:
        THOIGIAN();
        THOIGIAN(int gio, int phut, int giay);
        THOIGIAN operator- (THOIGIAN obj1);
        friend istream &operator>> (istream &input, THOIGIAN &obj1);
        friend ostream &operator<< (ostream &output, THOIGIAN obj1);

};

THOIGIAN::THOIGIAN()
{
    gio = phut = giay = 0;
}

THOIGIAN::THOIGIAN(int gio, int phut, int giay)
{
    this->gio = gio;
    this->phut = phut;
    this->giay = giay;
}

THOIGIAN THOIGIAN::operator-(THOIGIAN obj1)
{
    THOIGIAN ans;

    int ThoiGian1 = gio * 3600 + phut * 60 + giay;
    int ThoiGian2 = obj1.gio * 3600 + obj1.phut * 60 + obj1.giay;

    int ThoiGian = abs(ThoiGian1 - ThoiGian2);

    ans.gio = ThoiGian / 3600;
    ThoiGian = ThoiGian % 3600;

    ans.phut = ThoiGian / 60;
    ThoiGian = ThoiGian % 60;

    ans.giay = ThoiGian;

    return ans;
}

istream &operator>> (istream &input, THOIGIAN &obj1)
{
    cout << "Nhap Gio: ";
    input >> obj1.gio;
    cout << "Nhap Phut: ";
    input >> obj1.phut;
    cout << "Nhap Giay: ";
    input >> obj1.giay;
    
    return input;
}

ostream &operator<< (ostream &output, THOIGIAN obj1)
{
    output << obj1.gio << ":" << obj1.phut << ":" << obj1.giay << endl;
    return output;
}

int main()
{
    THOIGIAN tg1, tg2;

    cout << "Nhap Thoi Gian Thu Nhat: ";
    cin >> tg1;

    cout << "Nhap Thoi Gian Thu Hai: ";
    cin >> tg2;

    THOIGIAN tg3 = tg1 - tg2;

    cout << "Hieu 2 thoi gian la : " << tg3 << endl;
    return 0;
}