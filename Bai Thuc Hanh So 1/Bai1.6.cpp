#include <bits/stdc++.h>
using namespace std;

class ARRAY
{
    float *array1;
    int n;

    public:
        void NHAP();
        void XUAT();
        float FINDMIN();
        float FINDMAX();
};

void ARRAY::NHAP()
{
    cout << "Nhap N: ";
    cin >> n;
    
    array1 = new float[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> array1[i];
    }
}

void ARRAY::XUAT()
{
    cout << "Day So: ";
    
    for(int i = 0 ; i < n ; i++)
    {
        cout << array1[i] << " ";
    }

    cout << endl;
}

float ARRAY::FINDMIN()
{
    float answer = array1[0];

    for(int i = 1 ; i < n ; i++)
    {
        if(answer > array1[i])
        {
            answer = array1[i];
        }
    }

    return answer;
}

float ARRAY::FINDMAX()
{
    float answer = array1[0];
    
    for(int i = 1 ; i < n ; i++)
    {
        if(answer < array1[i])
        {
            answer = array1[i];
        }
    }

    return answer;
}

int main()
{
    ARRAY a;

    a.NHAP();
    a.XUAT();

    cout << "Gia Tri Nho Nhat: " <<  a.FINDMIN() << endl;
    cout << "Gia tri lon nhat: " << a.FINDMAX() << endl;
    return 0;
}