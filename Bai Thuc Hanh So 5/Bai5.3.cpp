#include <bits/stdc++.h>
using namespace std;

class PTB2
{
    float a, b, c;

    public:
        PTB2();
        PTB2(float a, float b, float c);
        friend ostream &operator<< (ostream &output, PTB2 obj1);
        PTB2 operator- ();//Doi dau;
        PTB2 operator+ (PTB2 obj1);
        PTB2 operator- (PTB2 obj1);
};

PTB2::PTB2()
{
    a = b = c = 0;
}

PTB2::PTB2(float a, float b, float c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

ostream &operator<< (ostream &output, PTB2 obj1)
{
    output << obj1.a << "x^2 + " << obj1.b << "x + " << obj1.c; 
    return output;
}

PTB2 PTB2::operator- ()
{
    PTB2 ans;
    ans.a = -a;
    ans.b = -b;
    ans.c = -c;
    return ans;
}

PTB2 PTB2::operator+ (PTB2 obj1)
{
    PTB2 ans;
    ans.a = a + obj1.a;
    ans.b = b + obj1.b;
    ans.c = c + obj1.c;
    return ans;
}

PTB2 PTB2::operator- (PTB2 obj1)
{
    PTB2 ans;
    ans.a = a - obj1.a;
    ans.b = b - obj1.b;
    ans.c = c - obj1.c;
    return ans;
}

int main()
{
    PTB2 a(2, 4, 2), b(3, 2, 1);
    a = -a;
    b = -b;

    PTB2 c = a + b;
    PTB2 d = a - b;

    cout << "Tam Thuc A: " << a << endl;
    cout << "Tam Thuc B: " << b << endl;

    cout << "Tong 2 tam thuc: " << c << endl;
    cout << "Hieu 2 tam thuc: " << d << endl;
    return 0;
}