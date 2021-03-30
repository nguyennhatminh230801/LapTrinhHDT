#include <bits/stdc++.h>
using namespace std;

class LOPHOC;

class NGUOI
{
    protected:
        char HoTen[30];
        char NgaySinh[15];
        char QueQuan[30];
    
    public:
        void NHAP();
        void XUAT();
        
};

void NGUOI::NHAP()
{
    cout << "Nhap ho ten: ";
    fflush(stdin);
    gets(HoTen);

    cout << "Nhap ngay sinh: ";
    fflush(stdin);
    gets(NgaySinh);

    cout << "Nhap que quan: ";
    fflush(stdin);
    gets(QueQuan);
}

void NGUOI::XUAT()
{
    cout << setw(30) << HoTen << setw(15) << NgaySinh << setw(30) << QueQuan;
}

class SINHVIEN : public NGUOI
{
    char MaSV[15];
    char Nganh[30];
    int KhoaHoc;

    public:
        void NHAP();
        void XUAT();
        friend void FindK11(LOPHOC obj1);
        friend void SapXep(LOPHOC obj1);
};

void SINHVIEN::NHAP()
{
    NGUOI::NHAP();

    cout << "Nhap Ma Sinh Vien: ";
    fflush(stdin);
    gets(MaSV);

    cout << "Nhap Nganh: ";
    fflush(stdin);
    gets(Nganh);

    cout << "Nhap Khoa Hoc: ";
    cin >> KhoaHoc;
}

void SINHVIEN::XUAT()
{
    NGUOI::XUAT();
    cout << setw(15) << MaSV << setw(30) << Nganh << setw(10) << KhoaHoc << endl;
}

class LOPHOC
{
    char MaLH[10];
    char TenLH[30];
    char NgayMo[15];
    SINHVIEN *x;
    int n;
    char GiaoVien[30];

    public:
        void NHAP();
        void XUAT();
        friend void FindK11(LOPHOC obj1);
        friend void SapXep(LOPHOC obj1);
};

void LOPHOC::NHAP()
{
    cout << "Nhap Ma Lop Hoc: ";
    fflush(stdin);
    gets(MaLH);

    cout << "Nhap Ten Lop Hoc: ";
    fflush(stdin);
    gets(TenLH);

    cout << "Nhap Ngay Mo: ";
    fflush(stdin);
    gets(NgayMo);

    cout << "Nhap giao vien: ";
    fflush(stdin);
    gets(GiaoVien);

    cout << "Nhap So Luong Sinh Vien: ";
    cin >> n;

    x = new SINHVIEN[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap sinh vien thu " << i + 1 << ": " << endl;
        x[i].NHAP();
    }
}

void LOPHOC::XUAT()
{
    cout << "MA LOP HOC: " << MaLH << endl;
    cout << "TEN LOP HOC: " << TenLH << endl;
    cout << "NGAY MO: " << NgayMo << endl;
    cout << "GIAO VIEN: " << GiaoVien << endl;

    cout << setw(30) << "HO TEN" << setw(15) << "NGAY SINH" << setw(30) << "QUE QUAN" << setw(15) << "MA SV" << setw(30) << "NGANH" << setw(10) << "KHOA HOC" << endl;
    
    for(int i = 0 ; i < n ; i++)
    {
        x[i].XUAT();
    }
}

void FindK11(LOPHOC obj1)
{
    int count1 = 0;

    for(int i = 0 ; i < obj1.n ; i++)
    {
        if(obj1.x[i].KhoaHoc == 11)
        {
            count1++;        
        }
    }

    if(count1 > 0)
    {
        cout << "Co " << count1 << " sinh vien khoa 11 trong lop" << endl;
    }
    else
    {
        cout << "Khong co sinh vien nao khoa 11 trong lop" << endl;
    }
}

void SapXep(LOPHOC obj1)
{
    for(int i = 0 ; i < obj1.n - 1; i++)
    {
        for(int j = 0 ; j < obj1.n - i - 1; j++)
        {
            if(obj1.x[j].KhoaHoc > obj1.x[j + 1].KhoaHoc)
            {
                int change = obj1.x[j].KhoaHoc;
                obj1.x[j].KhoaHoc = obj1.x[j + 1].KhoaHoc;
                obj1.x[j + 1].KhoaHoc = change;
            }
        }
    }
}

int main()
{
    LOPHOC LH01;

    LH01.NHAP();
    LH01.XUAT();

    FindK11(LH01);
    SapXep(LH01);

    cout << "Sau Khi Sap Xep: " << endl;
    LH01.XUAT();
    return 0;
}