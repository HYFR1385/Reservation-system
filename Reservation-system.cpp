#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <vector>
using namespace std;

class passengers
{
private:
    int passengerid;
    string name;
    string family;
    int port;
    int nationalid;
    string nationality;
    float wallet;

public:
    void signing (int &passengerid, string &name, string &family, int &port, int &nationalid, string &nationality, float &wallet)
    {
        this->passengerid = rand();
        this->name = name;
        this->family = family;
        this->port = port;
        this->nationalid = nationalid;
        this->nationality = nationality;
        this->wallet = wallet;
    }
    int getPassengerID() const { return passengerid; }
    string getName() const { return name; }
    string getFamily() const { return family; }
    int getPort() const { return port; }
    int getNationalID() const { return nationalid; }
    string getNationality() const { return nationality; }
    float getWallet() const { return wallet; }

    void addperson()
    {

        fstream p;
        p.open("passengers.txt", ios::app);
        // if (p.tellp() == 0)
        // {
        //     for (int i = 0; i < 145; i++)
        //         p << "_";
        //     p << "\npassengerid" << setw(15) << "name" << setw(15) << "family" << setw(15) << "passportid" << setw(15) << setw(15) << "nationalid" << setw(15) << "nationality" << setw(15) << "wallet\n";
        //     for (int i = 0; i < 145; i++)
        //         p << "_";
        // }
        p << "\n"
          << passengerid << setw(15) << name << setw(15) << family << setw(15)
          << port << setw(15) << nationalid << setw(15) << nationality << setw(15) << wallet << "\n";
        for (int i = 0; i < 145; i++)
            p << "_";
        p.close();
    }
    void show_list()
    {
         system("start passengers.txt");
        fstream p;
        p.open("passengers.txt", ios::in);
        while (p >> passengerid >> name >> family >> port >> nationalid >> nationality >> wallet)
        {
            cout << "passenger id:" << passengerid << setw(20) << "name:" << name << setw(20)
                 << "family:" << family << setw(20) << "nationality:" << nationality << setw(20)
                 << "national id:" << nationalid << setw(20) << "passport id"
                 << port << setw(20) << "wallet:" << wallet<<"\n\n";
        }
        p.close();
    }    

    void edit_passenger() {
    fstream file("passengers.txt", ios::in);
    if (!file) {
        cout << "Could not open passengers.txt\n";
        return;
    }

    vector<passengers> passengerList;
    passengers temp;
    bool found = false;
    int searchID;

    cout << "Enter Passenger ID to edit: ";
    cin >> searchID;

    while (file >> temp.passengerid >> temp.name >> temp.family >> temp.port >> temp.nationalid >> temp.nationality >> temp.wallet) {
        passengerList.push_back(temp);
    }
    file.close();

    
    for (auto& p : passengerList) {
        int a;
        if (p.passengerid == searchID) {
            found = true;
            cout << "\nPassenger found. Enter new values that you want:\n(1) Name\n(2) Family\n(3) passport number\n(4) national id\n(5) Nationality\n(6) Wallet amount\n";
            cin>>a;
              while (cin.fail()|| a<1 || a>6 )
        {
            cout << "Wrong answer!!\n please enter correct number\n";
            cout << "\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> a;
            system("cls");
        }
        switch (a)
        {
            case 1:
            cout << "New name (was " << p.name << "): ";
            cin >> p.name;
            break;
            case 2:
            cout << "New family (was " << p.family << "): ";
            cin >> p.family;
            break;
            case 3:
            cout << "New passport number (was " << p.port << "): ";
            cin >> p.port;
            break;
            case 4:
            cout << "New national ID (was " << p.nationalid << "): ";
            cin >> p.nationalid;
            break;
            case 5:
            cout << "New nationality (was " << p.nationality << "): ";
            cin >> p.nationality;
            break;
            case 6:
            cout << "New wallet amount (was " << p.wallet << "): ";
            cin >> p.wallet;
            break;

        }
    }
    }

    if (!found) {
        cout << "Passenger with ID " << searchID << " not found.\n";
        return;
    }

    
    ofstream outFile("passengers.txt");
    for (const auto& p : passengerList) {
        outFile << p.passengerid << setw(15) << p.name << setw(15) << p.family << setw(15)
                << p.port << setw(15) << p.nationalid << setw(15) << p.nationality << setw(15) << p.wallet << "\n";
    }
    outFile.close();

    cout << "Passenger information updated successfully.\n";
}

   void search_passenger()
{
    fstream file("passengers.txt", ios::in);
    if (!file) {
        cout << "Could not open passengers.txt\n";
        return;
    }

    cout << "Search passenger by:\n";
    cout << "(1) Passenger ID\n";
    cout << "(2) National ID\n";
    cout << "(3) Passport Number\n";
    cout << "(4) Name (or part of it)\n";
    int choice;
    cin >> choice;

    int searchInt;
    string searchStr;
    bool found = false;

    
    switch (choice) {
        case 1:
            cout << "Enter passenger ID: ";
            cin >> searchInt;
            break;
        case 2:
            cout << "Enter national ID: ";
            cin >> searchInt;
            break;
        case 3:
            cout << "Enter passport number: ";
            cin >> searchInt;
            break;
        case 4:
            cout << "Enter name or part of name: ";
            cin >> searchStr;
            break;
        default:
            cout << "Invalid option!\n";
            return;
    }

    
    while (file >> passengerid >> name >> family >> port >> nationalid >> nationality >> wallet) {
        switch (choice) {
            case 1:
                if (passengerid == searchInt) found = true;
                break;
            case 2:
                if (nationalid == searchInt) found = true;
                break;
            case 3:
                if (port == searchInt) found = true;
                break;
            case 4:
                if (name.find(searchStr) != string::npos) found = true;
                break;
        }

        if (found) {
            cout << "\nPassenger found:\n";
            cout << "ID: " << passengerid << "\tName: " << name << "\tFamily: " << family
                 << "\tPassport: " << port << "\tNational ID: " << nationalid
                 << "\tNationality: " << nationality << "\tWallet: " << wallet << endl;
            break;  
        }
    }

    if (!found) {
        cout << "\nNo matching passenger found.\n";
    }

    file.close();
}
    
};
class flights
{
private:
    int flight_id = rand();
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

class reservations : public passengers, flights
{
    int reservation_id = rand();

public:
    void show_buying();
    void search_reserve();
    void delete_reserve();
    void report_enger();
    void report_flights();
    void report_reserve();
};
void khat()
{
    Sleep(250);
    string k = "_";
    for (int i = 0; i < 70; i++)
        cout << k;
}
int menu(int &a, int &input)
{

    system("color 0E");

    khat();
    cout << "\n\n(1) Flights";
    Sleep(250);
    cout << "\n(2) Passengers";
    Sleep(250);
    cout << "\n(3) Reservation \n";
    Sleep(250);
    cout << "(4) Exit\n";
    khat();
    cout << "\n";
    cin >> input;
    system("cls");
    while (cin.fail() || input < 1 || input > 4)
    {
        cout << "Wrong answer!!\n please enter correct number(1,2,3,4)\n";
        khat();
        cout << "\n\n(1) Flights\n(2) Passengers\n(3) Reservation \n(4) Exit";
        khat();
        cout << "\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> input;
        system("cls");
    }

    return input;
}
void fly(int &a, int &input, vector<flights> &flight)
{
    system("cls");
    system("color 09");
    khat();
    cout << "\n\n(1) Flights list";
    Sleep(250);
    cout << "\n(2) Add new flight\n";
    Sleep(250);
    cout << "(3) Search flight\n";
    Sleep(250);
    cout << "(4) Back to main menu\n";
    khat();
    cout << "\n";
    cin >> a;
    system("cls");
    while (cin.fail() || a < 1 || a > 4)
    {
        cout << "Wrong answer!!\nplease enter correct number(1,2,3)\n";
        khat();
        Sleep(250);
        cout << "\n\n(1) Flights list";
        Sleep(250);
        cout << "\n(2) Add new flight\n";
        Sleep(250);
        cout << "(3) Search flight\n";
        Sleep(250);
        cout << "(4) Back to main menu\n";
        khat();
        cout << "\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> a;
        system("cls");
    }

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
        // غملیات جست و جوی پرواز
    }
    else if (a == 4)
    {
        menu(a, input);
    }
}
void pass(int &a, int &input)
{
    int passengerid;
    string name;
    string family;
    int port;
    int nationalid;
    string nationality;
    float wallet;
    passengers p;
    system("cls");
    system("color 0C");
    khat();
    cout << "\n\n(1) Add new passenger\n";
    Sleep(250);
    cout << "(2) Passengers list\n";
    Sleep(250);
    cout << "(3) Edit passenger info\n";
    Sleep(250);
    cout << "(4) Search passenger\n";
    Sleep(250);
    cout << "(5) Go to main menu\n";
    khat();
    cout << "\n";
    cin >> a;
    system("cls");
    while (cin.fail() || a < 1 || a > 5)
    {
        cout << "Wrong answer!!\n please enter correct number(1,2,3,4,5)\n";
        khat();
        cout << "\n\n(1) Add new passenger\n";
        cout << "(2) Passengers list\n";
        cout << "(3) Edit passenger info\n";
        cout << "(4) Search passenger\n";
        cout << "(5) Go to main menu\n";
        khat();
        cout << "\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> a;
    }
    if (a == 1)
    { // اضافه کردن مسافر
        cout << "Enter name:\n";
        khat();
        cout << "\n";
        cin >> name;
        cout << "\n";
        khat();
        cout << "\nEnter family:\n";
        khat();
        cout << "\n";
        cin >> family;
        cout << "\n";
        khat();
        cout << "\nEnter passport number:\n ";
        khat();
        cout << "\n";
        cin >> port;
        while (cin.fail())
        {
            cout << "Wrong answer!!\n please enter correct number\n";
            khat();
            cout << "\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> port;
            system("cls");
        }
        cout << "\n";
        khat();
        cout << "\nEter national id:\n";
        khat();
        cout << "\n";
        cin >> nationalid;
        while (cin.fail())
        {
            cout << "Wrong answer!!\n please enter correct number\n";
            khat();
            cout << "\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> nationalid;
            system("cls");
        }
        cout << "\n";
        khat();
        cout << "\nenter nationality:\n";
        khat();
        cout << "\n";
        cin >> nationality;
        cout << "\n";
        khat();
        cout << "\nenter your account balance:\n";
        khat();
        cout << "\n";
        cin >> wallet;
        while (cin.fail())
        {
            cout << "Wrong answer!!\n please enter correct number\n";
            khat();
            cout << "\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> wallet;
            system("cls");
        }
        
        p.signing (passengerid, name, family, port, nationalid, nationality, wallet);
        p.addperson();
        system("cls");
        menu(a, input);
    }

    else if (a == 2)
    {
       int a;
       p.show_list();
       
      
    cout<<"\nPress key(2) to back main menu\n";
        cin>>a;
        if (a==2)
        menu(a,input);
         while (a!=2)
        {
            cout << "Wrong answer!!\n please enter correct number(2)\n";
            khat();
            cout << "\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> a;
            system("cls");
        }

        // باید لیست مسافران را نمایش دهد
    }

   else if (a == 3)
{
    p.edit_passenger();
    cout << "\nPress 2 to return to main menu:\n";
    int back;
    cin >> back;
    while (back != 2) {
        cout << "Wrong input, press 2 to go back.\n";
        cin >> back;
    }
    menu(a, input);
}

    else if (a == 4)
    {
        

    p.search_passenger();
    cout << "\nPress 2 to return to main menu:\n";
    int back;
    cin >> back;
    while (back != 2) {
        cout << "Wrong input, press 2 to go back.\n";
        cin >> back;
    }
    menu(a, input);

        
    }
    else if (a == 5)
    {
        menu(a, input);
    }
}
int main()
{
    int securityCode = 12345;
    int input;
    int a;
    vector<flights> flight;
    vector<reservations> reserve;
    srand(time(NULL));
    system("cls");
    cout << "\nhello to our airline reservation system\n"
         << "please Enter the number of your choice:\n";
    menu(a, input);
    while (input != 4)
    {
        switch (input)
        {
        case 1:
            fly(a, input, flight);
            break;
        case 2:
            pass(a, input);
            break;
        case 3:
            khat();
            Sleep(250);
            cout << "\n\n(1) Take reserve";
            Sleep(250);
            cout << "\n(2) Search reserve";
            Sleep(250);
            cout << "\n(3) Delete reserve\n";
            break;
        }
    }
}