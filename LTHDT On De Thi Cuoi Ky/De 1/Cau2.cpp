#include <bits/stdc++.h>
using namespace std;

class DIEM
{
    float x, y, z;

    public:
        DIEM();
        DIEM(float x, float y, float z);
        DIEM operator+ (DIEM obj1);
        friend istream &operator>>(istream &input, DIEM &obj1);
        friend ostream &operator<<(ostream &output, DIEM obj1);
};

DIEM::DIEM()
{
    x = y = z = 0;
}

DIEM::DIEM(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

DIEM DIEM::operator+(DIEM obj1)
{
    x += obj1.x;
    y += obj1.y;
    z += obj1.z;

    return *this;
}

istream &operator>>(istream &input, DIEM &obj1)
{
    cout << "Nhap Toa Do X: ";
    input >> obj1.x;
    cout << "Nhap Toa Do Y: ";
    input >> obj1.y;
    cout << "Nhap Toa Do Z: ";
    input >> obj1.z;

    return input;
}

ostream &operator<<(ostream &output, DIEM obj1)
{
    output << "Toa Do: (" << obj1.x << "," << obj1.y << "," << obj1.z << ")" << endl;

    return output; 
}

int main()
{
    DIEM A, B;
    cin >> A >> B;

    DIEM C = A + B;

    cout << C;
    return 0;
}