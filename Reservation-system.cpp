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
}