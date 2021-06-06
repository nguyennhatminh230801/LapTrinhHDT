#include <bits/stdc++.h>
using namespace std;

class NHANSU
{
    protected:
        char HoTen[50];
        char GioiTinh[5];
        int NgaySinh, ThangSinh, NamSinh;
        char DiaChi[100];
};

class CONGCHUC : public NHANSU
{
    char NganhNghe[20];
    int NamVaoCQ;
    char TrinhDo[50];
    float HSLuong;
    float PhuCap;

    public:
        void NHAP();
        void XUAT();
        float THUNHAP();
        friend void SapXepTen(CONGCHUC *array1, int n);
};

void CONGCHUC::NHAP()
{
    cout << "Nhap Ho Ten: ";
    fflush(stdin);
    gets(HoTen);

    cout << "Nhap Gioi Tinh: ";
    fflush(stdin);
    gets(GioiTinh);

    cout << "Nhap Ngay Sinh: ";
    cin >> NgaySinh;

    cout << "Nhap Thang Sinh: ";
    cin >> ThangSinh;

    cout << "Nhap Nam Sinh: ";
    cin >> NamSinh;

    cout << "Nhap Dia Chi: ";
    fflush(stdin);
    gets(DiaChi);

    cout << "Nhap Nganh Nghe: ";
    fflush(stdin);
    gets(NganhNghe);

    cout << "Nhap Nam Vao Co Quan: ";
    cin >> NamVaoCQ;

    cout << "Nhap Trinh Do: ";
    fflush(stdin);
    gets(TrinhDo);

    cout << "Nhap He So Luong: ";
    cin >> HSLuong;

    cout << "Nhap Phu Cap: ";
    cin >> PhuCap;
}

void CONGCHUC::XUAT()
{
    cout << "Ho Ten: " << HoTen << endl;
    cout << "Gioi Tinh: " << GioiTinh << endl;
    cout << "Ngay Sinh : " << NgaySinh << "/" << ThangSinh << "/" << NamSinh << endl;
    cout << "Dia Chi: " << DiaChi << endl;
    cout << "Nganh Nghe: " << NganhNghe << endl;
    cout << "Nam Vao Co Quan: " << NamVaoCQ << endl;
    cout << "Trinh Do: " << TrinhDo << endl;
    cout << "He So Luong: " << HSLuong << endl;
    cout << "Phu Cap: " << PhuCap << endl;
}

float CONGCHUC::THUNHAP()
{
    return HSLuong * 830 + PhuCap;
}

void DuaRaThongTinCongChucCoThuNhapThapNhat(CONGCHUC *array1, int n)
{
    float ThuNhapThapNhat = array1[0].THUNHAP();

    for(int i = 1 ; i < n ; i++)
    {
        if(array1[i].THUNHAP() < ThuNhapThapNhat)
        {
            ThuNhapThapNhat = array1[i].THUNHAP();
        }
    }

    cout << "Nhung Nguoi Co Thu Nhap Thap Nhat: " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        if(array1[i].THUNHAP() == ThuNhapThapNhat)
        {
            array1[i].XUAT();
        }
    }
}

void SapXepTen(CONGCHUC *array1, int n)
{
    CONGCHUC temp;

    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(stricmp(array1[j].HoTen, array1[j + 1].HoTen) == -1)
            {
                temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;
            }
        }
    }
}

int main()
{   
    CONGCHUC *array1;
    int n;

    do
    {
        cout << "Nhap So Cong Chuc: ";
        cin >> n;

        if(n < 0 || n > 50)
        {
            cout << "Yeu Cau Nhap Lai!!!!" << endl;
        }
    } while (n < 0 || n > 50);
    
    array1 = new CONGCHUC[n];


    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap Cong Chuc Thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }

    DuaRaThongTinCongChucCoThuNhapThapNhat(array1, n);

    cout << "Truoc Khi Sap Xep: " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Cong Chuc Thu " << i + 1 << ": " << endl;
        array1[i].XUAT();
    }

    SapXepTen(array1, n);

    cout << "Sau Khi Sap Xep: " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Cong Chuc Thu " << i + 1 << ": " << endl;
        array1[i].XUAT();
    }
    return 0;
}