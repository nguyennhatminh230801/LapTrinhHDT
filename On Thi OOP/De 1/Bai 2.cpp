#include <bits/stdc++.h>
using namespace std;

class DIEM
{
    int x, y, z;

    public:
        DIEM();
        DIEM(int x, int y, int z);
        //~DIEM();
        DIEM operator+ (DIEM obj1);
        friend istream &operator>> (istream &input, DIEM &obj1);
        friend ostream &operator<< (ostream &output, DIEM obj1);

};

DIEM::DIEM()
{
    x = y = z = 0;
}

DIEM::DIEM(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

// DIEM::~DIEM()
// {
//     x = y = z = 0;

//     //delete[] mang;
//     //n = 0;
//     //chuoi = "";
// }

DIEM DIEM::operator+(DIEM obj1)
{
    DIEM ans;

    ans.x = x + obj1.x;
    ans.y = y + obj1.y;
    ans.z = z + obj1.z;

    return ans;
}

istream &operator>> (istream &input, DIEM &obj1)
{   
    cout << "Nhap Toa Do X: ";
    input >> obj1.x;
    cout << "Nhap Toa Do Y: ";
    input >> obj1.y;
    cout << "Nhap Toa Do Z: ";
    input >> obj1.z;

    return input;
}

ostream &operator<< (ostream &output, DIEM obj1)
{
    output << "Toa Do Diem : (" << obj1.x << "," << obj1.y << "," << obj1.z << ")" << endl;
    return output;
}

int main()
{
    DIEM A, B;
    cout << "Nhap Diem A:" << endl;
    cin >> A;
    cout << "Nhap Diem B:" << endl;
    cin >> B;

    DIEM C = A + B;
    
    cout << C;
    
    return 0;
}