#include <iostream>
using namespace std;

bool IsLeapYear(int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

int GetMonthLen(int month, int year)
{
    return
        (month <= 7 && month % 2 == 1) ||
        (month >= 8 && month % 2 == 0) ? 31 :
        month != 2                     ? 30 :
        IsLeapYear(year)               ? 29 :
                                         28;
}

int main()
{
    int day = 0; // == Monday; Tuesday 1... Sunday 6
    int sundayCount = 0;
    
    for (int year = 1900; year != 2001; ++year)
    {
        for (int month = 1; month != 13; ++month)
        {
            if (day == 6 && year != 1900)
                ++sundayCount;
            
            day = (day + GetMonthLen(month, year)) % 7;
        }
    }
    
    cout << sundayCount << endl;
    
    return 0;
}
