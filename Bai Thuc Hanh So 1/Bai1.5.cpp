#include <bits/stdc++.h>
using namespace std;

class ARRAY
{
    int *array1;
    int n;

    public:
        void NHAP();
        void XUAT();
        void SAPXEP();
};

void ARRAY::NHAP()
{
    cout << "Nhap N:";
    cin >> n;

    array1 = new int[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap Phan Tu thu " << i + 1 << ": ";
        cin >> array1[i];
    }
}

void ARRAY::XUAT()
{
    cout << "Day so: ";
    for(int i = 0 ; i < n ; i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;
}

void ARRAY::SAPXEP()
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(array1[j] > array1[j + 1])
            {
                int change = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = change;
            }
        }
    }
}

int main()
{
    ARRAY arr;

    arr.NHAP();
    arr.XUAT();

    cout << "DAY SO SAU KHI SAP XEP" << endl;
    arr.SAPXEP();
    arr.XUAT();
    return 0;
}