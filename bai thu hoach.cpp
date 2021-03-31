#include <bits/stdc++.h>
using namespace std;

class HANG
{
    char MaHang[10];
    char TenHang[30];
    float DonGia;
    int SoLuong;
    int Nam;

    public:
        HANG();
        HANG(char *MaHang, char *TenHang, float DonGia, int SoLuong, int Nam);
        friend istream& operator>>(istream& input, HANG &obj1);
        friend ostream& operator<<(ostream& output, HANG obj1);
        friend bool HaveIPHONE12(HANG obj1);
        friend void SapXep(HANG *array1, int n);
        friend void XoaH005(HANG *&array1, int &n);
        friend void XoaDonGiaNhoHon20(HANG *&array1, int &n);
        friend void Chen(HANG *&array1, int &n, int pos, HANG obj1);
};

HANG::HANG()
{
    strcpy(this->MaHang, "");
    strcpy(this->TenHang, "");
    DonGia = 0;
    SoLuong = 0;
    Nam = 0;
}

HANG::HANG(char *MaHang, char *TenHang, float DonGia, int SoLuong, int Nam)
{
    strcpy(this->MaHang, MaHang);
    strcpy(this->TenHang, TenHang);
    this->DonGia = DonGia;
    this->SoLuong = SoLuong;
    this->Nam = Nam;
}

istream& operator>>(istream& input, HANG &obj1)
{
    cout << "Nhap Ma Hang: ";
    fflush(stdin);
    input.getline(obj1.MaHang, 10);

    cout << "Nhap Ten Hang: ";
    fflush(stdin);
    input.getline(obj1.TenHang, 30);

    cout << "Nhap Don Gia: ";
    input >> obj1.DonGia;

    cout << "Nhap So Luong: ";
    input >> obj1.SoLuong;

    cout << "Nhap Nam: ";
    input >> obj1.Nam;

    return input;
}

ostream& operator<<(ostream& output, HANG obj1)
{
    output << obj1.MaHang << endl;
    output << obj1.TenHang << endl;
    output << obj1.DonGia << endl;
    output << obj1.SoLuong << endl;
    output << obj1.Nam << endl;

    return output;
}

bool HaveIPHONE12(HANG obj1)
{
    return stricmp(obj1.TenHang, "IPHONE 12") == 0;
}

void SapXep(HANG *array1, int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(array1[j].SoLuong * array1[j].DonGia > array1[j + 1].SoLuong * array1[j + 1].DonGia)
            {
                HANG temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;
            }
        }
    }
}

void XoaH005(HANG *&array1, int &n)
{
    int pos = -1;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(stricmp(array1[i].MaHang, "H005") == 0)
        {
            pos = i;
        }
    }

    if(pos != -1)
    {
        for(int i = pos ; i < n - 1 ; i++)
        {
            array1[i] = array1[i + 1];
        }
        n--;

        array1 = (HANG*) realloc(array1, n * sizeof(HANG));
        cout << "Xoa H005 thanh cong" << endl;
    }
    else
    {
        cout << "Khong Ton Tai H005 trong danh sach" << endl;
    }
}

void XoaDonGiaNhoHon20(HANG *&array1, int &n)
{
    for(int i = 0 ; i < n ; i++)
    {
        while (array1[i].DonGia < 20 && i < n)
        {
            for(int j = i ; j < n - 1; j++)
            {
                array1[j] = array1[j + 1];
            }

            n--;
        }
    }
    
    array1 = (HANG*) realloc(array1, n * sizeof(HANG));
}

void Chen(HANG *&array1, int &n, int pos, HANG obj1)
{
    if(pos < 0 || pos > n)
    {
        cout << "Vi tri chen ngoai khoang nen khong the chen" << endl;
    }
    else
    {
        array1 = (HANG*) realloc(array1, (n + 1) * sizeof(HANG));

        for(int i = n - 1 ; i >= pos ; i--)
        {
            array1[i + 1] = array1[i];
        }

        array1[pos] = obj1;
        n++;
        cout << "Chen Thanh Cong" << endl;
    }
}

int main()
{
    HANG *array1;
    int n;

    ofstream outfile;
    outfile.open("HANGNHAP.DAT", ios::out);
    
    cout << "Nhap So Luong: ";
    cin >> n;

    outfile << n << endl;
    
    array1 = new HANG[n];

    bool IPHONE12 = false;

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Nhap Mat Hang Thu " << i + 1 << ": " << endl; 
        cin >> array1[i];

        if(HaveIPHONE12(array1[i]))
        {
            IPHONE12 = true;
        }

        outfile << array1[i];
    }

    outfile.close();

    cout << ((IPHONE12) ? "Co" : "Khong") << " " << "ton tai Iphone12 trong danh sach" << endl;    

    outfile.open("HANGSORT.TXT", ios::out);

    SapXep(array1, n);

    outfile << "Danh Sach Sau khi Sap Xep: " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        outfile << array1[i];
    }

    outfile.close();
    
    outfile.open("HANGREMOVE.TXT", ios::app);

    XoaH005(array1, n);

    outfile << "Danh Sach Sau khi xoa H005: " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        outfile << array1[i];
    }
    
    outfile << endl;

    XoaDonGiaNhoHon20(array1, n);

    outfile << "Danh Sach Sau khi xoa don gia nho hon 20: " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        outfile << array1[i];
    }
    
    outfile << endl;

    outfile.close();
    
    //Câu làm thêm =)) Chèn 1 đối tượng vào mảng đối tượng
    outfile.open("HANGINSERT.txt", ios::out);

    int pos;
    cout << "Nhap vi tri chen: ";
    cin >> pos;

    HANG obj1;
    cin >> obj1;

    Chen(array1, n, pos, obj1);

    outfile << "Danh Sach Can Tim " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        outfile << array1[i];
    }

    outfile.close();
    return 0;
}