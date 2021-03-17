#include <bits/stdc++.h>
using namespace std;

class ARRAY
{
    int *VALUE;
    int n;

    public:
        ARRAY();
        ARRAY(int n);
        ~ARRAY();
        void NHAP();
        void XUAT();
};

ARRAY::ARRAY()
{
    n = 0;
    VALUE = NULL;
}

ARRAY::ARRAY(int n)
{
    this->n = n;
    VALUE = new int[n];

    for(int i = 0 ; i < n ; i++)
    {
        VALUE[i] = 0;
    }
}

ARRAY::~ARRAY()
{
    delete VALUE;
    n = 0;
}

void ARRAY::NHAP()
{
    if(n == 0)
    {
        cout << "Nhap so luong phan tu: ";
        cin >> n;    
    }
    
    if(VALUE == NULL)
    {
        VALUE = new int[n];
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> VALUE[i];
    }
}

void ARRAY::XUAT()
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << VALUE[i] << " ";
    }
    cout << endl;
}

int main()
{
    ARRAY arr(8);

    cout << "Mang vua khoi tao: ";
    arr.XUAT();

    cout << "Nhap mang: " << endl;
    arr.NHAP();

    cout << "Mang sau khi nhap: ";
    arr.XUAT();
    return 0;
}