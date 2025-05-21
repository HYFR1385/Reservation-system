#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <vector>
using namespace std;
class passengers
{
private:
    int passenger_id;
    string name;
    string family;
    int passport;
    int nationalid;
    string nationality;
    float wallet;

public:
    void show_list();
    void edit_passenger();
    void search_passenger();
};
class flights
{
private:
    int flight_id;
    int flynum;
    string origin;
    string date;
    string time;
    int count;
    float price;

public:
    void show_flights();
    void search_flights();
};

class reservationsm : public passengers, flights
{
    int reservation_id;

public:
    void show_buying();
    void search_reserve();
    void delete_reserve();
    void report_passenger();
    void report_flights();
    void report_reserve();
};
int main()
{
    int securityCode = 12345;
    int input;
    int a;
    string khat = "_";
    system("cls");
    cout << "\nhello to our airline reservation system\n"
         << "please Enter the number of your choice:\n";
menu:
    system("color 0E");
    for (int i = 0; i <= 70; i++)
        cout << khat;

    cout << "\n\n(1) Flights\n(2) Passengers\n(3)Reservation \n";
    for (int i = 0; i <= 70; i++)
        cout << khat;
    cout << "\n";
    cin >> input;
    system("cls");
    while (cin.fail() || input < 1 || input > 3)
    {
        cout << "Wrong answer!!\n please enter correct number(1,2,3)\n";
        for (int i = 0; i <= 70; i++)
            cout << khat;

        cout << "\n\n(1) Flights\n(2) Passengers\n(3)Reservation \n";
        for (int i = 0; i <= 70; i++)
            cout << khat;
        cout << "\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> input;
        system("cls");
    }
    switch (input)
    {
    case 1:
        system("cls");
        system("color 09");
        Sleep(1000);
        for (int i = 0; i <= 70; i++)
            cout << khat;
        cout << "\n";
        Sleep(500);
        cout << "\n(1)Flights list";
        Sleep(500);
        cout << "\n(2) Add new flight\n";
        Sleep(500);
        cout << "(3) Back to main menu\n";
        Sleep(500);
        for (int i = 0; i <= 70; i++)
            cout << khat;
        cout << "\n";
        cin >> a;
        system("cls");
        while (cin.fail() || a < 1 || a > 3)
        {
            cout << "Wrong answer!!\n please enter correct number(1,2,3)\n";
            for (int i = 0; i <= 70; i++)
                cout << khat;
            cout << "\n";
            Sleep(1000);
            cout << "\n(1) Flights list";
            Sleep(1000);
            cout << "\n(2) Add new flight\n";
            for (int i = 0; i <= 70; i++)
                cout << khat;
            cout << "\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> a;
            system("cls");
        }
        {
            if (a == 1)
            {
                // باید لیست مسافر ها رو نشو بده
            }
            else if (a == 2)
            {
                // باید لیست بسازی
            }
            else if (a == 3)
            {
                goto menu;
            }
        }
        break;
    case 2:
        system("cls");
        Sleep(500);
        system("color 0C");
        for (int i = 0; i <= 70; i++)
            cout << khat;
        cout << "\n(1) Add new passenger\n";
        Sleep(500);
        cout << "(2) Passengers list\n";
        Sleep(500);
        cout << "(3) Edit passenger info\n";
        Sleep(500);
        cout << "(4) Go to main menu\n";
        Sleep(500);
        for (int i = 0; i <= 70; i++)
            cout << khat;
        cout << "\n";
        cin >> a;
        system("cls");
        while (cin.fail() || a < 1 || a > 4)
        {
            cout << "Wrong answer!!\n please enter correct number(1,2,3,4)\n";
            for (int i = 0; i <= 70; i++)
                cout << khat;
            cout << "\n(1) Add new passenger\n";
            cout << "(2) Passengers list\n";
            cout << "(3) Edit passenger info\n";
            cout << "(4) Go to main menu\n";
            for (int i = 0; i <= 70; i++)
                cout << khat;
            cout << "\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> a;
            system("cls");
        }
        if (a == 1)
        {
            // باید مسافر جدید اسجاد کند
        }
        else if (a == 2)
        {
            // باید لیست مسافران را نمایش دهد
        }
        else if (a == 3)
        {
            // باید دستور تغییر مشخصات مسافر ایجاد شود
        }
        else if (a == 4)
            goto menu;
        break;
        case 3:
    }
}
