#include <bits/stdc++.h>
using namespace std;

class HCN
{
    float D;
    float R;

    public:
        void NHAP();
        void VE();
        float DIENTICH();
        float CHUVI();
};

void HCN::NHAP()
{
    cout << "Nhap chieu dai: ";
    cin >> D;
    cout << "Nhap chieu rong: ";
    cin >> R;
}

void HCN::VE()
{
    for(int i = 1 ; i <= R ; i++)
    {
        for(int j = 1 ; j <= D ; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

float HCN::DIENTICH()
{
    return D * R;
}

float HCN::CHUVI()
{
    return (D + R) * 2;
}

int main()
{
    HCN X;

    X.NHAP();
    cout << "Hinh Chu Nhat Co Dang: " << endl;
    X.VE();
    cout << "Dien tich: " << X.DIENTICH() << endl;
    cout << "Chu vi: " << X.CHUVI() << endl;
    return 0;
}