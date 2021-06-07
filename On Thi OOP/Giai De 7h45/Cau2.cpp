#include <bits/stdc++.h>
using namespace std;

class NHITHUC
{
    int a, b;

    public:
        NHITHUC();
        NHITHUC(int a, int b);
        ~NHITHUC();
        NHITHUC operator-(); //Toan Tu Doi Dau
        friend istream &operator>>(istream &input, NHITHUC &obj1);
        friend ostream &operator<<(ostream &output, NHITHUC obj1);
}; 

NHITHUC::NHITHUC()
{
    a = b = 0;
}

NHITHUC::NHITHUC(int a, int b)
{
    this->a = a;
    this->b = b;
}

NHITHUC::~NHITHUC()
{
    a = b = 0;
}

NHITHUC NHITHUC::operator-()
{
    a = -a;
    b = -b;

    return *this;
}

istream &operator>>(istream &input, NHITHUC &obj1)
{
    cout << "Nhap So A: ";
    input >> obj1.a;
    cout << "Nhap So B: ";
    input >> obj1.b;

    return input;
}

ostream &operator<<(ostream &output, NHITHUC obj1)
{
    output << obj1.a << "x+" << obj1.b << "=0" << endl;

    return output;
}

int main()
{
    NHITHUC nt1;
    cout << "Nhap Nhi Thuc: " << endl;
    cin >> nt1;

    nt1 = -nt1;

    cout << "Nhi Thuc: " << nt1 << endl;
    return 0;
}