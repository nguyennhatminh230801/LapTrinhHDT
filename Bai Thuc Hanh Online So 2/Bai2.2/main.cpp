#include <bits/stdc++.h>
using namespace std;

class STUDENT;
class FACULTY;

class SCHOOL
{
    char Name[30];
    char Date[15];
public:
    friend class FACULTY;
    friend class STUDENT;
};

class FACULTY
{
    char Name[30];
    char Date[15];
    SCHOOL x;

public:
    void input();
    void output();
    friend class STUDENT;
};

void FACULTY::input()
{
    cout << "Nhap ten khoa: ";
    fflush(stdin);
    gets(Name);

    cout << "Nhap ngay thanh lap khoa: ";
    fflush(stdin);
    gets(Date);

    cout << "Nhap ten truong: ";
    fflush(stdin);
    gets(x.Name);

    cout << "Nhap ngay thanh lap truong: ";
    fflush(stdin);
    gets(x.Date);
}

void FACULTY::output()
{
    cout << "Ten Khoa: " << this->Name << endl;
    cout << "Ngay Thanh Lap Khoa: " << this->Date << endl;
    cout << "Ten Truong: " << x.Name << endl;
    cout << "Ngay thanh lap truong: " << x.Date << endl;
}

class PERSON
{
protected:
    char Name[30];
    char Birth[15];
    char Address[50];
public:
    void input();
    void output();
    PERSON();
};

PERSON::PERSON()
{
    strcpy(Name, "");
    strcpy(Birth, "");
    strcpy(Address, "");
}

void PERSON::input()
{
    cout << "Nhap ho ten: ";
    fflush(stdin);
    gets(Name);

    cout << "Nhap ngay sinh: ";
    fflush(stdin);
    gets(Birth);

    cout << "Nhap dia chi: ";
    fflush(stdin);
    gets(Address);
}

void PERSON::output()
{
    cout << "Ho va Ten: " << Name << endl;
    cout << "Ngay sinh: " << Birth << endl;
    cout << "Dia chi: " << Address << endl;
}

class STUDENT : public PERSON
{
    FACULTY y;
    char Class[20];
    float Score;
public:
    void input();
    void output();
    STUDENT();

};

STUDENT::STUDENT() : PERSON()
{
    strcpy(Class, "");
    Score = 0;
    strcpy(y.Date, "");
    strcpy(y.Name, "");
    strcpy(y.x.Date, "");
    strcpy(y.x.Name, "");
}

void STUDENT::input()
{
    PERSON::input();
    y.input();

    cout << "Nhap ten lop: ";
    fflush(stdin);
    gets(Class);

    cout << "Nhap diem: ";
    cin >> Score;
}

void STUDENT::output()
{
    PERSON::output();
    y.output();

    cout << "Ten lop: " << Class << endl;
    cout << "Diem: " << Score << endl;

    //Bonus 1 : Sua lai thong tin ve Ten Truong

    strcpy(this->y.x.Name, "DHCNHN");

    cout << "Ten truong sau khi sua thanh DHCNHN: " << endl;

    PERSON::output();
    y.output();

    cout << "Ten lop: " << Class << endl;
    cout << "Diem: " << Score << endl;
}

int main()
{
    STUDENT sv1;
    sv1.input();
    sv1.output();

    return 0;
}
