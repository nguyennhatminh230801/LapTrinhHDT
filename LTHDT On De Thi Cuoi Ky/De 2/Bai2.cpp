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
    long long value1 = gio * 60 * 60 + phut * 60 + giay;
    long long value2 = obj1.gio * 60 * 60 + obj1.phut * 60 + obj1.giay;

    long long value3 = value1 - value2;
    value3 = abs(value3);

    THOIGIAN ans;
    ans.gio = value3 / 3600;
    value3 %= 3600;

    ans.phut = value3 / 60;
    value3 %= 60;

    ans.giay = value3;

    return ans;
}

istream &operator>> (istream &input, THOIGIAN &obj1)
{   
    do
    {
        cout << "Nhap Gio: ";
        input >> obj1.gio;

        if(obj1.gio < 0 || obj1.gio > 23)
        {
            cout << "Nhap Sai! Vui Long Nhap Lai" << endl;
        }

    } while (obj1.gio < 0 || obj1.gio > 23);
    
    do
    {
        cout << "Nhap Phut: ";
        input >> obj1.phut;

        if(obj1.phut < 0 || obj1.phut > 59)
        {
            cout << "Nhap Sai! Vui Long Nhap Lai" << endl;
        }
    } while (obj1.phut < 0 || obj1.phut > 59);
    
    do
    {
        cout << "Nhap Giay: ";
        input >> obj1.giay;

        if(obj1.giay < 0 || obj1.giay > 59)
        {
            cout << "Nhap Sai! Vui Long Nhap Lai" << endl;
        }
    } while (obj1.giay < 0 || obj1.giay > 59);
    
    return input;
}

ostream &operator<< (ostream &output, THOIGIAN obj1)
{
    output << obj1.gio << ":" << obj1.phut << ":" << obj1.giay << endl;
    return output;
}

int main()
{
    THOIGIAN tg1(7, 50, 11), tg2;
    
    cout << "Nhap Thoi Gian 2: " << endl;
    cin >> tg2;

    THOIGIAN tg3 = tg2 - tg1;

    cout << "Ket Qua Hieu Thoi Gian La: " << tg3 << endl;
    return 0;
}