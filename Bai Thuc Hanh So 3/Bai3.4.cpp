#include <bits/stdc++.h>
using namespace std;

class PTB2
{
    float a, b, c;

    public:
        PTB2();
        PTB2(float a, float b, float c);
        void NHAP();
        void XUAT();
        void GIAI();
};

PTB2::PTB2()
{
    a = 0;
    b = 0;
    c = 0;
}

PTB2::PTB2(float a, float b, float c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void PTB2::NHAP()
{
    cout << "Nhap a: ";
    cin >> a;

    cout << "Nhap b: ";
    cin >> b;
    
    cout << "Nhap c: ";
    cin >> c;
}

void PTB2::XUAT()
{
    cout << a << "x^2 + " << b << "x + " << c << "= 0" << endl;
}

void PTB2::GIAI()
{
    if(a == 0)
    {
        if(b == 0)
        {
            if(c == 0)
            {
                cout << "Phuong trinh vo so nghiem" << endl;
            }
            else{
                cout << "Phuong trinh vo nghiem" << endl;
            }
        }
        else{
            cout << "Phuong trinh co 1 nghiem " << -c / b << endl;
        }
    }
    else{
        float delta = b * b - 4 * a * c;

        if(delta < 0)
        {
            cout << "Phuong trinh vo nghiem" << endl;
        }
        else if (delta == 0)
        {
            cout << "Phuong trinh co 1 nghiem " << -b / (2 * a) << endl;
        }
        else{
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }
}

int main()
{
    PTB2 P(2, 4, 2);

    cout << "Phuong trinh P: ";
    P.XUAT();
    cout << "Giai phuong trinh P: ";
    P.GIAI();

    PTB2 Q;
    cout << "Nhap gia tri phuong trinh P: " << endl;
    Q.NHAP();
    
    cout << "Phuong trinh Q: ";
    Q.XUAT();
    
    cout << "Giai phuong trinh Q: ";
    Q.GIAI();
    return 0;
}