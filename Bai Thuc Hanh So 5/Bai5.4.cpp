#include <bits/stdc++.h>
using namespace std;

class MaTrix
{
    int n, m;
    double **mat1;

    public:
        friend istream &operator>> (istream &input, MaTrix &obj1);
        friend ostream &operator<< (ostream &output, MaTrix obj1);
        MaTrix operator- ();// Doi dau ma tran
        MaTrix operator+ (MaTrix obj1);
        MaTrix operator- (MaTrix obj1);
};

istream &operator>> (istream &input, MaTrix &obj1)
{
    cout << "Nhap N: ";
    input >> obj1.n;

    cout << "Nhap M: ";
    input >> obj1.m;

    obj1.mat1 = new double*[obj1.n];

    for(int i = 0 ; i < obj1.n ; i++)
    {
        obj1.mat1[i] = new double[obj1.m];
    }

    for(int i = 0 ; i < obj1.n ; i++)
    {
        for(int j = 0 ; j < obj1.m ; j++)
        {
            input >> obj1.mat1[i][j];
        }
    }

    return input;
}

ostream &operator<< (ostream &output, MaTrix obj1)
{
    for(int i = 0 ; i < obj1.n ; i++)
    {
        for(int j = 0 ; j < obj1.m ; j++)
        {
            output << obj1.mat1[i][j] << " ";
        }
        output << endl;
    }

    return output;
}

MaTrix MaTrix::operator- ()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
             mat1[i][j] = -mat1[i][j];
        }
    }

    return *this;
}

MaTrix MaTrix::operator- (MaTrix obj1)
{
    MaTrix ans;
    
    if(m == obj1.m && n == obj1.n)
    {
        ans.m = m;
        ans.n = n;

        ans.mat1 = new double*[ans.n];

        for(int i = 0 ; i < ans.n ; i++)
        {
            ans.mat1[i] = new double[ans.m];
        }

        for(int i = 0 ; i < ans.n ; i++)
        {
            for(int j = 0 ; j < ans.m ; j++)
            {
                ans.mat1[i][j] = mat1[i][j] - obj1.mat1[i][j];
            }
        }
    }
    else
    {
        cout << "2 ma tran khong cung kich thuoc" << endl;
        ans.n = ans.m = 0;
        ans.mat1 = NULL;
    }

    return ans;
}

MaTrix MaTrix::operator+ (MaTrix obj1)
{
    MaTrix ans;
    
    if(m == obj1.m && n == obj1.n)
    {
        ans.m = m;
        ans.n = n;

        ans.mat1 = new double*[ans.n];

        for(int i = 0 ; i < ans.n ; i++)
        {
            ans.mat1[i] = new double[ans.m];
        }

        for(int i = 0 ; i < ans.n ; i++)
        {
            for(int j = 0 ; j < ans.m ; j++)
            {
                ans.mat1[i][j] = mat1[i][j] + obj1.mat1[i][j];
            }
        }
    }
    else
    {
        cout << "2 ma tran khong cung kich thuoc" << endl;
        ans.n = ans.m = 0;
        ans.mat1 = NULL;
    }

    return ans;
}

int main()
{
    MaTrix P, Q;

    cout << "Nhap Ma Tran P: " << endl;
    cin >> P;

    cout << "Nhap Ma Tran Q: " << endl;
    cin >> Q;

    P = -P;
    Q = -Q;

    cout << "Ma Tran P sau khi doi dau: " << endl;
    cout << P;

    cout << "Ma Tran Q sau khi doi dau: " << endl;
    cout << Q;

    MaTrix M = P + Q;
    MaTrix N = P - Q;

    cout << "Ma Tran Tong: " << endl;
    cout << M;

    cout << "Ma Tran Hieu: " << endl;
    cout << N;

    return 0;
}