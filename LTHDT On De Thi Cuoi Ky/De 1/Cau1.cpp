#include <bits/stdc++.h>
using namespace std;

class PERSON
{
    protected:
        char HoTen[50];
        int NgaySinh;
        int ThangSinh;
        int NamSinh;
        char QueQuan[100];
};

class VANDONGVIEN : public PERSON
{
    protected:
        char BoMon[30];
        float ThuNhap;  
};

class CAUTHU : public VANDONGVIEN
{
    char CLB[100];
    char ViTri[100];

    public:
        void NHAP();
        void XUAT();
        friend void Bonus1(CAUTHU *array1, int n);
        friend void Bonus2(CAUTHU *array1, int n);
};

void CAUTHU::NHAP()
{
    cout << "Nhap Ho Ten Cua Cau Thu: ";
    fflush(stdin);
    gets(HoTen);

    cout << "Nhap Ngay Sinh Cua Cau Thu: ";
    cin >> NgaySinh;

    cout << "Nhap Thang Sinh Cua Cau Thu: ";
    cin >> ThangSinh;

    cout << "Nhap Nam Sinh Cua Cau Thu: ";
    cin >> NamSinh;

    cout << "Nhap Que Quan Cau Thu : ";
    fflush(stdin);
    gets(QueQuan);

    cout << "Nhap Bo Mon Cua Cau Thu: ";
    fflush(stdin);
    gets(BoMon);

    cout << "Nhap Thu Nhap Cua Cau Thu:";
    cin >> ThuNhap;

    cout << "Nhap CLB cua cau thu: ";
    fflush(stdin);
    gets(CLB);

    cout << "Nhap Vi Tri Cua Cau Thu: ";
    fflush(stdin);
    gets(ViTri);
}

void CAUTHU::XUAT()
{
    cout << "Ho Ten: " << HoTen << endl;
    cout << "Ngay Sinh: " << NgaySinh << "/" << ThangSinh << "/" << NamSinh << endl;
    cout << "Que Quan: " << QueQuan << endl;
    cout << "Bo Mon: " << BoMon << endl;
    cout << "Thu Nhap: " << ThuNhap << endl;
    cout << "CLB: " << CLB << endl;
    cout << "Vi Tri: " << ViTri << endl;
}

//In ra danh sách cầu thủ CLB T&T
void Bonus1(CAUTHU *array1, int n)
{
    cout << "Danh Sach Cac Cau Thu Thuoc CLB T&T: " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        if(stricmp(array1[i].CLB, "T&T") == 0)
        {
            array1[i].XUAT();
        }
    }
}

//Dua Ra Thong Tin Nguoi Co Thu Nhap Cao Nhat
void Bonus2(CAUTHU *array1, int n)
{
    float max1 = array1[0].ThuNhap;
    int pos = 0;

    for(int i = 1 ; i < n ; i++)
    {
        if(array1[i].ThuNhap > max1)
        {
            max1 = array1[i].ThuNhap;
            pos = i;
        }
    }

    cout << "Thong Tin Nguoi Co Thu Nhap Cao Nhat: " << endl;
    array1[pos].XUAT();
}

int main()
{
    CAUTHU *array1;
    int n;

    cout << "Nhap So Luong Cau Thu: ";
    cin >> n;

    array1 = new CAUTHU[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap Thong Tin Cau Thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }

    Bonus1(array1, n);
    Bonus2(array1, n);
    return 0;
}