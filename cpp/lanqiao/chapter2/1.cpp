#include <iostream>
#include <string>
using namespace std;

bool is_leap_year(int year)
{
    return (year % 400 == 0)||(year % 4 == 0 && year %100 != 0);
}
int main(int argc, char const *argv[])
{
    int year = 1970;
    std::cin >> year;
    
    std::cout << (is_leap_year(year) ? "yes" : "no");
    return 0;
}