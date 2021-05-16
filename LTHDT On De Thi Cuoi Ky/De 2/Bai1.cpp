#include <bits/stdc++.h>
using namespace std;

class NHANSU
{
    protected:
        char HoTen[50];
        char GioiTinh[5];
        int Ngay, Thang, Nam;
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
        friend void SapXepGiamDanTheoTen(CONGCHUC *array1, int n);
};

void CONGCHUC::NHAP()
{
    cout << "Nhap Ho Ten: ";
    fflush(stdin);
    gets(HoTen);

    cout << "Nhap Gioi Tinh: ";
    fflush(stdin);
    gets(GioiTinh);

    cout << "Nhap Ngay Thang Nam (Nhap Theo Thu Tu Ngay Thang Nam, co khoang cach): ";
    cin >> Ngay >> Thang >> Nam;

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

    cout << "Nhap Phu Cap : ";
    cin >> PhuCap;
}

void CONGCHUC::XUAT()
{
    cout << "Ho Ten: " << HoTen << endl;
    cout << "Gioi Tinh: " << GioiTinh << endl;
    cout << "Ngay Sinh: " << Ngay << "/" << Thang << "/" << Nam << endl;
    cout << "Dia Chi: " << DiaChi << endl;
    cout << "Nganh Nghe: " << NganhNghe << endl;
    cout << "Nam Vao Co Quan: " << NamVaoCQ << endl;
    cout << "Trinh Do: " << TrinhDo << endl;
    cout << "He So Luong: " << HSLuong << endl;
    cout << "Phu Cap: " << PhuCap << endl;
}

float CONGCHUC::THUNHAP()
{
    return HSLuong * (float)830 + PhuCap;
}


void SapXepGiamDanTheoTen(CONGCHUC *array1, int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(stricmp(array1[j].HoTen, array1[j + 1].HoTen) == -1){
                CONGCHUC temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    CONGCHUC *array1;
    do
    {
        cout << "Nhap N: ";
        cin >> n;

        if(n < 0){
            cout << "So luong khong duoc be hon 1" << endl;
        }

        if(n > 50){
            cout << "So luong khong duoc vuot qua 50" << endl;
        }
    } while (n < 1 or n > 50);
    
    array1 = new CONGCHUC[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap Thong Tin Cong Chuc thu " << i + 1 << ": " << endl;
        array1[i].NHAP();
    }

    //Danh Sach Sau Khi Nhap
    for(int i = 0 ; i < n ; i++)
    {
        cout << "Thong Tin Cong Chuc thu " << i + 1 << ": " << endl;
        array1[i].XUAT();
    }

    //Tim Cong Chuc co thu nhap thap nhat
    int pos = 0;
    float ThuNhapThapNhat = array1[0].THUNHAP();

    for(int i = 1 ; i < n ; i++)
    {
        if(array1[i].THUNHAP() < ThuNhapThapNhat)
        {
            ThuNhapThapNhat = array1[i].THUNHAP();
            pos = i;
        }
    }

    cout << "Thong Tin Cong Chuc Co Thu Nhap Thap Nhat: " << endl;
    array1[pos].XUAT();
    cout << "Thu Nhap: " << array1[pos].THUNHAP() << endl;
    //Danh Sach Sau Khi Sap Xep
    SapXepGiamDanTheoTen(array1, n);

    cout << "Danh Sach Sau Khi Sap Xep: " << endl;
    
    for(int i = 0 ; i < n ; i++)
    {
        cout << "Thong Tin Cong Chuc thu " << i + 1 << ": " << endl;
        array1[i].XUAT();
    }
    return 0;
}