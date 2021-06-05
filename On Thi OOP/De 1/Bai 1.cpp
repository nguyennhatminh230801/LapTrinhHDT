#include <bits/stdc++.h>
using namespace std;

//Cau A
class PERSON
{
    protected:
        char Hoten[50];
        int Ngay;
        int Thang;
        int Nam;
        char Quequan[100];
};

//Cau B
class VANDONGVIEN : public PERSON //Ke thua
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
        friend void InDanhSachCauThuTvaT(CAUTHU *array1, int n);
        friend void DuaRaThongTinNguoiCoThuNhapCaoNhat(CAUTHU *array1, int n);
};

void CAUTHU::NHAP()
{
    cout << "Nhap Ho Ten Cau Thu: ";
    fflush(stdin);
    gets(Hoten);

    cout << "Nhap Ngay Sinh Cua Cau Thu: ";
    cin >> Ngay;

    cout << "Nhap Thang Sinh Cua Cau Thu: ";
    cin >> Thang;
    
    cout << "Nhap Ngay Sinh Cua Cau Thu: ";
    cin >> Nam;

    cout << "Nhap Que Quan Cua Cau Thu: ";
    fflush(stdin);
    gets(Quequan);

    cout << "Nhap Bo Mon Cua Cau Thu: ";
    fflush(stdin);
    gets(BoMon);

    cout << "Nhap Thu Nhap Cua Cau Thu: ";
    cin >> ThuNhap;

    cout << "Nhap CLB Cua Cau Thu: ";
    fflush(stdin);
    gets(CLB);

    cout << "Nhap Vi Tri Cua Cau Thu: ";
    fflush(stdin);
    gets(ViTri);
}

void CAUTHU::XUAT()
{
    cout << "Ho Ten: " << Hoten << endl;
    cout << "Ngay Sinh: " << Ngay << "/" << Thang << "/" << Nam << endl;
    cout << "Que Quan: " << Quequan << endl;
    cout << "Bo Mon: " << BoMon << endl;
    cout << "Thu Nhap: " << ThuNhap << endl;
    cout << "CLB: " << CLB << endl;
    cout << "Vi Tri: " << ViTri << endl;
}

void InDanhSachCauThuTvaT(CAUTHU *array1, int n)
{
    cout << "Danh Sach Cau Thu CLB T&T: " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        if(stricmp(array1[i].CLB, "T&T") == 0)//Ham So Sanh Chuoi = 0 giong nhau, 1 Chuoi Dau > Chuoi Sau, -1 Chuoi Dau < Chuoi Sau
        {
            array1[i].XUAT();
        }
    }
}

void DuaRaThongTinNguoiCoThuNhapCaoNhat(CAUTHU *array1, int n)
{
    float ThuNhapCaoNhat = array1[0].ThuNhap;
    
    for(int i = 1 ; i < n ; i++)
    {
        if(array1[i].ThuNhap > ThuNhapCaoNhat)
        {
            ThuNhapCaoNhat = array1[i].ThuNhap;
        }
    }

    cout << "Thong Tin Nhung Nguoi Co Thu Nhap Cao Nhat:" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        if(array1[i].ThuNhap == ThuNhapCaoNhat)
        {
            array1[i].XUAT();
        }
    }
}

int main()
{
    CAUTHU *array1;
    int n;

    do
    {
        cout << "Nhap So Luong Cau Thu: ";
        cin >> n;

        if(n <= 0 || n >= 50)
        {
            cout << "Yeu Cau Nhap Lai" << endl;
        }
    } while(n <= 0 || n >= 50);
    
    array1 = new CAUTHU[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap Cau Thu Thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }

    InDanhSachCauThuTvaT(array1, n);
    DuaRaThongTinNguoiCoThuNhapCaoNhat(array1, n);
    return 0;
}