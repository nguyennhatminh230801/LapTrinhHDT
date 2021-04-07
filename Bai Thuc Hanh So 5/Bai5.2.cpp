#include <bits/stdc++.h>
using namespace std;

class Complex
{
    float a, b;

    public:
        Complex();
        Complex(float a, float b);
        friend ostream &operator<<(ostream &output, Complex obj1);
        Complex operator+ (Complex obj1);
        Complex operator- (Complex obj1);
};

Complex::Complex()
{
    a = b = 0;
}

Complex::Complex(float a, float b)
{
    this->a = a;
    this->b = b;
}

ostream &operator<<(ostream &output, Complex obj1)
{
    output << obj1.a << "+" << obj1.b << "i";
    return output;
}

Complex Complex::operator+(Complex obj1)
{
    Complex ans;
    ans.a = a + obj1.a;
    ans.b = b + obj1.b;
    return ans;
}

Complex Complex::operator-(Complex obj1)
{
    Complex ans;
    ans.a = a - obj1.a;
    ans.b = b - obj1.b;
    return ans;
}

int main()
{
    Complex a(8.5, 9.5);
    Complex b(10.5, 11.5);

    Complex c = a + b;
    Complex d = a - b;

    cout << "So Phuc a: " << a << endl;
    cout << "So Phuc b: " << b << endl;
    cout << "So Phuc c: " << c << endl;
    cout << "So Phuc d: " << d << endl;
     
    return 0;
}